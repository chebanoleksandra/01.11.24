#pragma once

#include <iostream>

class Foo
{
private:

    char m_character;
    int m_data;

public:

    Foo();
    Foo(const int data, const char character);

    friend std::ostream& operator<<(std::ostream& os, const Foo& obj);
    friend std::istream& operator>>(std::istream& is, Foo& obj);
};