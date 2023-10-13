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

     void IvestiDuomenis(vector<Studentas>& studentai) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(1, 10);
     int s;
        cout << "Norite pazymius suvesti ar nuskaityti juos is failo?(Rasykite 1, jei norite pazymius suvesti, ir 2, jei norite juos nuskaityti is failo)"<< endl;
        cin >> s;
        klaida2(s);
        if (s==2){
            ifstream input("2.txt");
            if (!input.is_open()) {
                cout << "Nepavyko atidaryti failo..." << endl;
            }
            else {
                string pav;
                    getline(input, pav);
                    int ndsk = NamuDarbuSk(pav);

    while (!input.eof()) {
        Studentas naujasStudentas;
        input >> naujasStudentas.vardas >> naujasStudentas.pavarde;
        for(int i = 1; i <= ndsk; i++){
            int nd;
            input >> nd;
            naujasStudentas.namuDarbai.push_back(nd);
        }
        input >> naujasStudentas.egzaminas;

        naujasStudentas.galutinisBalas = SkaiciuotiGalutiniBala(naujasStudentas);
        naujasStudentas.galutinisBalasM = SkaiciuotiGalutiniBalaM(naujasStudentas);
        studentai.push_back(naujasStudentas);

            }

            input.close();
            sort(studentai.begin(), studentai.end(), SortVardas);

            ofstream output("4rez.txt");
            output << "\nGalutiniai rezultatai:\n";
            output << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis balas(vid.)" << setw(20) << "Galutinis balas(med.)" << endl;
            output << "----------------------------------------------------------------------------" << endl;
            for (const Studentas& studentas : studentai) {
                output << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << fixed << setprecision(2) << setw(25) <<
                    studentas.galutinisBalas << setprecision(2) << setw(20) << studentas.galutinisBalasM << endl;
            }
            output.close();
        }
    }

    if (s==1){
    while (true) {
        Studentas naujasStudentas;

        cout << "Iveskite studento varda: ";
        cin >> naujasStudentas.vardas;

        cout << "Iveskite studento pavarde: ";
        cin >> naujasStudentas.pavarde;

        naujasStudentas.namuDarbai.clear();

        int nd;
        cout << "Iveskite namu darbu tarpinius rezultatus (-1, jei baigete ir -2, jei norite, kad namu darbu balai butu sugeneruoti atsitiktinai): ";
        while (true) {
            cin >> nd;
            klaida(nd);
            if (nd == -1) {
                break;
            }
            if (nd == -2){
                int n=0;
                cout << "Iveskite kiek namu darbu balu dar sugeneruoti: " << endl;
                cin >> n;
                klaida3(n);
                for (int i = 1; i <= n; i++){
                   nd = distribution(mt);
                   naujasStudentas.namuDarbai.push_back(nd);
                   cout << "(" << nd << ")" << endl;
                }
                break;
                }
            naujasStudentas.namuDarbai.push_back(nd);
        }
        cout << "Iveskite egzamino rezultata (-2, jei norite, kad ji sugeneruotu atsitiktinai): ";
        cin >> naujasStudentas.egzaminas;
        klaida1(naujasStudentas.egzaminas);
        if(naujasStudentas.egzaminas == -2){
            naujasStudentas.egzaminas = distribution(mt);
            cout << "(" << naujasStudentas.egzaminas << ")" << endl;
        }

        naujasStudentas.galutinisBalas = SkaiciuotiGalutiniBala(naujasStudentas);
        naujasStudentas.galutinisBalasM = SkaiciuotiGalutiniBalaM(naujasStudentas);

        studentai.push_back(naujasStudentas);

        cout << "Ar norite ivesti dar vieno studento duomenis? (Taip/Ne): ";
        string pasirinkimas;
        cin >> pasirinkimas;
        klaida4(pasirinkimas);
        if (pasirinkimas != "Taip" && pasirinkimas != "taip" && pasirinkimas != "TAIP") {
            break;
        }
    }
    sort(studentai.begin(), studentai.end(), SortVardas);
    }
    }


void SpausdintiRezultatus(const vector<Studentas>& studentai) {
    cout << "Norite kad isspausdintu studentu vidurkius ar medianas? (Vidurkis/Mediana): ";
    string pasirinkimas2;
    cin >> pasirinkimas2;
    klaida5(pasirinkimas2);
    cout << "\nGalutiniai rezultatai:\n";
    if (pasirinkimas2 != "Vidurkis" && pasirinkimas2 != "vidurkis"){
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis balas(med)" << endl;
        cout << "--------------------------------------------" << endl;
        for (const Studentas& studentas : studentai) {
            cout << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << fixed << setprecision(2) << setw(15) << studentas.galutinisBalasM << endl;
        }
    }
    else {
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis balas(vid)" << endl;
        cout << "--------------------------------------------" << endl;
        for (const Studentas& studentas : studentai) {
        cout << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << fixed << setprecision(2) << setw(15) << studentas.galutinisBalas << endl;
        }
    }
}

void SortStudentai(const vector<Studentas>& studentai, const string& genijuFailas, const string& vargsiukuFailas) {
        ofstream outputGenijai(genijuFailas);
        ofstream outputVargsiukai(vargsiukuFailas);

        outputGenijai << left << setw(15) << " Vardas" << setw(15) << "  Pavarde" << setw(15) << "Galutinis Balas" << endl;
        outputVargsiukai << left << setw(15) << " Vardas" << setw(15) << "  Pavarde" << setw(15) << "Galutinis Balas" << endl;

        for (const Studentas& studentas : studentai) {
            if (studentas.galutinisBalas >= 5.0) {
                outputGenijai << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15) << studentas.galutinisBalas << endl;
        }   else {
                outputVargsiukai << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15) << studentas.galutinisBalas << endl;
            }
        }
        outputGenijai.close();
        outputVargsiukai.close();
}

    string GeneruotiVarda(int a) {
        return "Vardas" + to_string(a);
}
    string GeneruotiPavarde(int a) {
        return " Pavarde" + to_string(a);
}

   vector<Studentas> GeneruotiStudentus(int studentuSkaicius, const string& failoPavadinimas, int namuDarbuSkaicius) {
        vector<Studentas> studentai;
        ofstream output(failoPavadinimas);
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> distribution(1, 10);

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
            naujasStudentas.galutinisBalas = SkaiciuotiGalutiniBala(naujasStudentas);
            studentai.push_back(naujasStudentas);
            output << left << setw(20) << naujasStudentas.vardas << setw(20) << naujasStudentas.pavarde;
            for (const int& pazymys : naujasStudentas.namuDarbai) {
                output << setw(10) << pazymys;
            }
            output << setw(10) << naujasStudentas.egzaminas << endl;
        }
        output.close();
    return studentai;
    }














