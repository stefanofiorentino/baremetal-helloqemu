namespace {
const unsigned int ARRAY_SIZE = 64;
template <typename T, unsigned int _Size>
struct array final
{
    consteval unsigned int capacity() const { return _Size; }
};


consteval void test_capacity() {
    static_assert(ARRAY_SIZE == array<int, ARRAY_SIZE>().capacity());
}
}
