#include "mylib.h"


using namespace std;

int main() {
    //vector<Studentas> studentai;
    //IvestiDuomenis(studentai);
    //SpausdintiRezultatus(studentai);
    //vector<Studentas> studentai = GeneruotiStudentus(i, "p.txt", 10);
    //std::pair<vector<Studentas>, vector<Studentas>> sortedStudents = RikiuotiStudentus(studentai);



    for (int i = 1000; i <= 10000000; i=i*10){
        auto start = std::chrono::high_resolution_clock::now();
        vector<Studentas> studentai = GeneruotiStudentus(i, "p.txt", 10);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << i << " studentu sugeneravimas ir spausdinimas i faila: " << diff.count() << endl;
            start = std::chrono::high_resolution_clock::now();
            pair<vector<Studentas>, vector<Studentas>> sortedStudents = RikiuotiStudentus(studentai);
            vector<Studentas> genijai = sortedStudents.first;
            vector<Studentas> vargsiukai = sortedStudents.second;
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            cout << i << " studentu rusiavimas i dvi grupes: " << diff.count() << endl;
                start = std::chrono::high_resolution_clock::now();
                SpausdintiStudentus(genijai, "genijai.txt");
                end = std::chrono::high_resolution_clock::now();
                diff = end - start;
                cout << i << " geniju spausdinimas i faila: " << diff.count() << endl;
                    start = std::chrono::high_resolution_clock::now();
                    SpausdintiStudentus(vargsiukai, "vargsiukai.txt");
                    end = std::chrono::high_resolution_clock::now();
                    diff = end - start;
                    cout << i << " vargsiuku spausdinimas i faila: " << diff.count() << endl;
                    cout << endl;
    }
    return 0;
}
