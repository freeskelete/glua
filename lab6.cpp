#include <iostream>
#include <fstream>
#include <windows.h>

const int N_max = 100;
const int GL_Ru = 21;
const int Sogl_Ru = 43;
const int Alph = 65;
const int Symb = 7;
void main()
{
	setlocale(0, "RU");
	
	char Alfavit[Alph] = "абвгдеёжзийклмнопрстуфхцчшщьъэюя";
	char Symbols[Symb] = ".,:;!?";
	char gl_ru[GL_Ru] = "ауоиэыяюеё";
	char sogl_ru[Sogl_Ru] = "бвгджзйклмнпрстфхцчшщ";
	int cnt = 0;
	char str[N_max] = "ёолаырорашииыв;'./";
	int len_string = 0;
	while (str[len_string] != '\0') {
		len_string++;
	}

	for (int i = 0; i < len_string; i++) {
		for (int j = 0; j < GL_Ru; j++) {
			if (str[i] == 'ё') {
				str[i] = 'Ё';
				break;
			}
			if (str[i] == gl_ru[j]) {
				str[i] = char(str[i] - 32);
				break;
			}
		}
	}

	for (int i = 0; i < N_max; i++) {
		std::cout << str[i];
	}
	std::cout << "\n";

	std::cout << "\nAlfavit\n\n";
	for (int i = 0; i < 32; i++) {
		std::cout << Alfavit[i] << "->" << int(unsigned char(Alfavit[i])) << "\n";
		if (Alfavit[i] == 0)
			break;
	}
	for (int i = 0; i < 32; i++) {
		if (Alfavit[i] == 'ё') {
			std::cout << 'Ё' << "->" << int(unsigned char('Ё')) << "\n";
			continue;
		}
		std::cout << char(Alfavit[i] - 32) << "->" << int(unsigned char(Alfavit[i] - 32)) << "\n";
		if (Alfavit[i] == 0)
			break;
	}
	std::cout << "\nSymbols\n\n";
	for (int i = 0; i < Symb - 1; i++) {
		std::cout << Symbols[i] << "->" << int(unsigned char(Symbols[i])) << "\n";
	}

	

	std::ifstream text("text.txt");
	std::ifstream inp("input.txt");
	std::string array_word[10];
	int cnt_word = 0;
	char alpha;
	int N;
	inp >> N >> alpha;

	while (!text.eof()) {
		std::string word;
		text >> word;
		int start_pos = -1, end_pos = -1;

		bool flag = true;
		for (int i = 0; i < word.length(); i++){
			if (start_pos == -1 && isalpha((unsigned char)word[i])){
				flag = false;
				start_pos = i;
			}
			if (start_pos != -1 && (isalpha((unsigned char)word[i]))){
				end_pos = i;
			}
		}

		std::string new_str_for_word;
		for (int i = start_pos; i <= end_pos; i++){
			new_str_for_word += tolower(word[i]);
		}
		word = new_str_for_word;
		flag = true;
		if (not(word[end_pos] == alpha)) {
			flag = false;
		}

		if (flag){
			for (short i = 0; i < 10; i++){
				if (word == array_word[i]){
					flag = false;
					break;
				}
			}
		}

		if (flag){
			int min_len_str = INT_MAX, min_index_str;
			if (cnt_word < N && cnt_word != 10){
				array_word[cnt_word] = word;
				cnt_word++;
			}
			else{
				for (int i = 0; i < cnt_word; i++){
					if (min_len_str > array_word[i].length()){
						min_len_str = array_word[i].length();
						min_index_str = i;
					}
				}
				if (min_len_str < word.length())
					array_word[min_index_str] = word;
			}
		}
	}


	std::ofstream result("result.txt");
	for (short i = 0; i < cnt_word; i++){
		for (short j = i + 1; j < cnt_word; j++){
			if (array_word[i].length() < array_word[j].length())
				std::swap(array_word[i], array_word[j]);
		}
	}

	//ввод подходящих слов
	for (int i = 0; i < cnt_word; i++){
		result << array_word[i] << " ";
	}
	//вывод этих слов
	std::cout << "\n";
	for (int i = 0; i < cnt_word; i++)
		std::cout << "<" << array_word[i] << ">" << "\n";

}


/*
// 1 Доп.
#include <iostream>
#include <fstream>
using namespace std;
void main()
{
	setlocale(0, "");
	bool flag;
	string out;
	cout << "(0)кодировка (любое другое число)декодировка" << endl;
	cin >> flag;
	if (flag)
	{	//Декодировка
		ifstream cod("cod.txt");
		while (!cod.eof())
		{
			string word;
			short cnt = 0;
			cod >> word;
			if (flag)
				flag = false;
			else out += " ";
			for (char c : word)//for (int j = 0; j < word.length(); j++)
			{
				if (isdigit(c))
					cnt++;
				else
					for (int i = 0, ii = cnt - 1; i < cnt; i++, ii--)
						for (int count = (int(word[i]) - 48) * pow(10, ii); count > 0; count--)
							out += c;
			}
		}
	}
	else
	{	//Кодировка
		ifstream cod("cod.txt");
		while (!cod.eof())
		{
			string word;
			cod >> word;
			int cnt = 0;
			for (char alfa : word)	//while (word[cnt] != '\0') cnt++;
				cnt++;
			if (flag)
				out += " ";
			else flag = true;
			string ch;
			while (cnt)
			{
				ch += char(cnt % 10) + 48;
				cnt /= 10;
			}
			for (int i = 0, j = ch.length() - 1; i < ch.length() / 2; i++, j--)
			{
				swap(ch[i], ch[j]);
			}
			out += ch;
			out += word[0];
		}

	}
	ofstream cod1("cod.txt");
	cod1 << out;
}



// 2 Доп.
#include <iostream>
#include <fstream>
using namespace std;
void main(){
	setlocale(0, "");
	ifstream text("Text.txt");
	string out;
	while (!text.eof()){
		string word;
		text >> word;
		int l = word.length();
		for (int c = 0; c < l; c++){
			if (tolower(word[c]) == tolower(word[c + 1])){
				word[c] = char(toupper(word[c]));
				word[c + 1] = char(toupper(word[c + 1]));
				word+= '('; word+= word[c]; word+= word[c]; word+= ')';
			}
		}
		out += word; out += ' ';
	}
	ofstream Text("Text.txt"); Text << out;
}
*/
