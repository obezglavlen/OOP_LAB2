#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;
class Set{
    int *arr = new int [size], size = 0;
public:
    Set();
    Set(int a);
    void Input ();
    void Output();              // 1
    void include();             // 2
    void exclude();             // 3
    Set Union(Set obj);         // 4
    Set Inters(Set obj);        // 5
    Set Substr(Set obj);        // 6
    Set SymSubstr(Set obj);     // 7
    void showPower();           // 8
    void Duplicate();
    void Sort(int * arr, int left, int right);







    // DEBUG
    void ptrOut() {cout << arr;}
    void eraseMem() {delete [] arr;}
};

#endif // SET_H
