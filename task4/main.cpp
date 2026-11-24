#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cin >> name >> age;
        outFile << name << " " << age << endl;
    }
    outFile.close();

    ifstream inFile("persons.txt");
    vector<person> persons;
    person p;

    while (inFile >> p.name >> p.age) {
        persons.push_back(p);
    }
    inFile.close();

    if (!persons.empty()) {
        person younger = persons[0];
        person older = persons[0];

        for (size_t i = 1; i < persons.size(); i++) {
            if (persons[i].age < younger.age) {
                younger = persons[i];
            }
            if (persons[i].age > older.age) {
                older = persons[i];
            }
        }

        ofstream resFile("results.txt");
        resFile << "Younger: " << younger.name << " (" << younger.age << ")" << endl;
        resFile << "Older: " << older.name << " (" << older.age << ")" << endl;
        resFile.close();

        cout << "Younger: " << younger.name << " (" << younger.age << ")" << endl;
        cout << "Older: " << older.name << " (" << older.age << ")" << endl;
    }

    return 0;
}
