#include <fstream>
#include <iostream>
#include <regex>
#include "SList.h"

using namespace std;

int main()
{
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
	}

	s2.DisPlayWords();
	return 0;
}

