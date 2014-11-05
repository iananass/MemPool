#include "MemMgr.h"
#include <memory>

int main()
{
    //    std::shared_ptr<A> a, b, c;
    //    a = std::shared_ptr<A>(new A);
    //    b = std::shared_ptr<A>(new B);
    //    c = std::shared_ptr<A>(new C);
    //    
    //    a->MakeSomeNoise();
    //    b->MakeSomeNoise();
    //    c->MakeSomeNoise();
    //    B*bb = new B;
    //    bb->MakeSomeNoise();
    //    
    //    a = std::shared_ptr<A>(new A);
    //    a->MakeSomeNoise();
    //    a = std::shared_ptr<A>(new A);
    //    a->MakeSomeNoise();
    //    a = std::shared_ptr<A>(new A);
    //    a->MakeSomeNoise();
    //    a = std::shared_ptr<A>(new A);
    //    a->MakeSomeNoise();

    std::shared_ptr<A> a;
    a = std::shared_ptr<A>(new A);
    a = std::shared_ptr<A>(new A);
    a = std::shared_ptr<A>(new A);
    a = std::shared_ptr<A>(new A);
    new A;
    new A;
    new A;
    new A;
    new A;
    new A;
}