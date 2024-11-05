#include <iostream>
using namespace std;
class date {
public:
    int year;
    int month;
    int date;
    void print () {
        cout << year << ' ' << month << ' ' << date << endl;
    }
};

class People {
public:
    People () {}
    People (int num, int se, date bir) : number (num) , sex (se), birthdate (bir) {}
    ~People () {}
    People (const People &p);
    void show () {
        cout << number << ' ' << sex << ' ' << id << endl;
        birthdate.print();
    }
    ~People () {};
private:
    int number;
    bool sex;
    date birthdate;
    int id;
};
inline People :: People (const People &p) {
    number = p.number;
    sex = p.sex;
    birthdate = p.birthdate;
    id = p.id;
}
int main () 
{
    date da;
    da.year  = 2024;
    da.month = 11;
    da.date  = 1;
}