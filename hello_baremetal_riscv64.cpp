#define VIRT_UART0 0x10000000

volatile unsigned int * const UART0DR = (unsigned int *)VIRT_UART0;

void print_uart0(const char *str) {
  while(*str != '\0') {
    *UART0DR = (unsigned int)(*str);
    str++;
  }
}

const unsigned int ARRAY_SIZE = 64;

namespace {
template <typename T, unsigned int _Size>
struct array
{
    consteval unsigned int capacity() const { return _Size; }
};
}

// ChatGPT prompt: can you help me implementing a plain C function, without using any function from the standard library that is able to transform an integer in a string?
void intToStr(unsigned int num, char* str) {
    // Temporary buffer to store the reversed digits
    char buffer[20]; // Enough space for a 64-bit integer and null-terminator
    unsigned int i = 0;

    // Convert the number to its digits in reverse order
    do {
        buffer[i++] = (num % 10) + '0'; // Extract last digit and convert to character
        num /= 10;
    } while (num > 0);

    // Reverse the string into the output buffer
    int j = 0;
    while (i > 0) {
        str[j++] = buffer[--i]; // Reverse copy from buffer
    }

    // Null-terminate the resulting string
    str[j] = '\0';
}

consteval void test_capacity() {
    static_assert(ARRAY_SIZE == array<int, ARRAY_SIZE>().capacity());
}

extern "C" void c_entry() {
    char str[20];
    print_uart0("Hello OpenEmbedded on RISC-V ");
    intToStr(array<int, ARRAY_SIZE>().capacity(), str);
    print_uart0(str);
    print_uart0("!\n");
}
