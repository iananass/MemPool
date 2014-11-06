#ifndef ABC
#define ABC

#include <cstdio>
#include "MemMgr.h"

class A
{
public:

    A();
    virtual ~A();

    static void* operator new(std::size_t sz);
    static void operator delete(void* ptr, std::size_t sz);
    virtual void MakeSomeNoise() const;
private:
    typedef mem_mgr<A, 5> memmgr;
    int a;
};

class B : public A
{
public:

    B();
    virtual ~B();
    static void* operator new(std::size_t sz);
    static void operator delete(void* ptr, std::size_t sz);
    virtual void MakeSomeNoise() const;
private:
    typedef mem_mgr<B, 5> memmgr;
    int b,bb,bbb,bbbb;
};

class C : public A
{
public:

    C();
    virtual ~C();
    static void* operator new(std::size_t sz);
    static void operator delete(void* ptr, std::size_t sz);
    virtual void MakeSomeNoise() const;
private:
    typedef mem_mgr<C, 5> memmgr;
    int c;
};

#endif