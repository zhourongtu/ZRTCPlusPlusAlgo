template <class T>
class allocator
{
public:
    typedef size_t          size_type;
    typedef ptrdiff_t       difference_type;
    typedef T*              pointer;
    typedef T               value_type;

    pointer allocate(size_type n, allocator<void>)
}