// kas shell bare-metal.yml
// devtool modify baremetal-helloworld
// bitbake -c build baremetal-helloworld
// runqemu nographic slirp

/* VIRT_UART0 base address is 0x10000000 according to QEMU source code*/
#define VIRT_UART0 0x10000000

volatile unsigned int * const UART0DR = (unsigned int *)VIRT_UART0;

/* Until we reach to the end of the string, put each char on UART0 */
void print_uart0(const char *str) {
  while(*str != '\0') {
    *UART0DR = (unsigned int)(*str);
    str++;
  }
}

extern "C" void c_entry() {
  print_uart0("Hello, world!\n");
  while(1);
}
