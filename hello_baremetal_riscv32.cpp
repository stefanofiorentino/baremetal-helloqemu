// #include "uart_addr.hpp"
// #include "step2.hpp"
// #include "step3.hpp"
#include "step4.hpp"

// template <typename Type, unsigned int _Size>
// struct array final
// {
//     constexpr array() noexcept : arr() {}
//     constexpr void push_back(Type el) noexcept {
//         arr[(index == _Size)?index-1:index++] = el;
//     }
//     constexpr Type back() const noexcept {
//         return arr[(index)?index-1:0];
//     }
//     constexpr Type front() const noexcept {
//         return arr[0];
//     }
//     constexpr Type pop_back() noexcept {
//         return arr[(index)?--index:0];
//     }
//     constexpr unsigned int size() const noexcept { return index; }
//     constexpr unsigned int capacity() const noexcept { return _Size; }

// private:
//     Type arr[_Size];
//     unsigned int index = 0;
// };

// namespace {
// const unsigned int ARRAY_SIZE = 64;

// consteval bool test_capacity() {
//     return ARRAY_SIZE == array<int, ARRAY_SIZE>().capacity();
// }
// static_assert(test_capacity());

// }

// consteval bool test_push() {
//     auto arr = array<int, ARRAY_SIZE>();
//     arr.push_back(-1);
//     return true;
// }
// static_assert(test_push());

// consteval bool test_back() {
//     auto arr = array<int, ARRAY_SIZE>();
//     arr.push_back(-1);
//     return arr.back() == -1;
// }
// static_assert(test_back());

// consteval bool test_push_twice() {
//     auto arr = array<int, ARRAY_SIZE>();
//     arr.push_back(-1);
//     arr.push_back(-2);
//     return arr.front() == -1 && arr.back() == -2;
// }
// static_assert(test_push_twice());

// consteval bool test_size() {
//     auto arr = array<int, ARRAY_SIZE>();
//     if (arr.size() != 0) {
//         return false;
//     }
//     arr.push_back(-1);
//     if (arr.size() != 1) {
//         return false;
//     }
//     arr.push_back(-2);
//     if (arr.size() != 2) {
//         return false;
//     }
//     return true;
// }
// static_assert(test_size());

// consteval bool test_pop_back() {
//     auto arr = array<int, ARRAY_SIZE>();
//     arr.push_back(-1);
//     arr.pop_back();
//     return arr.size() == 0;
// }
// static_assert(test_pop_back());

// consteval bool test_pop_back_multiple() {
//     auto arr = array<int, ARRAY_SIZE>();
//     if (arr.size() != 0) {
//         return false;
//     }
//     arr.push_back(-1);
//     if (arr.size() != 1) {
//         return false;
//     }
//     arr.push_back(-2);
//     if (arr.size() != 2) {
//         return false;
//     }
//     arr.pop_back();
//     if (arr.size() != 1) {
//         return false;
//     }
//     return true;
// }
// static_assert(test_pop_back_multiple());

// consteval bool test_pop_upper_boundaries() {
//     auto arr = array<int, 4>();
//     arr.push_back(-1);
//     arr.push_back(-1);
//     arr.push_back(-1);
//     arr.push_back(-1);
//     if (arr.back() != -1) {
//         return false;
//     }
//     arr.push_back(1);
//     if (arr.back() != 1) {
//         return false;
//     }
//     return true;
// }
// static_assert(test_pop_upper_boundaries());
// }

extern "C" void c_entry() {
    print(uart0, "Hello, world!");
    while(1);
}
