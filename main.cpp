#include "mylib.h"


using namespace std;

int main() {
    //vector<Studentas> studentai;
    //IvestiDuomenis(studentai);
    //SpausdintiRezultatus(studentai);
    int n = 10;
    int test = 5;
    vector<Studentas> studentai;

    /*GeneruotiStudentus(1000, "1000.txt", n);
    GeneruotiStudentus(10000, "10000.txt", n);
    GeneruotiStudentus(100000, "100000.txt", n);
    GeneruotiStudentus(1000000, "1000000.txt", n);
    GeneruotiStudentus(10000000, "10000000.txt", n);*/

    //std::pair<vector<Studentas>, vector<Studentas>> sortedStudents = RikiuotiStudentus(studentai);

    // 1000 irasu testu (5) vidurkis = 0.0320345
    // 10000 irasu testu (5) vidurkis = 0.308776
    // 100000 irasu testu (5) vidurkis = 2.84911
    // 1000000 irasu testu (5) vidurkis = 32.4168
    // 10000000 irasu testu (5) vidurkis = 161.129




    for (int i = 1000; i <= 10000000; i=i*10){
        //chrono::duration<double> suma1 = chrono::duration<double>::zero();
        //chrono::duration<double> vidurkis = chrono::duration<double>::zero();
    //for (int j = 1; j <= test; j++){

        chrono::duration<double> suma = chrono::duration<double>::zero();
        auto start = std::chrono::high_resolution_clock::now();
        FailoNuskaitymas(to_string(i) + ".txt", studentai, n);
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end-start;
        suma += diff;
        cout << i << " studentu sugeneravimas ir spausdinimas i faila: " << diff.count() << endl;

            start = std::chrono::high_resolution_clock::now();
            sort(studentai.begin(), studentai.end(), sortDidejant); //SortVardas, sortDidejant, sortMazejant
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            suma = suma + diff;
            cout << i << " studentu rusiavimas pagal parametra: " << diff.count() << endl;

                start = std::chrono::high_resolution_clock::now();
                pair<vector<Studentas>, vector<Studentas>> sortedStudents = RikiuotiStudentus(studentai);
                vector<Studentas> genijai = sortedStudents.first;
                vector<Studentas> vargsiukai = sortedStudents.second;
                end = std::chrono::high_resolution_clock::now();
                diff = end - start;
                suma = suma + diff;
                cout << i << " studentu rusiavimas i dvi grupes: " << diff.count() << endl;

                    start = std::chrono::high_resolution_clock::now();
                    SpausdintiStudentus(genijai, "genijai.txt");
                    end = std::chrono::high_resolution_clock::now();
                    diff = end - start;
                    suma = suma + diff;
                    cout << i << " geniju spausdinimas i faila: " << diff.count() << endl;

                        start = std::chrono::high_resolution_clock::now();
                        SpausdintiStudentus(vargsiukai, "vargsiukai.txt");
                        end = std::chrono::high_resolution_clock::now();
                        diff = end - start;
                        suma = suma + diff;
                        cout << i << " vargsiuku spausdinimas i faila: " << diff.count() << endl;
                        cout << endl;

        cout << i << " irasu testo laikas: " << suma.count() << endl;
        cout << endl;
        //suma1 += suma;
     }
    //vidurkis = suma1 / test;
    //cout << i << " irasu testo laiku vidurkis: " << vidurkis.count() << endl;
    //cout << endl;
   // }


    return 0;
}

