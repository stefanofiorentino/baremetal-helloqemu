template <unsigned int _Size = 256u>
struct uart_addr_t final
{
    consteval explicit uart_addr_t() noexcept : buffer(), index(0) {
        buffer[0] = '\0';
    }
    consteval operator unsigned int() noexcept {
        return buffer[(index)?index-1:0];
    }
    consteval uart_addr_t& operator *() noexcept {
        return *this;
    }
    consteval uart_addr_t& operator = (unsigned int c) noexcept {
        if (index < _Size-1) {
            buffer[index++] = (char)c;
            buffer[index] = '\0';
        }
        return *this;
    }

    char buffer[_Size];
private:
    unsigned int index;
};

namespace {
consteval bool test_uart_addr_to_unsigned_int() {
    return uart_addr_t() == 0;
}
static_assert(test_uart_addr_to_unsigned_int());

consteval bool test_uart_addr_dereference() {
    uart_addr_t uart_addr;
    (void)*uart_addr;
    return true;
}
static_assert(test_uart_addr_dereference());

consteval bool test_uart_addr_assignment() {
    uart_addr_t uart_addr;
    *uart_addr = (unsigned int)'a';
    return *uart_addr == (unsigned int)'a';
}
static_assert(test_uart_addr_assignment());

consteval bool test_uart_addr_read_last_written_char_empty() {
    uart_addr_t uart_addr;
    return uart_addr == 0;
}
static_assert(test_uart_addr_read_last_written_char_empty());

consteval bool test_uart_addr_read_last_written_char_single() {
    uart_addr_t uart_addr;
    *uart_addr = (unsigned int)'a';
    return uart_addr == (unsigned int)'a';
}
static_assert(test_uart_addr_read_last_written_char_single());
} // namespace
