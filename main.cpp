#include "mylib.h"

using namespace std;

int main() {
    //vector<Studentas> studentai;
    //IvestiDuomenis(studentai);
    //SpausdintiRezultatus(studentai);
    vector<Studentas> studentai = GeneruotiStudentus(1000, "p.txt", 10)
    SortStudentai(studentai, "genijai.txt", "vargsiukai.txt");

    return 0;
}
