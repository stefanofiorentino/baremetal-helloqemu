// kas shell bare-metal.yml
// devtool modify baremetal-helloworld
// bitbake -c build baremetal-helloworld
// runqemu nographic slirp

#define VIRT_UART0 0x10000000

constexpr void print(volatile unsigned int* const uart, const char * str) {
    while(*str != '\0')
    {
        *uart = (unsigned int) *str;
        str++;
    }
}

struct mock_uart {
    constexpr mock_uart() noexcept {}
    constexpr mock_uart& operator*() noexcept {
        return *this;
    }
    constexpr void operator=(unsigned int val) noexcept {
    }
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

extern "C" void c_entry() {
    volatile unsigned int * const uart0 = (volatile unsigned int*) VIRT_UART0;
    print(uart0, "Hello, world!\n");
    while(1);
}
