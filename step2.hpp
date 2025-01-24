#define UART0_ADDR 0x10000000

volatile unsigned int * const uart0 = (volatile unsigned int*) UART0_ADDR;

constexpr void print(volatile unsigned int* const uart, char const * const str) {
    while(*str != '\0')
    {
        *uart = (unsigned int) *str;
    }
}

struct testing_struct {
    constexpr testing_struct() noexcept {}
    constexpr testing_struct& operator*() noexcept {
        return *this;
    }
    constexpr void operator=(unsigned int val) noexcept {
    }
};
consteval bool test_dereferece_uart() {
    auto uart = testing_struct();
    (void)*uart;
    return true;
}
static_assert(test_dereferece_uart(), "test_dereferece_uart() failed");

consteval bool test_assignment_uart() {
    auto uart = testing_struct();
    *uart = (unsigned int) 'H';
    return true;
}
static_assert(test_assignment_uart(), "test_assignment_uart() failed");
