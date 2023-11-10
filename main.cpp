#include "mylib.h"


using namespace std;

int main() {
    //vector<Studentas> studentai;
    //IvestiDuomenis(studentai);
    int n = 10;
    int b,c;
    vector<Studentas> studentai;

    cout << "Jei norite is naujo generuoti failus, rasykite 1" << endl;
    cin >> b;
    if (b == 1){
        GeneruotiStudentus(1000, "1000.txt", n);
        GeneruotiStudentus(10000, "10000.txt", n);
        GeneruotiStudentus(100000, "100000.txt", n);
        GeneruotiStudentus(1000000, "1000000.txt", n);
        GeneruotiStudentus(10000000, "10000000.txt", n);
    }
    cout << "Pagal koki parametra norite rusiuoti? |1.Didejant | 2.Mazejant | 3.Vardas | (Rasykite tik skaiciuka)" << endl;
    cin >> c;

    auto sortingFunction = sortDidejant;
    if (c == 1){
        sortingFunction = sortDidejant;
    }
    if (c == 2){
        sortingFunction = sortMazejant;
    }
    if (c == 3){
        sortingFunction= SortVardas;
    }

    pair<vector<Studentas>, vector<Studentas>> sortedStudents = RikiuotiStudentus(studentai);

    for (int i = 1000; i <= 1000; i=i*10){
        chrono::duration<double> suma = chrono::duration<double>::zero();
        auto start = std::chrono::high_resolution_clock::now();
        FailoNuskaitymas(to_string(i) + ".txt", studentai, n);
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end-start;
        suma += diff;
        cout << i << " studentu nuskaitymas is failo: " << diff.count() << endl;

            start = std::chrono::high_resolution_clock::now();
            sort(studentai.begin(), studentai.end(), sortingFunction);
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
     }
//cout << "Studento objekto adresas Vector konteineryje: " << &studentai.back() << endl;
    return 0;
}
