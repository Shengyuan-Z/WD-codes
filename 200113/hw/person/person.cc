 ///
 /// @file    person.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-13 21:55:43
 ///
 
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class Person
{
public:
    Person(char* n, int ag):
        name(new char[strlen(n + 1)]()),
        age(ag)
    {
        strcpy(name, n);
    }
    ~Person()
    {
        delete [] name;
    }
    void display()
    {
        cout << "name: " << name << endl
             << "age: " << age  << endl;
    }
private:
    char* name;
    int age;
};

class Employee
:public Person 
{
public:
    Employee(char* n, int ag, char* dep, unsigned sal):
        Person(n, ag),
        department(new char[strlen(dep + 1)]()),
        salary(sal)
    {
        strcpy(department,dep);
    }
    ~Employee()
    {
        delete [] department;
    }
    void display()
    {
        Person::display();
        cout << "department: " << department << endl
             << "salary: " << salary <<endl;
    }
private:
    char* department;
    unsigned salary;
};

int main(void)
{
    Employee e1("Jack Ma", 60, "Speech & Lecture", 0);
    Employee e2("Qiangdong Liu", 48, "Brother", 1);
    e1.display();
    e2.display();
    return 0;
}
