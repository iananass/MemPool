#ifndef __MemMgr__h__
#define __MemMgr__h__

#include <iostream>
#include <list>
#include <boost/intrusive/slist.hpp>

template <class T, int PoolSize>
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

};

template <class T, int PoolSize>
mem_mgr<T, PoolSize>& mem_mgr<T, PoolSize>::Instance()
{
    static mem_mgr<T, PoolSize> mm;
    return mm;
}

template <class T, int PoolSize>
mem_mgr<T, PoolSize>::mem_mgr()
{
    m_chunks = new chunk [PoolSize];


    std::cout << "sizeof(mem_mgr<T, PoolSize>::chunk) is" << sizeof (chunk) << std::endl;
    std::cout << "sizeof(mem_mgr<T, PoolSize>::T) is" << sizeof (T) << std::endl;

    for (int i = 0; i < PoolSize; ++i) {
        m_pool.push_front(m_chunks[i]);
        std::cout << ((void*) m_chunks[i].mem) << "  inserted into mempoolA" << std::endl;
    }
}

template <class T, int PoolSize>
void* mem_mgr<T, PoolSize>::Create()
{
    void* ptr;
    if (m_pool.empty())
        ptr = 0;
    else
        ptr = reinterpret_cast<void*> (m_pool.front().mem);
    std::cout << "Create " << ptr << std::endl;
    m_pool.pop_front();
    return (ptr);
}

template <class T, int PoolSize>
void mem_mgr<T, PoolSize>::Destroy(T* obj)
{
    std::cout << "destroy " << obj << std::endl;
    chunk* area = (chunk*) ((char*) obj - offsetof(chunk, mem));
    m_pool.push_front(*area);
}

#endif