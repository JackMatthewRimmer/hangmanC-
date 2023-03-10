#include <stdio.h>
#include <string>

using namespace std;

class HangManGame
{
    public:
        // constructor
        HangManGame(string gameWord);
        // getter/setters
        bool setGameWord(string gameWord);
        string getGameWord();
        bool setEveryGuess(string everyGuess);
        string getEveryGuess();
        bool setAlphabet(string alphabet);
        string getAlphabet();
        bool setLives(int no_lives);
        int getLives();
        // public methods
        bool hasWon();
        bool applyGuess(char guess);
    private:
        // private attributes
        string m_gameWord;
        string m_everyGuess;
        string m_alphabet;
        int m_lives;
        // private methods
        string initializeEveryGuess();
};