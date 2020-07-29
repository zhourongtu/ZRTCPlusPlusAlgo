template<typename _Tp, typename _Alloc = std::allocator<_Tp>>
    class vector:protected _Vector_base<_Tp, _Alloc>


int *p;
allocator<int> alloc1;
p = alloc1.allocate(1);
alloc1.deallocate(p, 1);
