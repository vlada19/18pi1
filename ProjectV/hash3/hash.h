#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Hash
{
public:
    int sumFiles=0;
    string hashFile;
    char mode;
    wchar_t folderPath[75];
    wchar_t folderPath_1[75];
    int folderPathLen;
    void readingFiles(string* files);
    void checkFiles(string* files);
};

#endif // HASH_H
