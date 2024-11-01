#include "Foo.h"

using namespace std;

Foo::Foo() :
    m_character(0),
    m_data(0)
{
}

Foo::Foo(const int data, const char character) :
    m_character(character),
    m_data(data)
{
}

ostream& operator<<(ostream& os, const Foo& obj)
{
    os << "ostream& operator<<(ostream& os, const Foo& obj)" << endl;

    os << obj.m_data << endl;
    os << obj.m_character << endl;
    //os << obj.m_data << endl << obj.m_character << endl;

    return os;
}

istream& operator>>(istream& is, Foo& obj)
{
    cout << "istream& operator>>(istream& is, Foo& obj)" << endl;

    cout << "m_data = ";
    cin >> obj.m_data;

    cout << "m_character = ";
    is >> obj.m_character;

    return is;
}