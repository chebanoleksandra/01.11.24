#include<iostream>
using namespace std;

class Movie
{
    char* name;
    double time;
    int year;
public:
    Movie()
    {
        name = nullptr;
        time = 0;
        year = 0;
    }
    Movie(const char* n, double t, int y)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        time = t;
        year = y;
    }
    Movie(const Movie& obj)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
        time = obj.time;
        year = obj.year;

    }
    ~Movie()
    {
        delete[] name;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Time: " << time << endl;
        cout << "Year: " << year << endl;
    }
    const char* GetName()
    {
        return name;
    }

    double GetTime()
    {
        return time;
    }
    int GetYear()
    {
        return year;
    }
    void SetName(const char* n)
    {
        if (name != nullptr)
        {
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }
    void SetTime(double t)
    {
        time = t;
    }
    void SetYear(int y)
    {
        year = y;
    }
    /*friend ostream& operator<<(ostream& os, Movie& obj);*/
    /*friend istream& operator>>(istream& is, Movie& obj);*/
};

ostream& operator<<(ostream& os, Movie& obj)
{
    /*os << obj.name << "\t" << obj.time << "\t" << obj.year << endl;*/
    os << obj.GetName() << "\t" << obj.GetTime() << "\t" << obj.GetYear() << endl;
    return os;
}

istream& operator>>(istream& is, Movie& obj)
{
    char buff[20];
    double t;
    int y;
    cout << "Input title: ";
    is >> buff;
    obj.SetName(buff);
    cout << "Input time: ";
    is >> t;
    obj.SetTime(t);
    cout << "Input year: ";
    is >> y;
    obj.SetYear(y);
    return is;
}

int main()
{
    Movie obj1("Little Women", 2.15, 2019);
    cout << obj1;
    cin >> obj1;
    cout << obj1;
}