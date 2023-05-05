#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int SearchWord(string word, string fileName, int &nLines, int &total)
{
    ifstream fin(fileName);
    string line;
    if (fin.fail())
    {
        return 1;
    }
    while (getline(fin, line))
    {
        int count = 0;
        istringstream iss(line);
        string w;
        bool wordFound = false; 
        while (iss >> w)
        {
            if (w.size() != word.size())
                continue;
            wordFound = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (tolower(w[i]) != tolower(word[i]))
                {
                    wordFound = false;
                    break;
                }
            }
            if (wordFound)
                count++;
        }
        if (count > 0)
        {
            nLines++;
            total += count;
        }
    }
    return 0;
}
