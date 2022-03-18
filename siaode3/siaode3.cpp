//Дано предложение, состоящее из слов, разделенных запятой или пробелами.Найти самое длинное слово палиндром.
//Заменить слово в предложении числом, определяющим его номер среди палиндромов предложения.
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string Input() //ввод строки
{
    cout << "Enter sentence\n";
    string sent;
    getline(cin, sent);
    //cout << sent; //проверка что вводится
    return sent;
}
vector <string> Words(string sent) //разбить на слова
{
    vector <string> words;
    string buf = "";
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
    if (buf!="")
        words.push_back(buf);
    return words;
}
void Output(vector <string> word) // вывести слова
{
    for (int i = 0; i < word.size(); i++)
    {
        cout << word[i] << ' ';
    }
}
string max_Palindrom(vector <string> word, int nomer[100], int &count) // нахождение и вывод самого длинного палиндрома
{
    int maxpal = 0;
    int nomer_max = -1;
    for (int i = 0; i < word.size(); i++)
    {
        string obr = "";
        for (int j = word[i].size()-1; j >= 0; j--)
        {
            obr.push_back(word[i][j]);
        }
        //cout << obr << " " << word[i] << endl; //вывод обратных слов для проверки
        if (obr == word[i])
        {
            nomer[count] = i;
            count += 1;
            if (word[i].size() > maxpal)
            {
                maxpal = word[i].size();
                nomer_max = i;
            }
        }
    }
    if (nomer_max!=-1)
        return word[nomer_max];
    else return "[none]";
}
void Palindrome(vector <string> &word, int nomer[100], int count) //замена палиндромов на их номер
{
    for (int i = 0; i < count; i++)
    {
        word.erase(word.begin() + nomer[i]);
        word.insert(word.begin()+nomer[i], to_string(i));
        //cout << word[i] << ' ';
    }
}
int main()
{
    int nomer[100];
    int count = 0;
    vector <string> words;
    string sentence = Input();
    words = Words(sentence);
    //Output(words); //вывод разделённых слов (для проверки)
    cout << "The longest palindrome " << max_Palindrom(words, nomer, count) << endl;
    Palindrome(words, nomer, count);
    Output(words);
}