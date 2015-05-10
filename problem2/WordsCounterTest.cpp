#include <fstream>
#include <iostream>
#include <regex>
#include "SList.h"

using namespace std;

int main()
{

	//string str1 = "Hi";
	//string str2 = "ai";
	//string str1 = "123";
	//string str2 = "21";

	//bool r1;

	//r1 = str1 > str2;

	//cout << "result : " << r1 << endl << endl;


	//string str3 = "aaaaaaaa";
	//string str4 = "b";

	//bool r2 = str3 < str4;

	//cout << "result : " << r2 << endl << endl;

	// 총 단어 갯수
	// 같은 단어 갯수 
	// 위의 두가지를 구함

	//SList s1;

	//s1.InsertionSort("hihi");
	//s1.InsertionSort("hihi");
	//s1.InsertionSort("worlds");
	//s1.InsertionSort("jaesik");
	//s1.InsertionSort("jaesik");

	//s1.InsertToFirst("bb");
	//s1.InsertToFirst("aa");
	//s1.InsertToFirst("dd");
	//s1.InsertToFirst("cc");
	//s1.InsertToFirst("aa");

	//s1.DisPlayWords();

	//s1.test();

	//string some;
	//cin >> some;
	
	SList s2;

	ifstream file;
	file.open("test.txt");
	if (!file.is_open())
	{
		cout << "text.txt file have an error" << endl;
		exit(1);
	}

	string word;
	char chars[] = "!@#$%^&*()-_+=\|[{]}'\";:,<.>/?`~\r\n";
	while (file >> word)
	{
		//regex e("[^[:w:]]");
		//word = regex_replace(word, e, "a");
		//replace_if(word.begin(), word.end, "")

		// 단어 및 숫자를 제외한 나머지 모두 지우기
		for (int i = 0; i < strlen(chars); i++){
			word.erase(remove(word.begin(), word.end(), chars[i]), word.end());
		}
		s2.execute(word);
		//cout << word << endl;
	}

	s2.DisPlayWords();




	//char data[100];

	//// open a file in read mode.
	//ifstream infile;
	//infile.open("afile.txt");

	//cout << "Reading from the file" << endl;
	//infile >> data;

	//// write the data at the screen.
	//cout << data << endl;

	//// again read the data from the file and display it.
	//infile >> data;
	//cout << data << endl;

	//// close the opened file.
	//infile.close();

	return 0;
}

