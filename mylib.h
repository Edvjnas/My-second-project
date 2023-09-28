#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas, galutinisBalasM;
};

double SkaiciuotiGalutiniBalaM(const Studentas& studentas);
double SkaiciuotiGalutiniBala(const Studentas& studentas);
bool SortVardas(const Studentas& a, const Studentas& b);
