#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename) {
    ofstream file(filename); // Open file in write mode (overwrites existing content)
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    
    cout << "Enter text to write to the file (end with ENTER):\n";
    string text;
    cin.ignore();
    getline(cin, text);
    
    file << text << endl;
    file.close();
    cout << "Data written successfully." << endl;
}

void appendToFile(const string& filename) {
    ofstream file(filename, ios::app); // Open file in append mode
    if (!file) {
        cout << "Error opening file for appending!" << endl;
        return;
    }
    
    cout << "Enter text to append to the file (end with ENTER):\n";
    string text;
    cin.ignore();
    getline(cin, text);
    
    file << text << endl;
    file.close();
    cout << "Data appended successfully." << endl;
}

void readFromFile(const string& filename) {
    ifstream file(filename); // Open file in read mode
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }
    
    cout << "File content:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    string filename = "data.txt";
    int choice;
    
    do {
        cout << "\nFile Handling Menu:" << endl;
        cout << "1. Write to file" << endl;
        cout << "2. Append to file" << endl;
        cout << "3. Read from file" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}