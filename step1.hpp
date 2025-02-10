// kas shell bare-metal.yml
// devtool modify baremetal-helloworld
// bitbake -c build baremetal-helloworld
// runqemu nographic slirp

/* VIRT_UART0 base address is 0x10000000 according to QEMU source code*/
#define VIRT_UART0 0x10000000

constexpr void print(volatile unsigned int* const uart, const char * str) {
    while(*str != '\0')
    {
        *uart = (unsigned int) *str;
        str++;
    }
}

extern "C" void c_entry() {
    volatile unsigned int * const uart0 = (volatile unsigned int*) VIRT_UART0;
    print(uart0, "Hello, world!\n");
    while(1);
}
