#include "array.hpp"

#define VIRT_UART0 0x10000000

namespace {
struct uart_t final
{
    constexpr explicit uart_t(unsigned int _Base) : 
        UARTDR( const_cast<volatile unsigned int * const>(
                    static_cast<unsigned int *>(
                        reinterpret_cast<void *>(_Base)
                    )
                )
        ) {
    }
    void print(const char *str) {
        while(*str != '\0') {
            *UARTDR = (unsigned int)(*str);
            str++;
        }
    }
    uart_t& operator << (const char *str) {
        print(str);
        return *this;
    }
    volatile unsigned int * const UARTDR;
};
}


// ChatGPT prompt: can you help me implementing a plain C function, 
// without using any function from the standard library that is able to transform an integer in a string?
extern "C" void intToStr(unsigned int num, char* str) {
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


extern "C" void c_entry() {
    char str[20];
    auto uart0 = uart_t(VIRT_UART0);
    uart0.print("Hello OpenEmbedded on RISC-V ");
    intToStr(array<int, ARRAY_SIZE>().capacity(), str);
    uart0.print(str);
    uart0 << " with C++20" << "!\n";
}
