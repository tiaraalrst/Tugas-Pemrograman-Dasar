#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct studentType {
    string studentFName;
    string studentLName;
    int    testScore;   // 0..100
    char   grade;
};

const int CLASS_SIZE = 20; // saat uji coba boleh ganti 5 dulu

// a) Read data
void readStudents(vector<studentType>& cls) {
    cout << "Masukkan " << CLASS_SIZE
         << " baris: FirstName LastName Score (0-100)\n" << flush;

    for (int i = 0; i < CLASS_SIZE; ++i) {
        cout << "[" << i+1 << "] ";
        if (!(cin >> cls[i].studentFName >> cls[i].studentLName >> cls[i].testScore)) {
            cerr << "\nInput berhenti/invalid. Program keluar.\n";
            exit(1);
        }
        if (cls[i].testScore < 0) cls[i].testScore = 0;
        if (cls[i].testScore > 100) cls[i].testScore = 100;
    }
}

// b) Assign grades
void assignGrades(vector<studentType>& cls) {
    for (auto& s : cls) {
        if      (s.testScore >= 90) s.grade = 'A';
        else if (s.testScore >= 80) s.grade = 'B';
        else if (s.testScore >= 70) s.grade = 'C';
        else if (s.testScore >= 60) s.grade = 'D';
        else                        s.grade = 'F';
    }
}

// c) Find highest test score
int highestScore(const vector<studentType>& cls) {
    int mx = cls[0].testScore;
    for (const auto& s : cls) if (s.testScore > mx) mx = s.testScore;
    return mx;
}

// d) Print names of students with highest score
void printTopStudents(const vector<studentType>& cls, int top) {
    cout << "Highest score = " << top << '\n';
    cout << "Student(s) with the highest score:\n";
    for (const auto& s : cls) {
        if (s.testScore == top) {
            string name = s.studentLName + ", " + s.studentFName; // Last, First
            cout << left << setw(28) << name << '\n';
        }
    }
}

// Utility: print full roster with scores and grades
void printRoster(const vector<studentType>& cls) {
    cout << left << setw(28) << "Name (Last, First)"
         << right << setw(8) << "Score"
         << setw(8) << "Grade" << '\n';
    cout << string(44, '-') << '\n';

    for (const auto& s : cls) {
        string name = s.studentLName + ", " + s.studentFName;
        cout << left  << setw(28) << name
             << right << setw(8) << s.testScore
             << setw(8) << s.grade << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<studentType> cls(CLASS_SIZE);

    readStudents(cls);
    assignGrades(cls);
    printRoster(cls);
    cout << '\n';
    int top = highestScore(cls);
    printTopStudents(cls, top);

    return 0;
}
