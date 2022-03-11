//Дано предложение, состоящее из слов, разделенных запятой или пробелами.Найти самое длинное слово палиндром.
//Заменить слово в предложении числом, определяющим его номер среди палиндромов предложения.
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string Input() //ввод строки
{
    cout << "Enter sentence, in the end write point\n";
    string sent;
    getline(cin, sent);
    cout << sent;
    return sent;
}
vector <string> Words(string sent) //разбить на слова
{
    vector <string> words;
    string buf = "";
    int count = 0;
    for (int i = 0; i < sent.size(); i++)
    {
        if (sent[i] != ',' && sent[i] != ' ' && sent[i]!='.')
        {
            buf += sent[i];
        }
        else
        {
            words.push_back(buf);
            buf = "";
        }
    }
    return words;
}
void Output(vector <string> word) // вывести слова
{
    for (int i = 0; i < word.size(); i++)
    {
        cout << word[i] << ' ';
    }
}
string max_Palindrom(vector <string> word)
{
    int maxpal = 0;
    int nomer_max = 0;
    for (int i = 0; i < word.size(); i++)
    {
        string obr = "";
        for (int j = word[i].size(); j > 0; j--)
        {
            obr.push_back(word[i][j]);
        }
        if (obr == word[i]) 
            if (word[i].size() < maxpal)
            {
                maxpal = word[i].size();
                nomer_max = i;
            }
    }
    return word[nomer_max];
}
void Palindrome(vector <string> word)
{
    int nomer[100];
    int count = 0;
    for (int i = 0; i < word.size(); i++)
    {
        string obr = "";
        for (int j = word[i].size(); j >= 0; j--)
            obr += word[i][j];
        if (obr == word[i])
        {
            word.at(i) = i;
            cout << word[i] << ' ';
        }

    }
}
int main()
{
    vector <string> words;
    string sentence = Input();
    words = Words(sentence);
    //Output(words);
    cout << "The longest palindrome " << max_Palindrom(words) << endl;
    //Palindrome(words);
}

