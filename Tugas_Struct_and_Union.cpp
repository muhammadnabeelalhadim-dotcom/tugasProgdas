#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan data mahasiswa
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Fungsi untuk membaca data mahasiswa
void readStudentData(studentType students[], int size) {
    cout << "Masukkan data mahasiswa:\n";
    cout << "Format: Nama_Depan Nama_Belakang Nilai\n\n";
    
    for (int i = 0; i < size; i++) {
        cout << "Mahasiswa " << (i + 1) << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
    }
}

// Fungsi untuk memberikan grade berdasarkan nilai
void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90) {
            students[i].grade = 'A';
        }
        else if (students[i].testScore >= 80) {
            students[i].grade = 'B';
        }
        else if (students[i].testScore >= 70) {
            students[i].grade = 'C';
        }
        else if (students[i].testScore >= 60) {
            students[i].grade = 'D';
        }
        else {
            students[i].grade = 'F';
        }
    }
}

// Fungsi untuk mencari nilai tertinggi
int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    
    return highest;
}

// Fungsi untuk mencetak nama mahasiswa dengan nilai tertinggi
void printHighestScorer(studentType students[], int size, int highestScore) {
    cout << "\n\nMahasiswa dengan nilai tertinggi (" << highestScore << "):\n";
    
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentLName << ", " << students[i].studentFName << endl;
        }
    }
}

// Fungsi untuk mencetak semua data mahasiswa
void printAllStudents(studentType students[], int size) {
    cout << "\n\n\n";
    cout << "DATA MAHASISWA DAN NILAI\n";
    cout << "\n";
    
    for (int i = 0; i < size; i++) {
        cout << students[i].studentLName << ", " << students[i].studentFName;
        cout << " - Nilai: " << students[i].testScore;
        cout << " - Grade: " << students[i].grade << endl;
    }
    
    
}

int main() {
    const int NUM_STUDENTS = 20;
    studentType students[NUM_STUDENTS];
    int highestScore;
    
    // Membaca data mahasiswa
    readStudentData(students, NUM_STUDENTS);
    
    // Memberikan grade ke setiap mahasiswa
    assignGrade(students, NUM_STUDENTS);
    
    // Mencetak semua data mahasiswa
    printAllStudents(students, NUM_STUDENTS);
    
    // Mencari nilai tertinggi
    highestScore = findHighestScore(students, NUM_STUDENTS);
    
    // Mencetak mahasiswa dengan nilai tertinggi
    printHighestScorer(students, NUM_STUDENTS, highestScore);
    
    return 0;
}
