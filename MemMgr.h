#include <iostream>
#include <list>
#include <boost/intrusive/slist.hpp>
#include "abc.h"

class mem_mgr
{
public:

    static mem_mgr& Instance();

    void* CreateA();
    void* CreateB();
    void* CreateC();
    void Destroy(A* a);
    void Destroy(B* b);
    void Destroy(C* c);

private:

    mem_mgr();

    template <class T>
    struct chunk
    {
        char mem[sizeof (T)];
        boost::intrusive::slist_member_hook<> member_hook_;
    };

    typedef boost::intrusive::member_hook<chunk<A>, boost::intrusive::slist_member_hook<>, &chunk<A>::member_hook_> slist_hookA;
    typedef boost::intrusive::member_hook<chunk<B>, boost::intrusive::slist_member_hook<>, &chunk<B>::member_hook_> slist_hookB;
    typedef boost::intrusive::member_hook<chunk<C>, boost::intrusive::slist_member_hook<>, &chunk<C>::member_hook_> slist_hookC;
    
    
    boost::intrusive::slist<chunk<A>, slist_hookA> m_poolA;
    boost::intrusive::slist<chunk<B>, slist_hookB> m_poolB;
    boost::intrusive::slist<chunk<C>, slist_hookC> m_poolC;

    enum
    {
        PoolSize = 5
    };
};
