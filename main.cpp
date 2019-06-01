#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void readingFiles(string hashes, string* files, int number){
    string fileData[number] = {""};
    ofstream file;
    hash<string> h;
    file.open(hashes, ios::binary);
    if(!file.is_open()){
        cout<<"Couldn't open file!";
        exit(1);
    }
    for(int i = 0; i < number; i++){
        string line;
        ifstream t;
        t.open(files[i], ios::binary);
        if(!t.is_open()){
            cout<<"Couldn't open file!";
            exit(1);
        }
        while(!t.eof()){
            getline(t, line);
            fileData[i] += line;
        }
        t.close();
    }
    for(int i = 0; i < number; i++){
        file << files[i]<<endl << h(fileData[i])<<endl;
    }
    file.close();
}

void checkFiles(string hashes, string* files, int number){
    string fileData[number] = {""};
    for(int i = 0; i < number; i++){
        string line;
        ifstream t;
        t.open(files[i], ios::binary);
        if(!t.is_open()){
            cout<<"Couldn't open file!";
            exit(1);
        }
        while(!t.eof()){
            getline(t, line);
            fileData[i] += line;
        }
        t.close();
    }

    hash<string> h;
    ifstream file;
    file.open(hashes, ios::binary);
    if(!file.is_open()){
        cout<<"Couldn't open file!";
        exit(1);
    }
    bool allRight = true;
    for(int i = 0; i < number; i++){
        string name;
        size_t val;
        while(!file.eof()){
            file >> name;
            file >> val;
            if(name == files[i]){
                if(val != h(fileData[i])){
                    allRight = false;
                    cout<<"Hashes do not match "<< files[i]<<endl;
                }
                file.clear();
                file.seekg(0);
                break;
            }
        }
    }
    if(allRight){
        cout<<"All hashes match!"<<endl;
    }
    file.close();
}

int main(){
    string hashFile;
    char mode;
    int sumFiles;
    cout<<"Reading or check (r/c)? ";
    cin>>mode;
    cout<<"How many files will be? ";
    cin>>sumFiles;
    cout<<"Enter file names: ";
    string files[sumFiles];
    for(int i = 0; i < sumFiles; i++){
        cin>>files[i];
    }

    if(mode == 'r'){
        cout<<"Where save hashes? ";
        cin>>hashFile;
        readingFiles(hashFile, files, sumFiles);
    }else if(mode == 'c'){
        cout<<"Where read hashes? ";
        cin>>hashFile;
        checkFiles(hashFile, files, sumFiles);
    }

    return 0;
}
