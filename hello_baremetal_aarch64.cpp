const unsigned int ARRAY_SIZE = 128;

namespace {
template <typename T, unsigned int _Size>
struct array
{
    consteval explicit array() {
        data = new T[_Size*sizeof(T)];
        data[0] = 42;
    }
    consteval T front() const { return data[0]; }
    consteval T back() const {return *(data+_Size-1);}
    consteval unsigned int size() const { return _Size; }
    consteval T& operator[] (unsigned int index) {
        return *(data+index);
    }
    constexpr ~array() {delete[] data;}
private:
    T* data;
};
}

consteval void test_size() {
    static_assert(array<int, ARRAY_SIZE>().size() == ARRAY_SIZE);
}
consteval void test_subscript() {
    static_assert(array<int, ARRAY_SIZE>()[0] ==  42);
}

extern "C" void c_entry() {
  test_size();
  test_subscript();
}
