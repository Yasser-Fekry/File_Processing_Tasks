#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void findAndReplace(const string &filename, const string &oldWord, const string &newWord)
{
	ifstream inFile;
	inFile.open(filename, ios::in);

	if (!inFile)
	{
		cerr << "Error opening file!" << endl;
		return;
	}

	inFile.unsetf(ios::skipws);
	string content;
	char ch;
	while (inFile.get(ch))
	{
		content += ch;
	}
	inFile.close();

	//--------------------------------

	size_t pos = 0;
	while ((pos = content.find(oldWord, pos)) != string::npos)
	{
		content.replace(pos, oldWord.length(), newWord);
		pos += newWord.length();
	}

	//-----------------------------

	ofstream outFile;
	outFile.open(filename, ios::out);
	if (!outFile)
	{
		cerr << "Error writing to file!" << endl;
		return;
	}

	outFile << content;
	outFile.close();

	cout << "Replacement done successfully!" << endl;
}

int main()
{
	string filename, oldWord, newWord;

	cout << "Enter file name: ";
	cin >> filename;
	cout << "Enter word to replace: ";
	cin >> oldWord;
	cout << "Enter new word: ";
	cin >> newWord;

	findAndReplace(filename, oldWord, newWord);
	return 0;
}
