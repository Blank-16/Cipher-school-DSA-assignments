
#include <iostream>
using namespace std;

class solution
{
    string name;
    int age;
    float height;

public:
    solution(string n, int a, float h)
    {
        this->name = n;
        this->age = a;
        this->height = h;
    }
    void printDetails()
    {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Height: " << this->height << endl;
    }
};

int main()
{

    string name;
    int age;
    float height;
    cout << "Name of person: ";
    cin >> name;
    cout << "Age of person: ";
    cin >> age;
    cout << "Height of person: ";
    cin >> height;
    solution person(name, age, height);
    person.printDetails();

    return 0;
}