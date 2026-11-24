#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ofstream outFile("names.txt");
    outFile << "Hadeer Mahmoud" << endl;
    outFile << "Youssef Ali" << endl;
    outFile << "Ahmed Mostafa" << endl;
    outFile << "Esraa Ebrahim" << endl;
    outFile.close();

    ifstream input("names.txt");
    string line;
    vector<string> data;

    while (getline(input, line)) {
        data.push_back(line);
    }
    input.close();

    sort(data.begin(), data.end());

    cout << "Names sorted Successfully" << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }

    return 0;
}
