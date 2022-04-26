//  g++ vector2dr.cpp && ./a.out 
#include <cassert>

#include "../vector2d.h"
using namespace std;

int main() {
    // +, -, *, /
    Vector z(0., 0.), a(1., 1.), b(2., 2.) ;
    assert(a*0 == z); assert(0*a == z);
    assert(a*2 == b); assert(a+a == b);
    assert(a+b==b+a);
    assert(b-a==a);
    // +=, -=, *=, /=

    z+=a;
    assert(z==a);
    z-=a;
    assert(z==Vector(0,0));
    assert(b/2 == a);
}