/* VIRT_UART0 base address is 0x10000000 according to QEMU source code*/
#define VIRT_UART0 0x10000000

volatile unsigned int * const uart0 = (volatile unsigned int*) UART0_ADDR;

constexpr void print(volatile unsigned int* const uart, char const * const str) {
    while(*str != '\0')
    {
        *uart = (unsigned int) *str;
    }
}
