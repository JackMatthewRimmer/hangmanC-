#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileHandler
{
    public:
        // constructor
        FileHandler(string filePath);
        // getters/setters
        bool setFilePath(string filePath);
        string getFilePath();
        // public methods
        vector<string> readFile();
        bool printFile();
    private:
        // private attributes
        string m_filePath;
};