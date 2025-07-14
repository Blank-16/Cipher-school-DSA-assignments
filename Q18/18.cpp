#include <iostream>

using namespace std;

class Rectangle{
    int length, breadth;
    public:
    Rectangle(int l, int b){
        this->length = l;
        this->breadth = b;
    }

    Rectangle()
    {
        this->length = 10;
        this->breadth = 15;
    }

    int area()
    {
        return length * breadth;   
    }

    void printData()
    {
        cout << "Length\tBreadth\tArea" << endl;
        cout << length << "\t" << breadth << "\t" << area() << endl;
    }
};

int main()
{
    int length, breadth;
    cout << "Give length: ";
    cin >> length;
    cout << "Give breadth: ";
    cin >> breadth;

    Rectangle rect0(length, breadth);
    Rectangle rect1;
    
    int area0 = rect0.area();
    int area1 = rect1.area();
    
    rect0.printData();
    cout << "Using constructor overloading: " << endl;
    rect1.printData();

    return 0;

}
