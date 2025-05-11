#include "storageManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

StorageManager::StorageManager(string filePathIn)
{
    filePath = filePathIn;
}

StorageManager::~StorageManager()
{
    closeFile();
}

string StorageManager::convertDataToString(vector<string> data)
{
    string result = "";
    for (string i : data)
    {
        result += i + separator;
    }
    result.pop_back();
    return result;
}

vector<string> StorageManager::parseData(string data)
{
    vector<string> result;
    string temp = "";

    for (char i : data)
    {
        if (i != separator)
        {
            temp += i;
        }
        else
        {
            result.push_back(temp);
            temp = "";
        }
    }

    return result;
}

void StorageManager::openFile()
{
    file.open(filePath, ios::in | ios::out | ios::app);
    if (!file)
    {
        cout << "Error opening the file!";
    }
}


void StorageManager::closeFile()
{
    if (file.is_open())
    {
        file.close();
    }
}

template <typename T>
void StorageManager::readAll(vector<T>& objects)
{
    if (file.is_open())
    {
        file.seekg(0);
        string line;
        while(getline(file, line))
        {
            objects.emplace_back(parseData(line));
        }
        closeFile();
    }
    else
    {
        openFile();
        readAll(objects);
    }
}

template <typename T>
void StorageManager::findRecord(T& object, string id)
{
if (file.is_open())
    {
        file.seekg(0);
        string line;
        string idLenght;
        bool flag = 1;
        while(getline(file, line))
        {
            idLenght = to_string(line.find(separator)-1);
            if (idLenght == id)
            {
                for(int i = 0; i < stoi(idLenght); i++)
                {
                    if (id[i] != line[i])
                    {
                        flag = 0;
                        continue;
                    }
                }
            }
            else
            {
                flag = 0;
            }
            if(flag)
            {
                object.emplace_back(parseData(line));
            }
        }
    }
    else
    {
        openFile();
        findRecord(object, id);
    }
}

void StorageManager::createData(string data)
{
    if (file.is_open())
    {
        file << data << endl;
    }
    else
    {
        openFile();
        createData(data);
    }
}

void StorageManager::updateData(string data, string id)
{
    if (file.is_open())
    {
        file.seekg(0);
        string line;
        string idLenght;
        bool flag = 1;
        while(getline(file, line))
        {
            idLenght = to_string(line.find(separator)-1);
            if (idLenght == id)
            {
                for(int i = 0; i < stoi(idLenght); i++)
                {
                    if (id[i] != line[i])
                    {
                        flag = 0;
                        continue;
                    }
                }
            }
            else
            {
                flag = 0;
            }
            if(flag)
            {
                line = data;
            }
            file << line << endl;
        }
    }
    else
    {
        openFile();
        updateData(data, id);
    }
}


void StorageManager::deleteData(string id)
{
    if (file.is_open())
    {
        file.seekg(0);
        string line;
        string idLenght;
        bool flag = 1;
        while(getline(file, line))
        {
            idLenght = to_string(line.find(separator)-1);
            if (idLenght == id)
            {
                for(int i = 0; i < stoi(idLenght); i++)
                {
                    if (id[i] != line[i])
                    {
                        flag = 0;
                        continue;
                    }
                }
            }
            else
            {
                flag = 0;
            }
            if(!flag)
            {
                file << line << endl;
            }
        }
    }
    else
    {
        openFile();
        deleteData(id);
    }
}
