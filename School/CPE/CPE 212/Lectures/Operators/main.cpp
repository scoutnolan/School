#include <iostream>
#include <string>

using namespace std;
template <class T>
struct vec
{
    T x;
    T y;

    // Constructors
    vec() : x(0), y(0) {}
    vec(T _x, T _y) : x(_x), y(_y) {}

    // Overloads
    vec operator + (const vec& rightSide)
    {
        return vec(this->x + rightSide.x, this->y + rightSide.y);
    }

    vec operator - (const vec& rightSide)
    {
        return vec(this->x - rightSide.x, this->y - rightSide.y);
    }

    vec operator ++ (int)
    {
        x++;
        y++;
        return *this;
    }
};

template <typename T>
ostream& operator << (ostream& stream, const vec<T> v)
{
    stream << "Vector x = " << v.x << " y = " << v.y << endl;
    return stream;
}


int main()
{
    vec<float> a = {1.0, 2.5};
    vec<float> b = {4.0, 7.5};
    vec<float> c = {2.0, 3.5};

    vec<int> d = {1, 2};
    vec<int> e = {4, 5};

    a.x = b.x + c.x;

    cout << "A " << a << endl;

    b = a + c;

    cout << "B " << b << endl;

    c++;

    cout << "C " << c << endl;

    vec<int> f = d + e;
    cout << "F " << f << endl;

    return 0;
}