#include <iostream>
#include <list>
#include <boost/intrusive/slist.hpp>
#include "abc.h"

template <class T>
class mem_mgr
{
public:

    static mem_mgr& Instance();

    void* Create();
    void Destroy(T* obj);

private:

    mem_mgr();

    struct chunk
    {
        char mem[sizeof (T)];
        boost::intrusive::slist_member_hook<> member_hook_;
    };

    typedef boost::intrusive::member_hook<chunk, boost::intrusive::slist_member_hook<>, &chunk::member_hook_> slist_hook;
    
    boost::intrusive::slist<chunk, slist_hook> m_pool;
    chunk* m_chunks;

    enum
    {
        PoolSize = 5
    };
};

template <class T>
mem_mgr<T>& mem_mgr<T>::Instance()
{
    static mem_mgr<T> mm;
    return mm;
}

template <class T>
mem_mgr<T>::mem_mgr()
{
    m_chunks = new chunk [PoolSize];


    std::cout << "sizeof(mem_mgr<T>::chunk) is" << sizeof (chunk) << std::endl;
    std::cout << "sizeof(mem_mgr<T>::T) is" << sizeof (T) << std::endl;

    for (int i = 0; i < PoolSize; ++i) {
        m_pool.push_front(m_chunks[i]);
        std::cout << ((void*) m_chunks[i].mem) << "  inserted into mempoolA" << std::endl;
    }
}

template <class T>
void* mem_mgr<T>::Create()
{
    void* ptr;
    if (m_pool.empty())
        ptr = 0;
    else
        ptr = reinterpret_cast<void*> (m_pool.front().mem);
    std::cout << "Create A " << ptr << std::endl;
    m_pool.pop_front();
    return (ptr);
}

template <class T>
void mem_mgr<T>::Destroy(T* obj)
{
    std::cout << "destroy A " << obj << std::endl;
    chunk* area = (chunk*) ((char*) obj - offsetof(chunk, mem));
    m_pool.push_front(*area);
}