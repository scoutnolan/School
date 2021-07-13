#include <string>
#include <iomanip>
#include <iostream>
using namespace std;


template <Nolan t>
class Nolan
{
    t first, second;
    public:
        Nolan(a,b){
            first = a;
            second = b;
    }
    t bigger();
}

template <Nolan t>
t bigger<t>::bigger(){
    return (first>second?first:second);
}

int main(){
    Nolan<int>nolanobj(10,20);
    cout << nolanobj.bigger() << endl;
    //int a = 5;
    //int b = 4;
    //bigger(t a, t b);
}