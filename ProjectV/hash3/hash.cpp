#include "hash.h"

void Hash::readingFiles(string* files){
    //setlocale(LC_ALL,"Russian");
    setlocale(LC_ALL,"");
    string fileData[sumFiles] = {""};
    ofstream file;
    hash<string> h;
    file.open(hashFile, ios::binary);
    if(!file.is_open()){
        cout<<"Couldn't open file!";
        exit(1);
    }
    for(int i = 0; i < sumFiles; i++){
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
    for(int i = 0; i < sumFiles; i++){
        file << files[i]<< endl << h(fileData[i])<<endl;
    }
    file.close();
    cout<<"Hashes saved"<<endl;
}

void Hash::checkFiles(string* files){
    //setlocale(LC_ALL,"Russian");
    setlocale(LC_ALL,"");
    string fileData[sumFiles] = {""};
    for(int i = 0; i < sumFiles; i++){
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
    file.open(hashFile, ios::binary);
    if(!file.is_open()){
        cout<<"Couldn't open file!";
        exit(1);
    }
    bool allRight = true;
    for(int i = 0; i < sumFiles; i++){
        string name;
        size_t val;
        while(!file.eof()){
            file >> name;
            file >> val;
            if(name == files[i]){
                if(val != h(fileData[i])){
                    allRight = false;
                    cout<<"Hashes do not match for: "<< files[i] << " : " << endl;
                    cout<<"Old hash - "<< val <<endl;
                    cout<<"New hash - "<< h(fileData[i]) <<endl <<endl;
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
