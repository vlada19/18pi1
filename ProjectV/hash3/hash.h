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
    void readingFiles(string* files);
    void checkFiles(string* files);
};

#endif // HASH_H
