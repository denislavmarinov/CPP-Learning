#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class StorageManager
{
public:
    StorageManager(string filePath);
    ~StorageManager();
    string convertDataToString(vector<string> data);
    vector<string> parseData(string data);
    template <typename T>
    void readAll(vector<T>& objects);
    template <typename T>
    void findRecord(T& object, string id);
    void createData(string data);
    void updateData(string data, string id);
    void deleteData(string id);


private:
    string filePath;
    fstream file;
    char separator = '#';
    void openFile();
    void closeFile();
};

#endif // STORAGEMANAGER_H
