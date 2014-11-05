#include "MemMgr.h"
#include <cstddef>

mem_mgr& mem_mgr::Instance()
{
    static mem_mgr mm;
    return mm;
}

mem_mgr::mem_mgr()
{
    chunk<A>* ach = new chunk<A> [PoolSize];
    chunk<B>* bch = new chunk<B> [PoolSize];
    chunk<C>* cch = new chunk<C> [PoolSize];

    std::cout << "sizeof(chunk<A>) is" << sizeof (chunk<A>) << std::endl;
    std::cout << "sizeof(A) is" << sizeof (A) << std::endl;

    for (int i = 0; i < PoolSize; ++i) {
        m_poolA.push_front(ach[i]);
        std::cout << ((void*) ach[i].mem) << "  inserted into mempoolA" << std::endl;
        m_poolB.push_front(bch[i]);
        m_poolC.push_front(cch[i]);
    }
}

void* mem_mgr::CreateA()
{
    void* ptr;
    if (m_poolA.empty())
        ptr = 0;
    else
        ptr = reinterpret_cast<void*> (m_poolA.front().mem);
    std::cout << "Create A " << ptr << std::endl;
    m_poolA.pop_front();
    return (ptr);
}

void* mem_mgr::CreateB()
{
    std::cout << "Create B" << std::endl;
    if (m_poolB.empty())
        return 0;
    void* ptr = reinterpret_cast<void*> (m_poolB.front().mem);
    m_poolB.pop_front();
    return reinterpret_cast<void*> (ptr);
}

void* mem_mgr::CreateC()
{
    std::cout << "Create C" << std::endl;
    if (m_poolC.empty())
        return 0;
    void* ptr = reinterpret_cast<void*> (m_poolC.front().mem);
    m_poolC.pop_front();
    return reinterpret_cast<void*> (ptr);
}

void mem_mgr::Destroy(A* a)
{
    std::cout << "destroy A " << a << std::endl;
    chunk<A>* area = (chunk<A>*) ((char*) a - offsetof(chunk<A>, mem));
    m_poolA.push_front(*area);
}

void mem_mgr::Destroy(B* b)
{
    std::cout << "destroy B" << std::endl;
    chunk<B>* area = (chunk<B>*) ((char*) b - offsetof(chunk<B>, mem));
    m_poolB.push_front(*area);
}

void mem_mgr::Destroy(C* c)
{
    std::cout << "destroy C" << std::endl;
    chunk<C>* area = (chunk<C>*) ((char*) c - offsetof(chunk<C>, mem));
    m_poolC.push_front(*area);
}
