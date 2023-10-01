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

int main() {
    vector<Studentas> studentai;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(1, 10);
     int s;
        cout << "Norite pazymius suvesti ar nuskaityti juos is failo?(Rasykite 1, jei norite pazymius suvesti, ir 2, jei norite juos nuskaityti is failo)"<< endl;
        cin >> s;
        klaida2(s);
        if (s==2){
            ifstream input("kursiokai1.txt");
            if (!input.is_open()) {
                cout << "Nepavyko atidaryti failo..." << endl;
            }
            else {
                    string pav;
                    getline(input, pav);
                    int ndsk = NamuDarbuSk(pav);
                    Studentas naujasStudentas;

    while (input >> naujasStudentas.vardas >> naujasStudentas.pavarde) {
        int nd;
        for(int i = 1; i <= ndsk; i++){
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
        cout << "\nGalutiniai rezultatai:\n";
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(25) << "Galutinis balas(vid.)" << setw(20) << "Galutinis balas(med.)" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        for (const Studentas& studentas : studentai) {
            cout << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << fixed << setprecision(2) << setw(25) <<
             studentas.galutinisBalas <<setprecision(2) << setw(20) << studentas.galutinisBalasM << endl;
        }
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
    };

    return 0;
}

