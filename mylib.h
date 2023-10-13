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
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas, galutinisBalasM;
};

double SkaiciuotiGalutiniBalaM(const Studentas& studentas);
double SkaiciuotiGalutiniBala(const Studentas& studentas);
bool SortVardas(const Studentas& a, const Studentas& b);
int NamuDarbuSk(const string& pav);
void klaida(int &a);
void klaida1(int &a);
void klaida2(int &a);
void klaida3(int &a);
void klaida4(string &a);
void klaida5(string &a);
void IvestiDuomenis(vector<Studentas>& studentai);
void SpausdintiRezultatus(const vector<Studentas>& studentai);
void GeneruotiStudentus(int studentuSkaicius, const string& failoPavadinimas);
string GeneruotiVarda(int a);
string GeneruotiPavarde(int a);


