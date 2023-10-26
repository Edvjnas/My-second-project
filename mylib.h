#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    list<int> namuDarbai;
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
void IvestiDuomenis(list<Studentas>& studentai);
void SpausdintiRezultatus(const list<Studentas>& studentai);
void SpausdintiStudentus(const list<Studentas>& studentai, const string& failoPavadinimas);
pair<list<Studentas>, list<Studentas>>  RikiuotiStudentus(const list<Studentas>& studentai);
list<Studentas> GeneruotiStudentus(int studentuSkaicius, const string& failoPavadinimas, int namuDarbuSkaicius);
string GeneruotiVarda(int a);
string GeneruotiPavarde(int a);
void FailoNuskaitymas(const string& failoPavadinimas, list<Studentas>& studentai, int namuDarbuSkaicius);
bool sortDidejant(const Studentas& a, const Studentas& b);
bool sortMazejant(const Studentas& a, const Studentas& b);
