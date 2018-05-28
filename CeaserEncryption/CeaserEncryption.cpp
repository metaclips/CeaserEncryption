// CeaserEncryption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> encrypt(vector<string>,int);
int main()
{
	vector<string>words;
	vector<string>Encwrd;
	string word;
	cout << "Please enter or paste words to be encrypted Press ctrl-z to continue" << endl;
	while (cin >> word)
		words.push_back(word);
	if (cin.bad() || cin.fail())
		cin.clear();
	cout << "Enter key" << endl;
	int key;
	cin >> key;
	Encwrd = encrypt(words,key);
	cout << endl << endl;
	cout << "Encrypted word is " << endl << endl;
	for (int i = 0; i < Encwrd.size(); i++)
	{
		cout << Encwrd[i] << " ";
	}
	cout << endl;
	system("Pause");
    return 0;
}
vector<string> encrypt(vector<string> words,int key)
{
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words[i].size(); j++)
		{
			if (isalpha(words[i][j]))
			{
				if (isupper(words[i][j]))
				{
					for (int k = 0; k < key; k++)
					{
						if (words[i][j] == 'Z')
							words[i][j] = 'A';
						else
							words[i][j] = char(int(words[i][j]) + 1);
					}
				}
				else
					for (int k = 0; k < key; k++)
					{
						if (words[i][j] == 'z')
							words[i][j] = 'a';
						else
							words[i][j] = char(int(words[i][j]) + 1);
					}
			}
			else if (isdigit(words[i][j]))
			{
				for (int k = 0; k < key; k++)
				{
					if (words[i][j] == '9')
						words[i][j] = '0';
					else
						words[i][j] = int(words[i][j]) + 1;
				}
			}
			else
			{
				cout<<words[i][j]<<" Not supported yet"<<endl;
			}
		}
	}
	return words;
}

