// wtf am i doing with my life
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
void print(string s, bool top = true, bool bot = true)
{
    if (top)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else cout << "|";
    bool f = true;
    for (int i = s.length(); i < 33; i++)
    {
        if (f)
        {
            s = " " + s;
        }
        else s = s + " ";
        f = !f;
    }
    cout << s;
    if (bot)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else cout << "|" << endl;
}
void draw(int guess = 0)
{
    if (guess >= 1)
    {
        print("|", false, false);
    }
    else
    {
        print(" ", false, false);
    }
    if (guess >= 2)
    {
        print("|", false, false);
    }
    else
    {
        print(" ", false, false);
    }
    if (guess >= 3)
    {
        print("O", false, false);
    }
    else
    {
        print(" ", false, false);
    }
    if (guess == 4)
    {
        print("/  ", false, false);
    }
    if (guess == 5)
    {
        print("/| ", false, false);
    }
    if (guess >= 6)
    {
        print("/|\\", false, false);
    }
    else
    {
        print(" ", false, false);
    }
    if (guess >= 7)
    {
        print("|", false, false);
    }
    else
    {
        print(" ", false, false);
    }
    if (guess == 8)
    {
        print("/  ", false, false);
    }
    if (guess >= 9)
    {
        print("/ \\", false, false);
    }
    else print(" ", false, false);
}
void printlet(string s, char from, char to)
{
    string nvm;
    for (int i = from; i <= to; i++)
    {
        if (s.find(i) == string::npos)
        {
            nvm += i;
            nvm += " ";
        }
        else nvm += "  ";
    }
    print(nvm, false, false);
}
void printav(string s)
{
    printlet(s, 'A', 'M');
    printlet(s, 'N', 'Z');
}
bool check(string word, string guessed)
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    print(s, false);
    return won;
}
string loadrand(string s)
{
    int cnt = 0;
    string word;
    vector<string>v;
    ifstream read(s);
    if (read.is_open())
    {
        while (getline(read, word))
        {
            v.push_back(word);
        }
        int x = rand() % v.size();
        word = v[x];
        read.close();
    }
    return word;
}
int triesleft(string s, string guessed)
{
    int x = 0;
    for (int i = 0; i < guessed.size(); i++)
    {
        if (s.find(guessed[i]) == string::npos)
        {
            x++;
        }
    }
    return x;
}
int main()
{
    srand(time(0));
    string guess, word;
    word = loadrand("words.txt");
    cout << word << endl << endl;;
    int tries = 0;
    bool win = false;
    do
    {
        system("cls");
        print("Hang Man");
        draw(tries);
        print("Available Letters");
        printav(guess);
        print("Guess The Word");
        win = check(word, guess);
        if (win) break;
        char x;
        cout << "Enter the letter please : ";
        cin >> x;
        if (guess.find(x) == string::npos)
        {
            guess += x;
        }
        tries = triesleft(word, guess);
    } while (tries < 10);
    if (win)
    {
        print("YOU WON");
    }
    else
    {
        print("YOU LOST");
        print("Word :", true, false);
        print(word, false, true);
    }
    return 0;
}