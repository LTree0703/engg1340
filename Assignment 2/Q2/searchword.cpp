#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool word_found_in_line(string line, string word, int &total);

int SearchWord(string word, string fileName, int &nLines, int &total)
{
    ifstream file;
    string line;
    file.open(fileName);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (word_found_in_line(line, word, total))
            {
                nLines++;
            }
        }
    }
    else
    {
        return 1;
    }
    file.close();
    return 0;
}

bool word_found_in_line(string line, string word, int &total)
{
    int tmp = 0;
    for (int i = 0; i < line.length()-word.length()+1; i++)
    {
        bool wordFound = false;
        //cout << "entering loop " << word[0] << ' ' << line[i] << endl;
        if (word[0] == tolower(line[i]) && !isalpha(line[i+word.length()]) && !isalpha(line[i-1]))
        {
            wordFound = true;
            for (int j = 0; j < word.length(); j++)
            {
                //cout << "entering nested loop " << word[j] << ' ' << line[i+j] << endl;
                if (word[j] != tolower(line[i+j]))
                {
                    wordFound = false;
                    break;
                }
            }
            if (wordFound)
            {
                //cout << "true, " << line[i] << " tmp = " << tmp << endl;
                i += word.length();
                tmp++;
            }
            else
            {
                //cout << "false, tmp no change" << endl;
            }
        }
    }
    if (tmp > 0)
    {
        total += tmp;
        //cout << "total = " << total << endl;
        return true;
    }
    else
    {
        return false;
    }
}