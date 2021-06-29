#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void convert(string);

int main()
{
	string file_path;
	cout << "Enter your file path : ";
	cin >> file_path;

	convert(file_path);

	return 0;
}

void convert(string file_path)
{
	fstream fin, fout;
}