#include "hash.h"

int main(){
    setlocale(LC_ALL,"");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Hash one;   //файл класса
    cout<<"Reading or check (r/c)? ";
    cin>>one.mode;

    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    cout<<"Enter path folder (example - c:\\Folder\\*): " << endl;
    wcin >> one.folderPath;
    one.folderPathLen = wcslen(one.folderPath);
    for(int i = 0; i < one.folderPathLen-1; i++) {
        one.folderPath_1[i] = one.folderPath[i];
    }
    hf = FindFirstFile(one.folderPath, &FindFileData);
    wofstream fout("d:\\output.txt");
    if (hf != INVALID_HANDLE_VALUE)
    {
        do
        {
            fout << one.folderPath_1 << FindFileData.cFileName << endl;
            one.sumFiles++;

        } while (FindNextFile(hf, &FindFileData) != 0);
        FindClose(hf);
    }
    fout.close();
    
    ifstream file("d:\\output.txt");
    one.sumFiles=one.sumFiles-2;
    cout << "Number of files - " << one.sumFiles << endl;

    string files[one.sumFiles];

    string buffer;
    cout << "Files: " << endl;
    for (int i = 0; i < 2; i++)
        getline(file, buffer);
    for(int i = 0; i < one.sumFiles; i++){
        getline(file, files[i]);
        cout << files[i] << endl;
    }
    cout << endl;
    file.close();

    if(one.mode == 'r'){
        cout<<"Where save hashes? (example - c:\\Folder\\hash.txt)" << endl;
        cin>>one.hashFile;
        one.readingFiles(files);
    }else if(one.mode == 'c'){
        cout<<"Where read hashes? (example - c:\\Folder\\hash.txt)" << endl;
        cin>>one.hashFile;
        one.checkFiles(files);
    }

    return 0;
}
