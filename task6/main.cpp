#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {
    ofstream outFile("grades.txt");
    if (!outFile) {
        cout << "Error creating grades.txt!" << endl;
        return 1;
    }
    outFile << 85 << endl;
    outFile << 90 << endl;
    outFile << 75 << endl;
    outFile << 60 << endl;
    outFile << 95 << endl;
    outFile.close();

    ifstream inFile("grades.txt");
    if (!inFile) {
        cout << "Unable to open grades.txt!" << endl;
        return 1;
    }

    int grade;
    cout << "Current grades in file:" << endl;
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();

    int gradeToDelete;
    cout << "\nEnter the grade you want to delete: ";
    cin >> gradeToDelete;

    ifstream readGrades("grades.txt");
    ofstream tempFile("temp.txt");

    if (!readGrades || !tempFile) {
        cout << "Error opening files for update!" << endl;
        return 1;
    }

    bool found = false;
    while (readGrades >> grade) {
        if (grade == gradeToDelete) {
            found = true;
            continue;
        }
        tempFile << grade << endl;
    }

    readGrades.close();
    tempFile.close();

    if (remove("grades.txt") != 0) {
        cout << "Error deleting original file!" << endl;
    } else if (rename("temp.txt", "grades.txt") != 0) {
        cout << "Error renaming temporary file!" << endl;
    } else {
        if (found) {
            cout << "Grade deleted and file updated successfully!" << endl;
        } else {
            cout << "Grade not found, file remains unchanged." << endl;
        }
    }

    return 0;
}
