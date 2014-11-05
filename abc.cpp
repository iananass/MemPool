#include "abc.h"
#include "MemMgr.h"

A::A()
: a(1)
{
//    std::cout << __PRETTY_FUNCTION__ << "  " << this << std::endl;
}

A::~A()
{
//    std::cout << __PRETTY_FUNCTION__ << "  " << this << std::endl;
}

void* A::operator new(std::size_t sz)
{
    return mem_mgr<A>::Instance().Create();
}

void A::operator delete(void* ptr, std::size_t sz)
{
    mem_mgr<A>::Instance().Destroy(reinterpret_cast<A*> (ptr));
}

void A::MakeSomeNoise() const
{
    std::cout << " A  = " << a << "  " << this << std::endl;
}

B::B()
: b(2)
{
//    std::cout << __PRETTY_FUNCTION__ << "  " << this << std::endl;
}

B::~B()
{
//    std::cout << __PRETTY_FUNCTION__ << "  " << this << std::endl;
}

void* B::operator new(std::size_t sz)
{
    return mem_mgr<B>::Instance().Create();
}

void B::operator delete(void* ptr, std::size_t sz)
{
    mem_mgr<B>::Instance().Destroy(reinterpret_cast<B*> (ptr));
}

void B::MakeSomeNoise() const
{
    std::cout << " B  = " << b << "  " << this << std::endl;
}

C::C()
: c(3)
{
//    std::cout << __PRETTY_FUNCTION__ << "  " << this << std::endl;
}

C::~C()
{
//    std::cout << __PRETTY_FUNCTION__ << "  " << this << std::endl;
}

void* C::operator new(std::size_t sz)
{
    return mem_mgr<C>::Instance().Create();
}

void C::operator delete(void* ptr, std::size_t sz)
{
    mem_mgr<C>::Instance().Destroy(reinterpret_cast<C*> (ptr));
}

void C::MakeSomeNoise() const
{
    std::cout << " C  = " << c << "  " << this << std::endl;
}