#include "mylib.h"

using namespace std;

int main() {
    cout << "Pasirinkite konteinerio tipa (1 - vector, 2 - list): ";
    int containerType;
    cin >> containerType;

    if (containerType == 1) {
        vector<Studentas> studentai;
        Testavimas(studentai);
    } else if (containerType == 2) {
        list<Studentas> studentai;
        Testavimas(studentai);
    }

    return 0;
}

