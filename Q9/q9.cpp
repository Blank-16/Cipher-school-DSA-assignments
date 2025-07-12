
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> random = {1, 2, 3, 4, 5, 6, 7};
    int size = random.size();
    cout << "First unit of Array: " << random.at(0) << endl;
    cout << "Last unit of Array: " << random.at(size - 1) << endl;
    
    return 0;
}