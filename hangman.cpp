#include "hangman.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

HangManGame::HangManGame(string gameWord)
{
    setGameWord(gameWord);
    setAlphabet("abcdefghijklmnopqrstuvwxyz");
    setEveryGuess(initializeEveryGuess());
    setLives(5);
    
    return;
}

bool HangManGame::setGameWord(string gameWord)
{
    m_gameWord = gameWord;
    return true;
}

string HangManGame::getGameWord()
{
    return m_gameWord;
}

bool HangManGame::setEveryGuess(string everyGuess)
{
    m_everyGuess = everyGuess;
    return true;
}

string HangManGame::getEveryGuess()
{
    return m_everyGuess;
}

bool HangManGame::setAlphabet(string alphabet)
{
    m_alphabet = alphabet;
    return true;
}

string HangManGame::getAlphabet()
{
    return m_alphabet;
}

bool HangManGame::setLives(int no_lives)
{
    m_lives = no_lives;
    return true;
}

int HangManGame::getLives()
{
    return m_lives;
}

bool HangManGame::hasWon()
{
    string everyGuess = getEveryGuess();

    for (int i = 0; i < everyGuess.length(); i++)
    {
        if (everyGuess[i] == '.')
        {
            return false;
        }
    }

    return true;
}

bool HangManGame::applyGuess(char guess)
{
    // TODO add removing letter from alphabet
    string everyGuess = getEveryGuess();
    string gameWord = getGameWord();
    bool match = false;
    
    for (int i = 0; i < gameWord.length(); i++)
    {
        if (gameWord[i] == guess)
        {
            everyGuess[i] = guess;
            match = true;
        }
    }

    setEveryGuess(everyGuess);
    return match;
}

string HangManGame::initializeEveryGuess()
{
    string buffer;
    string gameWord = getGameWord();
    buffer.append(gameWord.length(), '.');
    return buffer;
}