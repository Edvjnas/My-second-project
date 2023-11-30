#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas, galutinisBalasM;
};

template <typename T>
double SkaiciuotiGalutiniBalaM(const T& studentas);

template <typename T>
double SkaiciuotiGalutiniBala(const T& studentas);

template <typename T>
bool SortVardas(const T& a, const T& b);

template <typename T>
int NamuDarbuSk(const string& pav);

template <typename T>
void klaida(int &a);

template <typename T>
void klaida1(int &a);

template <typename T>
void klaida2(int &a);

template <typename T>
void klaida3(int &a);

template <typename T>
void klaida4(T &a);

template <typename T>
void klaida5(T &a);

template <typename T>
void IvestiDuomenis(T& studentai);

template <typename T>
void SpausdintiRezultatus(const T& studentai);

template <typename T>
void SpausdintiStudentus(const T& studentai, const string& failoPavadinimas);

template <typename T>
pair<T, T> RikiuotiStudentus(const T& studentai);

vector<Studentas> GeneruotiStudentus(int studentuSkaicius, const string& failoPavadinimas, int namuDarbuSkaicius);

template <typename T>
string GeneruotiVarda(int a);

template <typename T>
string GeneruotiPavarde(int a);

template <typename T>
void FailoNuskaitymas(const string& failoPavadinimas, T& studentai, int namuDarbuSkaicius);

template <typename T>
bool sortDidejant(const T& a, const T& b);

template <typename T>
bool sortMazejant(const T& a, const T& b);

template <typename T>
void Testavimas (T& studentai);
