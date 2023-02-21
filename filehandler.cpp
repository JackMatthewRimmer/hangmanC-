#include "filehandler.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

FileHandler::FileHandler(string filePath)
{
    if (FileHandler::setFilePath(filePath))
    {
        return;
    }
    else
    {
        cout << "ERROR: Couldnt set file path" << endl;
        return;
    }
}

bool FileHandler::setFilePath(string filePath)
{
    m_filePath = filePath;
    return true;
}

string FileHandler::getFilePath()
{
    return m_filePath;
}

vector<string> FileHandler::readFile()
{
    fstream WordList;
    vector<string> words;
    string buffer;

    WordList.open(getFilePath(), ios::in);

    if (!WordList)
    {
        cout << "ERROR: when opening file" << endl;
    }

    while(!WordList.eof())
    {
        WordList>>buffer;
        words.push_back(buffer);
    }

    return words;
}

bool FileHandler::printFile()
{
    vector<string> words = readFile(); 

    for (string w : words)
    {
        cout << w << endl;
    }
    return true;
}