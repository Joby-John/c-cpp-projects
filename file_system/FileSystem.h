#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class FileSystem {
public:
    void listFiles(const string& directory);
    void readFile(const string& filename);
    void writeFile(const string& filename, const string& content);
    void deleteFile(const string& filename);
    void createFile(const string& filename);

private:
    vector<string> getFilesInDirectory(const string& directory);
};

#endif // FILESYSTEM_H
