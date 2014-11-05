#ifndef ABC
#define ABC

#include <cstdio>

class A
{
public:

    A();
    virtual ~A();

    static void* operator new(std::size_t sz);
    static void operator delete(void* ptr, std::size_t sz);
    virtual void MakeSomeNoise() const;
private:
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
    int b;
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
    int c;
};

#endif