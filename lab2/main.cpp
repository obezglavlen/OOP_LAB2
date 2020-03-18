#include "set.h"

void Menu();
void Request(Set obj1, Set obj2);

int main() {
    Set a;
    Set b;
    for (;;)
    Request(a, b);
}

void Menu() {
    cout << "Enter from 0 to 8. What do you want to do?\n";
    cout << "1 - Show arrays\n";
    cout << "2 - Include element in the array\n";
    cout << "3 - Exclude element from array\n";
    cout << "4 - Union of two arrays\n";
    cout << "5 - Intersection of two arrays\n";
    cout << "6 - Substraction arrays\n";
    cout << "7 - Symmetric substraction arrays\n";
    cout << "8 - Show power of array\n";
    cout << "0 - exit\n";
}

void Request(Set obj1, Set obj2){
    Menu();
    char Answer;
    cin >> Answer;

    switch (Answer) {
    case '1': {
        obj1.Output();
        obj2.Output();
        break;
    }
    case '2': {
        cout << "In which array you want to include?\n";
        int Ans;
        cin >> Ans;
        if (Ans == 1) {
            obj1.include();
            cout << "It's will array:\n";
            obj1.Output();
        }
        else if (Ans == 2) {
            obj2.include();
            cout << "It's will array:\n";
            obj2.Output();
        }
        else {
            cout << "Enter 1 or 2\n";
        }
        break;
    }
    case '3': {
        cout << "From which array you want to exclude?\n";
        int Ans;
        cin >> Ans;
        if (Ans == 1) {
            obj1.exclude();
            cout << "It's will array:\n";
            obj1.Output();
        }
        else if (Ans == 2) {
            obj2.exclude();
            cout << "It's will array:\n";
            obj2.Output();
        }
        else {
            cout << "Enter 1 or 2\n";
        }
        break;
    }
    case '4': {
        obj1.Union(obj2).Output();
        break;
    }
    case '5': {
        obj1.Inters(obj2).Output();
        break;
    }

    case '6': {
        obj1.Substr(obj2).Output();
        break;
    }

    case '7': {
        obj1.SymSubstr(obj2).Output();
        break;
    }

    case '8': {
        obj1.showPower();
        obj2.showPower();
        break;
    }
    case '0': {
        exit(0);
        break;
    }
    default: {
        cout << "Enter from 0 to 8\n";
    }
    }
}
