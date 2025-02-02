#include <bits/stdc++.h>
#include "bird.h"
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
}

int main()
{
    Bird *bird = new pigeon();
    // sparrow*sp=new sparrow();
    // sp->eat(); //not possible
    birdDoesSomething(bird);
    // Bird*b2=new Bird(); // not possible
    return 0;
}