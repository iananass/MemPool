#include "abc.h"


A::A()
: a(1) { }

A::~A() { }

void* A::operator new(std::size_t sz)
{
    return memmgr::Instance().Create();
}

void A::operator delete(void* ptr, std::size_t sz)
{
    memmgr::Instance().Destroy(reinterpret_cast<A*> (ptr));
}

void A::MakeSomeNoise() const
{
    std::cout << " A  = " << a << "  " << this << std::endl;
}

B::B()
: b(2) { }

B::~B() { }

void* B::operator new(std::size_t sz)
{
    return memmgr::Instance().Create();
}

void B::operator delete(void* ptr, std::size_t sz)
{
    memmgr::Instance().Destroy(reinterpret_cast<B*> (ptr));
}

void B::MakeSomeNoise() const
{
    std::cout << " B  = " << b << "  " << this << std::endl;
}

C::C()
: c(3) { }

C::~C() { }

void* C::operator new(std::size_t sz)
{
    return memmgr::Instance().Create();
}

void C::operator delete(void* ptr, std::size_t sz)
{
    memmgr::Instance().Destroy(reinterpret_cast<C*> (ptr));
}

void C::MakeSomeNoise() const
{
    std::cout << " C  = " << c << "  " << this << std::endl;
}