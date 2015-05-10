#include <fstream>
#include <iostream>
using namespace std;

int main()
{

//	string str1 = "Hi";
//	string str2 = "ai";
	string str1 = "123";
	string str2 = "21";

	bool r1;

	r1 = str1 > str2;

	cout << "result : " << r1 << endl << endl;


	string str3 = "aaaaaaaa";
	string str4 = "b";

	bool r2 = str3 < str4;

	cout << "result : " << r2 << endl << endl;

	// 총 단어 갯수
	// 같은 단어 갯수 
	// 위의 두가지를 구함






	char data[100];

	// open a file in read mode.
	ifstream infile;
	infile.open("afile.txt");

	cout << "Reading from the file" << endl;
	infile >> data;

	// write the data at the screen.
	cout << data << endl;

	// again read the data from the file and display it.
	infile >> data;
	cout << data << endl;

	// close the opened file.
	infile.close();

	return 0;
}