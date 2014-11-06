#include "MemMgr.h"
#include "abc.h"
#include <memory>

int main()
{
    std::shared_ptr<A> a;
    a = std::shared_ptr<A>(new A);
    a = std::shared_ptr<A>(new A);
    a = std::shared_ptr<A>(new A);
    a = std::shared_ptr<A>(new A);
    new A;
    new A;
    new A;
    new B;
}