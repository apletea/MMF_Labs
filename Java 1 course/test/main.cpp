#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int *p1;
    int *p2;
    int arr[10];
    p1 = &arr[0];
    p2 = &arr[9];
    cout << p2 - p1 << endl;
    cout << *p1 + p2 << endl;
    cout << *p1**p2 << endl;
    cout << p2/p1;
    return 0;
}
