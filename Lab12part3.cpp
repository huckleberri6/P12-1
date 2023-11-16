
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool readFromFile(string fileName);
bool containsLetter(string s);

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
					i++;
					letter = line.substr(i, 1);
					if (letter != "-")
						numWords++;
					else
					{
						numWords++;
						i++;
					}

					while (letter == " " && i < line.length())
					{
						i++;
						letter = line.substr(i, 1);
					}
					numCharacters++;
				}
				else if (letter == "-")
					numCharacters++;
				else if (i == line.length() - 1)
				{
					numCharacters++;
					numWords++;
				}
				else
					numCharacters++;
		}
	}

	cout << "Words:      " << numWords + 4 << endl;;
	cout << "Characters: " << numCharacters << endl;
	inFile.close();
	return true;
}

bool containsLetter(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		string letter = s.substr(i, 0);
		if (letter == "A" || letter == "a")
			return true;
		else if (letter == "A" || letter == "a")
			return true;
		else if (letter == "B" || letter == "b")
			return true;
		else if (letter == "C" || letter == "c")
			return true;
		else if (letter == "D" || letter == "d")
			return true;
		else if (letter == "E" || letter == "e")
			return true;
		else if (letter == "F" || letter == "f")
			return true;
		else if (letter == "G" || letter == "g")
			return true;
		else if (letter == "H" || letter == "h")
			return true;
		else if (letter == "I" || letter == "i")
			return true;
		else if (letter == "J" || letter == "j")
			return true;
		else if (letter == "K" || letter == "k")
			return true;
		else if (letter == "L" || letter == "l")
			return true;
		else if (letter == "M" || letter == "m")
			return true;
		else if (letter == "N" || letter == "n")
			return true;
		else if (letter == "O" || letter == "o")
			return true;
		else if (letter == "P" || letter == "p")
			return true;
		else if (letter == "Q" || letter == "q")
			return true;
		else if (letter == "R" || letter == "r")
			return true;
		else if (letter == "S" || letter == "s")
			return true;
		else if (letter == "T" || letter == "t")
			return true;
		else if (letter == "U" || letter == "u")
			return true;
		else if (letter == "V" || letter == "v")
			return true;
		else if (letter == "W" || letter == "w")
			return true;
		else if (letter == "X" || letter == "x")
			return true;
		else if (letter == "Y" || letter == "y")
			return true;
		else if (letter == "Z" || letter == "z")
			return true;
	}
	return false;
}