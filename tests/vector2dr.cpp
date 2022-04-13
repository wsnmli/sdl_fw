//  g++ vector2dr.cpp && ./a.out 
#include <cassert>

#include "../vector2d.h"
using namespace std;

int main() {
    // +, -, *, /
    Vector z(0., 0.), a(1., 1.), b(2., 2.) ;
    assert(a*0 == z); assert(0*a == z);
    assert(a*2 == b); assert(a+a == b);
    assert(b-a==a);
    // +=, -=, *=, /=
}