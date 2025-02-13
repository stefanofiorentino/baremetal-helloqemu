// kas shell bare-metal.yml
// devtool modify baremetal-helloworld
// bitbake -c build baremetal-helloworld
// runqemu nographic slirp

#define VIRT_UART0 0x10000000

template <typename UART>
constexpr void print(UART&& uart, const char * str) {
    while(*str != '\0')
    {
        *uart = (unsigned int) *str;
        str++;
    }
}

struct mock_uart {
    constexpr mock_uart() noexcept : buffer(nullptr), N(0), index(0) {}
    constexpr mock_uart(char * buffer, int N) noexcept : buffer(buffer), N(N), index(0)  {}
    constexpr mock_uart& operator*() noexcept {
        return *this;
    }
    constexpr void operator=(unsigned int val) noexcept {
        if (buffer && index < N) {
            buffer[index++] = (char) val;
        }
    }
private:
    char * buffer;
    unsigned int N;
    unsigned int index;
};

consteval bool test_dereferece_uart() {
    auto uart = mock_uart();
    (void)*uart;
    return true;
}
static_assert(test_dereferece_uart(), "test_dereferece_uart() failed");

consteval bool test_assignment_uart() {
    auto uart = mock_uart();
    *uart = (unsigned int) 'H';
    return true;
}
static_assert(test_assignment_uart(), "test_assignment_uart() failed");

consteval bool test_print() {
    auto uart = mock_uart();
    print(uart, "Hello, world!");
    return true;
}
static_assert(test_print(), "test_print() failed");

constexpr bool strcmq(const char * a, const char * b) {
    while(*a != '\0' && *b != '\0') {
        if (*a != *b) {
            return false;
        }
        a++;
        b++;
    }
    return *a == *b;
}

consteval bool test_print_content() {
    // arrange
    const unsigned int STRING_SIZE = 15;
    char actual[STRING_SIZE] = {0};
    const char expected[STRING_SIZE] = "Hello, world!\n";

    // act
    auto uart = mock_uart(actual, STRING_SIZE);
    print(uart, "Hello, world!\n");

    // assert
    return strcmq(expected, actual);
}
static_assert(test_print_content(), "test_print_content() failed");

extern "C" void c_entry() {
    volatile unsigned int * const uart0 = (volatile unsigned int*) VIRT_UART0;
    print(uart0, "Hello, world!\n");
    while(1);
}
