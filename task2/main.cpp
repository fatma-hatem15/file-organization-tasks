#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("fruit.txt");
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();

    ofstream writeFile("fruit.txt", ios::app);
    writeFile << "Fresh Fruits" << endl;
    writeFile.close();

    cout << "Fresh Fruits" << endl;

    return 0;
}
