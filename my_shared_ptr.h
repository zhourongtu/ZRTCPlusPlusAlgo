// https://github.com/nwpuhq/AwesomeCpp

#include <functional>

template <typename T>
class smart_ptr
{
public:
    smart_ptr(); // 默认构造函数
    explicit smart_ptr(T*); // 显式的声明含有一个参数的类构造函数
    smart_ptr(const smart_ptr&); // 利用另一个指针初始化该指针
    smart_ptr(T*, std::function<void(T*)>); // 指针,删除器
    smart_ptr& operator=(const smart_ptr&); // 赋值运算符
    T& operator*() const; // 间接运算符
    T* operator->() const; // 指针运算符

    ~smart_ptr();
    // 向bool的类型转换
    explicit operator bool() const; // bool 运算符

    bool unique(); // 判断是否唯一
    void reset(); // 只解决当前指针的问题
    void reset(T*); // 指向另一个指针
    void reset(T*, std::function<void(T*)>); // 指向另一个指针，同时使用不同的删除器
    T* release(); // 相当于reset，但是返回指针（与reset的区别在于 不会设置 默认的删除器

    T* get() const; // 获取指针

private:
    // 默认的deleter
    static std::function<void(T*)> default_del;

private:
    unsigned* m_p_use_count = nullptr;
    T* m_pobject = nullptr;
    std::function<void(T*)> m_del = default_del;
};

template<typename T>
std::function<void(T*)> smart_ptr<T>::default_del = [](T* p){delete p; p = nullptr;};

// 多参数，利用T本身的构造函数创建一个实例对象，并指向它
template<typename T, typename ...Args>
smart_ptr<T> make_smart(Args&&... args)
{
    smart_ptr<T> sp(new T(std::forward<Args>(args)...));
    return sp;
}

// 初始化函数
template<typename T>
smart_ptr<T>::smart_ptr()
    :m_pobject(nullptr), m_p_use_count(new unsigned(1))
{
}

template<typename T>
smart_ptr<T>::smart_ptr(T *p)
    :m_pobject(p), m_p_use_count(new unsigned(1))
{
}

template<typename T>
smart_ptr<T>::smart_ptr(T *p, std::function<void(T*)> del)
    :m_pobject(p), m_p_use_count(new unsigned(1)), m_del(del)
{   
}

template<typename T>
smart_ptr<T>::smart_ptr(const smart_ptr& rhs)
    :m_pobject(rhs.m_pobject), m_p_use_count(rhs.m_p_use_count), m_del(rhs.m_del)
{
    (*m_p_use_count)++;
}

template<typename T>
smart_ptr<T>& smart_ptr<T>::operator= (const smart_ptr &rhs)
{
    m_del = rhs.m_del;
    ++(*rhs.m_p_use_count);
    if(--(*m_p_use_count) == 0){
        m_del(m_pobject);
        delete m_p_use_count;
    }

    m_p_use_count = rhs.m_p_use_count;
    m_pobject = rhs.m_pobject;
    return *this;
}

template<typename T>
T& smart_ptr<T>::operator*() const
{
    return *m_pobject;
}

template<typename T>
T* smart_ptr<T>::operator->() const
{
    return &this->operator*();
}

/*
operator->确实是个比较容易迷惑的地方，
对对象使用->运算符的语义是先调用对象的operator->，
然后对返回的裸指针使用原生的->运算符。
所以希望对象相当于指向谁的指针，就让operator->返回谁的指针。
返回&(**this)是个常见的实现，保持了原生语义中a->b和(*a).b的一致性。

*/

template<typename T>
smart_ptr<T>::~smart_ptr()
{
    if(--(*m_p_use_count) == 0)
    {
        m_del(m_pobject);
        m_pobject = nullptr;

        delete m_p_use_count;
        m_p_use_count = nullptr;
    }
}

template<typename T>
bool smart_ptr<T>::unique()
{
    return *m_p_use_count == 1;
}

template<typename T>
void smart_ptr<T>::reset()
{
    (*m_p_use_count)--;
    if(*m_p_use_count == 0){
        m_del(m_pobject);
    }

    m_pobject = nullptr;
    *m_p_use_count = 1;
    m_del = default_del;
}

template<typename T>
void smart_ptr<T>::reset(T* p)
{
    (*m_p_use_count)--;
    if(*m_p_use_count == 0){
        m_del(m_pobject);
    }

    m_pobject = p;
    *m_p_use_count = 1;
    m_del = default_del;
}

template<typename T>
void smart_ptr<T>::reset(T *p, std::function<void(T*)> del)
{
    reset(p);
    m_del = del;
}


template<typename T>
T* smart_ptr<T>::release()
{
    (*m_p_use_count)--;
    if(*m_p_use_count == 0){
        *m_p_use_count = 1;
    }
    T* p = m_pobject;
    m_pobject = nullptr;

    return p;
}

template<typename T>
T* smart_ptr<T>::get() const
{
    return m_pobject;
}

template<typename T>
smart_ptr<T>::operator bool() const
{
    return m_pobject != nullptr;
}

