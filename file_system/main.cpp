#include "FileSystem.h"
#include "Utils.h"
#include <iostream>

using namespace std;

int main() {
    FileSystem fs;
    string directory = "./";  // Use current directory or specify another

    while (true) {
        cout << "\n--- File System Menu ---\n";
        cout << "1. View Files\n";
        cout << "2. Read a File\n";
        cout << "3. Write to a File\n";
        cout << "4. Create a File\n";
        cout << "5. Delete a File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();  // Ignore leftover newline

        switch (choice) {
            case 1:
                fs.listFiles(directory);
                break;
            case 2: {
                string filename = getInput("Enter the filename to read: ");
                fs.readFile(filename);
                break;
            }
            case 3: {
                string filename = getInput("Enter the filename to write to: ");
                string content = getInput("Enter content to write: ");
                fs.writeFile(filename, content);
                break;
            }
            case 4: {
                string filename = getInput("Enter the filename to create: ");
                fs.createFile(filename);
                break;
            }
            case 5: {
                string filename = getInput("Enter the filename to delete: ");
                fs.deleteFile(filename);
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
