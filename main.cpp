#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// void json_tree(string);
void json_tree();

int main()
{
	// string file_path;
	// cout << "Enter your file path : ";
	// cin >> file_path;

	// json_tree(file_path);
	json_tree();


	return 0;
}

// void json_tree(string file_path)
void json_tree()
{
	cout << "Enter inside function";
	ifstream fin;
	ofstream fout;
	int tabs, tokens; //here tokens are  { } , :
	tokens = -1;
	char ch;
	cout << "open function";
	fin.open("sample.json");
	if (!fin)
		cout << "Failed to open file";
	else
	{
		cout << "open file";
		fout.open("result.txt");
		while (fin.get(ch))
		{

			if (ch == '{')
			{
				tokens++;
				tabs = tokens;
				while (tabs)
				{
					fout << "\t";
					tabs--;
				}

				fout << ch << "\n";
				tabs = tokens + 1;

				while (tabs)
				{
					fout << "\t";
					tabs--;
				}
			}
			else if (ch == '}')
			{
				tabs = tokens;
				while (tabs)
				{
					fout << "\t";
					tabs--;
				}

				fout << ch << "\n";
				tokens--;
				tabs = tokens + 1;

				while (tabs)
				{
					fout << "\t";
					tabs--;
				}
			}
			else
				fout << ch;
		}
		fout.close();
	}
	fin.close();
	cout << "Complete";
}