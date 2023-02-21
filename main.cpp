#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "filehandler.h"
#include "hangman.h"

using namespace std;

int main(int argc, char* argv[])
{
    FileHandler file("wordlist.txt");
    vector<string> words = file.readFile(); 
    char guess;

    file.printFile();

    HangManGame game("programming");

    while (!game.hasWon())
    {
        cout << "Make Your Guess !" << endl;
        cout << game.getEveryGuess() << endl;
        cin >> guess;
        game.applyGuess(guess);
    }

    cout << "YOU WIN!" << endl;

    return 0;
}

int getRandomNum()
{

}


