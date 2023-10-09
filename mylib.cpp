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
int NamuDarbuSk(const string& pav){
    istringstream InputStringStream(pav);
            vector<string> zodziai;
            string zodis;
            while (InputStringStream >> zodis) {
                zodziai.push_back(zodis);
                }
            int ndsk= zodziai.size()-3;
    return ndsk;
}
void klaida(int &a){
    do{
        try{
                    if (cin.fail()) {
                            throw runtime_error("Ivedete ne sveikaji skaiciu. ");
                    }
                    if (a < -2 || a > 10) {
                            throw runtime_error("Ivedete netinkamus duomenis. ");
                    }
        }
        catch (const runtime_error& e){
                    cout << e.what();
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Veskite duomenis dar karta: ";
                    cin >> a;
                }
        }
        while (cin.fail() == true || a < -2 || a > 10);
    }

    void klaida1(int &a){
    do{
        try{
                    if (cin.fail()) {
                            throw runtime_error("Ivedete ne sveikaji skaiciu. ");
                    }
                    if (a < -2 || a > 10 || a == -1) {
                            throw runtime_error("Ivedete netinkamus duomenis. ");
                    }
        }
        catch (const runtime_error& e){
                    cout << e.what();
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Veskite duomenis dar karta: ";
                    cin >> a;
                }
        }
        while (cin.fail() == true || a == -1 || a > 10 || a < -2);
    }

    void klaida2(int &a){
    do{
        try{
                    if (cin.fail()) {
                            throw runtime_error("Ivedete netinkamus duomenis. ");
                    }
                    if (a < 1 || a > 2) {
                            throw runtime_error("Ivedete netinkamus duomenis. ");
                    }
        }
        catch (const runtime_error& e){
                    cout << e.what();
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Veskite duomenis dar karta (1 arba 2): ";
                    cin >> a;
                }
        }
        while (cin.fail() == true || a < 1 || a > 2);
    }

     void klaida3(int &a){
    do{
        try{
                    if (cin.fail() || a < 0) {
                            throw runtime_error("Ivedete netinkamus duomenis. ");
                    }
        }
        catch (const runtime_error& e){
                    cout << e.what();
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Veskite duomenis dar karta: ";
                    cin >> a;
                }
        }
        while (cin.fail() == true || a < 0);
    }

    void klaida4(string &a){
    do{
        try{
                    if (a != "taip" && a != "ne" && a != "Taip" && a != "Ne" && a != "TAIP" && a != "NE") {
                            throw runtime_error("Ivedete netinkamus duomenis. ");
                    }
        }
        catch (const runtime_error& e){
                    cout << e.what();
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Veskite duomenis dar karta: ";
                    cin >> a;
                }
        }
        while (a != "taip" && a != "ne" && a != "Taip" && a != "Ne" && a != "TAIP" && a != "NE");
    }

    void klaida5(string &a){
    do{
        try{
                    if (a != "Vidurkis" && a != "VIDURKIS" && a != "vidurkis" && a != "Mediana" && a != "mediana" && a != "MEDIANA") {
                            throw runtime_error("Ivedete netinkamus duomenis. ");
                    }
        }
        catch (const runtime_error& e){
                    cout << e.what();
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Veskite duomenis dar karta: ";
                    cin >> a;
                }
        }
        while (a != "Vidurkis" && a != "VIDURKIS" && a != "vidurkis" && a != "Mediana" && a != "mediana" && a != "MEDIANA");
    }

    string GeneruotiVarda(int a) {
        return "Vardas" + to_string(a);
}
    string GeneruotiPavarde(int a) {
        return " Pavarde" + to_string(a);
}

// Funkcija, kuri sugeneruoja atsitiktinius duomenis ir iraso i faila
    void GeneruotiStudentus(int studentuSkaicius, const string& failoPavadinimas) {
        ofstream output(failoPavadinimas);
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> distribution(1, 10);
        int namuDarbuSkaicius = 10;

        output << left << setw(20) << " Vardas" << setw(20) << "  Pavarde";
        for (int p = 1; p <= namuDarbuSkaicius; p++){
            output << setw(10) << "ND" + to_string(p);
        }
        output << setw(10) << "Egz" << endl;
        for (int i = 1; i <= studentuSkaicius; ++i) {
            Studentas naujasStudentas;
            naujasStudentas.vardas = GeneruotiVarda(i);
            naujasStudentas.pavarde = GeneruotiPavarde(i);
            naujasStudentas.namuDarbai.reserve(namuDarbuSkaicius);
            for (int j = 0; j < namuDarbuSkaicius; ++j) {
                naujasStudentas.namuDarbai.push_back(distribution(mt));
            }
            naujasStudentas.egzaminas = distribution(mt);
            output << left << setw(20) << naujasStudentas.vardas << setw(20) << naujasStudentas.pavarde;
            for (const int& pazymys : naujasStudentas.namuDarbai) {
                output << setw(10) << pazymys;
            }
            output << setw(10) << naujasStudentas.egzaminas << endl;
        }
        output.close();
    }






