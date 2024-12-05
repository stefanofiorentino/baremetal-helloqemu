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

// const unsigned int ARRAY_SIZE = 128;

// namespace {
// template <typename T, unsigned int _Size>
// struct array
// {
//     consteval explicit array() {
//         data = new T[_Size];
//         for (int i=0; i<_Size; i++) {
//             data[i] = 0;
//         }
//         index = 0;
//     }
//     consteval T const& front() const { return data[0]; }
//     consteval T const& back() const { return data[(index)?index-1:0]; }
//     consteval unsigned int size() const { return index; }
//     consteval unsigned int capacity() const { return _Size; }
//     consteval T& operator[] (unsigned int _index) {
//         return *(data+_index);
//     }
//     consteval T const& push_back(T t) {
//         data[index++]=t;
//         return back();
//     }
//     consteval T const& pop_back() {
//         return data[--index];
//     }
//     constexpr ~array() noexcept{delete[] data;}
// private:
//     T* data;
//     unsigned int index;
// };
// }

// consteval void test_size() {
//     static_assert(0 == array<int, ARRAY_SIZE>().size());
// }

// consteval void test_capacity() {
//     static_assert(ARRAY_SIZE == array<int, ARRAY_SIZE>().capacity());
// }

// consteval void test_subscript() {
//     static_assert(0 == array<int, ARRAY_SIZE>()[0]);
// }

// consteval void test_front() {
//     static_assert(0 == array<int, ARRAY_SIZE>().front());
// }

// consteval void test_back() {
//     static_assert(0 == array<int, ARRAY_SIZE>().back());
// }

// consteval unsigned int size_after_one_push_back() {
//     auto arr = array<int, ARRAY_SIZE>();
//     arr.push_back(84);
//     return arr.size();
// }

// consteval void test_push_back() {
//     static_assert(84 == array<int, ARRAY_SIZE>().push_back(84));
//     static_assert(1 == size_after_one_push_back());
// }

// consteval unsigned int size_after_one_push_back_and_one_pop_back() {
//     auto arr = array<int, ARRAY_SIZE>();
//     arr.push_back(84);
//     arr.pop_back();
//     return arr.size();
// }

// consteval void test_pop_back()  {
//     static_assert(0 == size_after_one_push_back_and_one_pop_back());
// }

extern "C" void c_entry() {
    print_uart0("Hello OpenEmbedded on RISC-V 64!\n");
}
