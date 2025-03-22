#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Algorithm XOR Decrypt
string xorEncryptDecrypt(const string &text, char key)
{
	string result = text;
	for (size_t i = 0; i < text.size(); ++i)
	{
		result[i] = text[i] ^ key;
	}
	return result;
}

int main()
{
	int choice;
	char key = 'K';
	cout << "1. Encrypt text and print it\n";
	cout << "2. Decrypt text from a file\n";
	cout << "Choose an option: ";
	cin >> choice;
	cin.ignore(); // نتجاهل ال space

	if (choice == 1)
	{
		string userInput;
		cout << "Enter the text: ";
		getline(cin, userInput); // cin ده ال input stream
		string encryptedText = xorEncryptDecrypt(userInput, key);
		cout << "#########################################" << endl;
		cout << "Encrypted text: " << encryptedText << endl;
		ofstream outFile("encrypted.txt"); // outfile variable
		if (outFile.is_open())
		{
			outFile << encryptedText;
			outFile.close();
			cout << "Encrypted text saved to encrypted.txt\n";
		}
	}

	else if (choice == 2)
	{
		ifstream inFile("encrypted.txt");
		if (inFile.is_open())
		{
			string encryptedText;
			getline(inFile, encryptedText);
			inFile.close();
			string decryptedText = xorEncryptDecrypt(encryptedText, key);
			cout << "Decrypted text: " << decryptedText << endl;

			// Save decrypted text to a file
			ofstream outFile("decrypted.txt");
			if (outFile.is_open())
			{
				outFile << decryptedText;
				outFile.close();
				cout << "Decrypted text saved to decrypted.txt\n";
			}
		}
	}
	return 0;
}
