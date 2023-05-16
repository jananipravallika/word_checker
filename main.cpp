
// the usual includes the io library and the string library and the map library and the unordered map library

#include <iostream>
#include <fstream>
#include <string>
#include <map>			 // for the bst
#include <unordered_map> // for the hash table

#include <chrono>

using namespace std;

map<string, string> read_file_as_table(char *file_name)
{
	if (file_name[2] == NULL)
	{
		return map<string, string>();
	}
	fstream file(file_name);

	if (!file)
	{
		cout << "File not found" << endl;
		exit(EXIT_FAILURE);
	}

	map<string, string> table;
	string data;

	while (file >> data && !file.eof())
	{
		table[data] = data;
	}
	{
		table[data] = data;
	}
	return table;
}

unordered_map<string, string> read_file_as_bst(char *file_name)
{
	if (file_name[2] == NULL)
	{
		return unordered_map<string, string>();
	}
	fstream file(file_name);

	if (!file)
	{
		cout << "File not found" << endl;
		exit(EXIT_FAILURE);
	}

	unordered_map<string, string> table;
	string data;

	while (file >> data && !file.eof())
	{
		table[data] = data;
	}
	{
		table[data] = data;
	}
	return table;
}

int main()
{
	try
	{
		string word;
		char *file_name = new char[20];
		int choice = 0;

		cout << "Enter the file name: " << endl;

		cin >> file_name;
		
		auto startTime = chrono::high_resolution_clock::now();
		auto endTime = chrono::high_resolution_clock::now();
		fstream file(file_name, ios::in);

		if (!file)
		{
			cout << "File not found" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Enter the word name to search: " << endl;

		cin >> word;

		cout << "Select which data structure you want to use: " << endl;

		cout << "1. Binary Search Tree" << endl;
		cout << "2. Hash Table" << endl;

		cin >> choice;
		// the choice is hash table
		if (choice == 2)
		{
			unordered_map<string, string> table = read_file_as_bst(file_name);
			startTime = chrono::high_resolution_clock::now();
			if (table.find(word) != table.end())
			{
				cout << "Word found" << endl;
			}
			else
			{
				cout << "Word not found" << endl;
			}
			endTime = chrono::high_resolution_clock::now();
		}
		// the choice is bst
		else if (choice == 1)
		{
			map<string, string> table = read_file_as_table(file_name);
			// if the word is found in the table
			startTime = chrono::high_resolution_clock::now();
			if (table.find(word) != table.end())
			{
				cout << "Word found" << endl;
			}
			else
			{
				cout << "Word not found" << endl;
			}
			endTime = chrono::high_resolution_clock::now();
		}
		else
		{
			cout << "Invalid choice" << endl;
		}

		auto timeElapsed = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
		cout << "Time Taken : " << timeElapsed.count() << " microseconds" << endl;
		delete[] file_name;
	}
	catch (exception e)
	{
		cout << "Error : " << e.what() << endl;
	}

	return 0;
}
