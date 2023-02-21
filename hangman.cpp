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
    
    for (int i = 0; i < gameWord.length(); i++)
    {
        if (gameWord[i] == guess)
        {
            everyGuess[i] = guess;
        }
    }

    setEveryGuess(everyGuess);
    return true;
}

string HangManGame::initializeEveryGuess()
{
    string buffer;
    string gameWord = getGameWord();
    buffer.append(gameWord.length(), '.');
    return buffer;
}