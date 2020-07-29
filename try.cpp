#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
};
int my_func(int i){
    printf("%d", i);
    return 0;
}

double my_divied(double x, double y)
{
    return x/y;
}
int main()
{
    auto s = bind(my_divied, 10, 2);
    int i = 0;
    int a[2] = {1, 2};
    // for_each(a, a+2, my_func);
    cout << &my_func;

}

// count_if(vi.begin(), vi.end(),
        // not1(bind2nd(less<int>(), 40)));



template<typename _Tp>
    class allocator;

template<typename _Tp>
    class allocator<void>
    {
    public:
        typedef size_t          size_type;
        typedef ptrdiff_t       difference_type;
        typedef void*           pointer;
        typedef const void*     const_pointer;
        typedef void            value_type;

        template<typename _Tp1>
            struct rebind
            {   typedef allocator<_Tp1> other;};

    };


template <class T,
        class Alloc = alloc>
class vector
{
    ...
};

template<class Alloc>
class vector<bool, Alloc>
{
    ...
};

template <class Iterator>
struct iterator_traits{
    typedef ....
};

template <class Iterator>
struct iterator_traits<T*>{
    typedef ....
};

template <class Iterator>
struct iterator_traits<const T*>{
    typedef ....
};

template<class _Ty, class _A = allocator<_Ty> >
class vector
{
    ...
};

reference operator*() const
{
    return (*node).data;
}

pointer operator->() const
{
    return &(operator*());
}


struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_acess_iterator_tag : public bidirectional_iterator_tag {};
