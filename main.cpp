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
        if (!game.applyGuess(guess))
        {
            int no_lives = game.getLives();
            game.setLives(no_lives - 1);
        }
        if(game.getLives() == 0){
            cout << "YOU LOSE!" << endl;
            return 0;
        }
    }

    cout << "YOU WIN!" << endl;

    return 0;
}

int getRandomNum()
{

}


