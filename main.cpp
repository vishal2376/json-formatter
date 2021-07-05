#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void json_tree(string);

int main()
{
	string file_path;
	cout << "Enter your file path : ";
	cin >> file_path;

	json_tree(file_path);

	return 0;
}

void json_tree(string file_path)
{
	ifstream fin;
	ofstream fout;
	int tabs, tokens; //here tokens are  { } , :
	tokens = -1;
	char ch;
	fin.open(file_path.c_str());
	if (!fin)
		cout << "Failed to open file";
	else
	{
		fout.open("result.json");
		while (fin.get(ch))
		{

			if (ch == '{')
			{
				tokens++;

				//open braces tabs
				tabs = tokens;
				if (tokens > 0)
					fout << "\n";
				while (tabs)
				{
					fout << "\t";
					tabs--;
				}
				fout << ch << "\n";

				//json key:value tabs
				tabs = tokens + 1;
				while (tabs)
				{
					fout << "\t";
					tabs--;
				}
			}
			else if (ch == ':')
			{
				fout << " : ";
			}
			else if (ch == ',')
			{
				fout <<  ",\n";
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
				fout << "\n";
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
			{
				if (ch == ' ' || ch == '\n' || ch == '\t')
					continue;
				else
					fout << ch;
			}
		}
		fout.close();
	}
	fin.close();
	cout << "Formatting Done \nCheck 'result.json' file\n";
}