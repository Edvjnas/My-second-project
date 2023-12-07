#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

/*struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas, galutinisBalasM;
};*/
class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas, galutinisBalasM;

public:
    Studentas() : egzaminas(0), galutinisBalas(0.0), galutinisBalasM(0.0) {}
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& namuDarbai, int egzaminas)
        : vardas(vardas), pavarde(pavarde), namuDarbai(namuDarbai), egzaminas(egzaminas),
          galutinisBalas(0.0), galutinisBalasM(0.0) {}
    std::vector<Studentas> GeneruotiStudentus(int studentuSkaicius, const std::string& failoPavadinimas, int namuDarbuSkaicius);

    const std::string& GetVardas() const {
        return vardas;
    }

    void SetVardas(const std::string& newVardas) {
        vardas = newVardas;
    }

    const std::string& GetPavarde() const {
        return pavarde;
    }

    void SetPavarde(const std::string& newPavarde) {
        pavarde = newPavarde;
    }

    const std::vector<int>& GetNamuDarbai() const {
        return namuDarbai;
    }

    void AddNamuDarbas(int pazymys) {
        namuDarbai.push_back(pazymys);
    }

    void ClearNamuDarbai() {
        namuDarbai.clear();
    }

    void SetNamuDarbai(const std::vector<int>& newNamuDarbai) {
        namuDarbai = newNamuDarbai;
    }

    int GetEgzaminas() const {
        return egzaminas;
    }

    void SetEgzaminas(int newEgzaminas) {
        egzaminas = newEgzaminas;
    }

    double GetGalutinisBalas() const {
        return galutinisBalas;
    }

    void SetGalutinisBalas(double newGalutinisBalas) {
        galutinisBalas = newGalutinisBalas;
    }

    double GetGalutinisBalasM() const {
        return galutinisBalasM;
    }

    void SetGalutinisBalasM(double newGalutinisBalasM) {
        galutinisBalasM = newGalutinisBalasM;
    }
};

template <typename T>
double SkaiciuotiGalutiniBalaM(const T& studentas);

template <typename T>
double SkaiciuotiGalutiniBala(const T& studentas);

template <typename T>
bool SortVardas(const T& a, const T& b);

template <typename T>
int NamuDarbuSk(const string& pav);


void klaida(int &a);

int klaida1(int a);


void klaida2(int &a);


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
