#include "FileSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

// List files in the directory
void FileSystem::listFiles(const string& directory) {
    vector<string> files = getFilesInDirectory(directory);
    cout << "Files in directory " << directory << ":" << endl;
    for (const auto& file : files) {
        cout << file << endl;
    }
}

// Read a file
void FileSystem::readFile(const std::string& filename) {
    ifstream infile(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close();
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}

// Write to a file
void FileSystem::writeFile(const std::string& filename, const std::string& content) {
    ofstream outfile(filename, ios::app);
    if (outfile.is_open()) {
        outfile << content << endl;
        outfile.close();
        cout << "Content written to " << filename << endl;
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}

// Delete a file
void FileSystem::deleteFile(const std::string& filename) {
    std::wstring wFilename = std::wstring(filename.begin(), filename.end());
    if (DeleteFileW(wFilename.c_str())) {
        cout << "Deleted file " << filename << endl;
    } else {
        cerr << "Failed to delete file " << filename << endl;
    }
}

// Create a file
void FileSystem::createFile(const std::string& filename) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        cout << "Created file " << filename << endl;
        outfile.close();
    } else {
        cerr << "Failed to create file " << filename << endl;
    }
}

// Utility function to get files in a directory
vector<string> FileSystem::getFilesInDirectory(const std::string& directory) {
    vector<string> files;
    for (const auto& entry : filesystem::directory_iterator(directory)) {
        files.push_back(entry.path().string());
    }
    return files;
}
