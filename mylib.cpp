#include "mylib.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

double SkaiciuotiGalutiniBalaM(const Studentas& studentas) {
    if (studentas.namuDarbai.empty()) {
        return studentas.egzaminas * 0.6;
    }
    vector<int> namuDarbaiSorted = studentas.namuDarbai;
    sort(namuDarbaiSorted.begin(), namuDarbaiSorted.end());
    double namuDarbuMediana = 0.0;
    int n = namuDarbaiSorted.size();
    if (n % 2 == 0){
        int mid1 = namuDarbaiSorted[n/2];
        int mid2 = namuDarbaiSorted[(n/2)-1];
        namuDarbuMediana = (mid1 + mid2) / 2;
    }
    else {
        namuDarbuMediana = namuDarbaiSorted[n/2];
    }

    return 0.4 * namuDarbuMediana + 0.6 * studentas.egzaminas;
}
double SkaiciuotiGalutiniBala(const Studentas& studentas) {
    if (studentas.namuDarbai.empty()) {
        return studentas.egzaminas * 0.6;
    }
    double namuDarbuVidurkis = 0.0;
    for (int nd : studentas.namuDarbai) {
        namuDarbuVidurkis =namuDarbuVidurkis + nd;
    }
    namuDarbuVidurkis = namuDarbuVidurkis / studentas.namuDarbai.size();

    return 0.4 * namuDarbuVidurkis + 0.6 * studentas.egzaminas;
}

bool SortVardas(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}
