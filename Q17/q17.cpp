#include <iostream>
using namespace std;

class Student {
  string name;
  int mark;

  public:
    Student(string n, int m){
        this->name = n;
        this->mark = m;
    }

    void displayData()
    {
        cout << this->name << endl;
        cout << this->mark;
    }
    
};

int main()
{
    Student student1("Blank" , 88);
    student1.displayData();

    return 0;
}

