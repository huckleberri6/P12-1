
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool readFromFile(string fileName);

void pressEnterToContinue()
{
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

int main() {
	string datafile;
	cout << "input file: ";
	getline(cin, datafile);
	bool status = readFromFile(datafile); // deleted CSV to test part 1
	if (status) cout << "Success!\n";
	else cout << "failure. :-(\n";
	pressEnterToContinue();
}

bool readFromFile(string filename)
{
	ifstream inFile;
	string line;
	string letter;
	int numWords = 0;
	int numCharacters = 0;

	inFile.open(filename);
	if (inFile.fail())
	{
		cout << "read error - sorry\n";
		return false;
	}

	while (true)
	{
		getline(inFile, line);
		if (inFile.fail())
		{
			break;
		}

		for (int i = 0; i < line.length(); i++)
		{
			letter = line.substr(i, 1);
			if (letter == " ")
			{
				numWords++;
				while (letter == " " && i < line.length())
				{
					i++;
					letter = line.substr(i, 1);
				}
				numCharacters++;
			}
			else if (letter == "." && i == line.length() - 1)
			{
				numCharacters++;
				numWords++;
			}
			else if (i == line.length() - 1)
			{
				numCharacters++;
				numWords++;
			}
			else
				numCharacters++;
		}
	}

	cout << "Words:      " << numWords << endl;;
	cout << "Characters: " << numCharacters << endl;
	inFile.close();
	return true;
}