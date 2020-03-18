#include "set.h"

using namespace std;

void Set::Sort(int * arr, int left, int right){
    int l, r;
    int x, y;
    l = left; r = right;
    x = arr[(left + right) / 2];
    do{
        while((arr[l] < x) && (l < right)) l++;
        while((x < arr[r]) && (r > left)) r--;
        if(l<=r){
            y = arr[l];
            arr[l] = arr[r];
            arr[r] = y;
            l++;
            r--;
        }
    } while(l<=r);
    if(left<r) Sort(arr, left, r);
    if(l<right) Sort(arr, l, right);


}

void Set::Duplicate() {
    for (int i = 0; i < size - 1; i++){
        if (arr[i] == arr[i+1]){
            for (int j = i; j < size - 1; j++){
            arr[j] = arr[j+1];
            } size -= 1; i -= 1;
        }
    }
}

Set::Set() {
    size = 0;
    Input();
}

Set::Set(int a) {
    size += a;
    for (int i = 0; i < size; i++) {
        arr[i] = ((i*a) + 1);
    }
}

void Set::Input() {
    // Enter values in a array
    cout << endl << "Enter the array, if you end press '0': ";
    for (int i = 0;; i++) {
        cin >> arr[i];
        if (arr[i] != 0)
            size += 1;
        else break;
    }
    Sort(arr, 0, size - 1);
    Duplicate();
}

void Set::Output(){
    // Show values of array
    cout << "\n|<----------------->|\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << "\n|<--------"<<size<<"--------->|\n";
}



void Set::showPower(){
    // Show power of array
    cout << "Power of vector = " << size << endl;
}

void Set::include(){
    // Add element to array
        int NewElement;
        cout << "Enter new elemment\n";
        cin >> NewElement;
        size += 1;
        arr[size - 1] = NewElement;
        Sort(arr, 0, size - 1);
        Duplicate();
}

void Set::exclude() {
    // Remove all elements X from array
    int ElementToRemove;
    cout << "Enter element, you want to remove\n";
    cin >> ElementToRemove;
    for (int i = 0; i < size; i++) {
        if (arr[i] == ElementToRemove) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j+1];
            } size -= 1; i -= 1;
        }
    }

    Sort(arr, 0, size - 1);
    Duplicate();
}


Set Set::Union(Set obj){
    // Union of two arrays
    Set res(size + obj.size);
    for (int i = 0; i < size; i++) res.arr[i] = arr[i];
    for (int i = 0; i < obj.size; i++) res.arr[i + size] = obj.arr[i];
    //for (int i = 0; i < res.size; i++) cout << endl<< res.arr[i] << endl;
    Sort(res.arr, 0, res.size - 1);
    res.Duplicate();
    return res;
}

Set Set::Inters(Set obj){
    // Intersection of two arrays
    Set res(0);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < obj.size; j++) {
            if (arr[i] == obj.arr[j]) {
                res.size += 1;
                res.arr[res.size - 1] = arr[i];
            }
        }
    }
    Sort(res.arr, 0, res.size - 1);
    res.Duplicate();
    return res;
}

Set Set::Substr(Set obj){
    // Substraction of two arrays
    Set res(0);
    for (int i = 0; i < size; i++) {
        int j = 0;
        while(j < obj.size && obj.arr[j] != arr[i])
            j++;

        if (j == obj.size) {
            res.size += 1;
            res.arr[res.size - 1] = arr[i];
        }
    }
    Sort(res.arr, 0, res.size - 1);
    res.Duplicate();
    return res;
}

Set Set::SymSubstr(Set obj){
    // Symmetric substraction of two arrays
    Set res(0);
    for (int i = 0; i < size; i++) {
        int j = 0;
        while(j < obj.size && obj.arr[j] != arr[i])
            j++;

        if (j == obj.size) {
            res.size += 1;
            res.arr[res.size - 1] = arr[i];
        }
    }

    for (int i = 0; i < obj.size; i++) {
        int j = 0;
        while(j < size && arr[j] != obj.arr[i])
            j++;

        if (j == size) {
            res.size += 1;
            res.arr[res.size - 1] = obj.arr[i];
        }
    }
    Sort(res.arr, 0, res.size - 1);
    res.Duplicate();
    return res;
}

