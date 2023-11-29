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
	/*
	char Alphabet[Alph] = "абвгдеёжзийклмнопрстуфхцчшщьъэюя";
	char Symbols[Symb] = ".,:;!?";
	char gl_ru[GL_Ru] = "ауоиэыяюеё";
	char sogl_ru[Sogl_Ru] = "бвгджзйклмнпрстфхцчшщ";
	int cnt = 0;

	char str[N_max] = "ёолаырорашииыв;'./";


	for (int i = 0; i < N_max; i++) {
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

	std::cout << "\nAlphabet\n\n";
	for (int i = 0; i < 32; i++) {
		std::cout << Alphabet[i] << "->" << int(unsigned char(Alphabet[i])) << "\n";
		if (Alphabet[i] == 0)
			break;
	}
	for (int i = 0; i < 32; i++) {
		if (Alphabet[i] == 'ё') {
			std::cout << 'Ё' << "->" << int(unsigned char('Ё')) << "\n";
			continue;
		}
		std::cout << char(Alphabet[i] - 32) << "->" << int(unsigned char(Alphabet[i] - 32)) << "\n";
		if (Alphabet[i] == 0)
			break;
	}
	std::cout << "\nSymbols\n\n";
	for (int i = 0; i < Symb - 1; i++) {
		std::cout << Symbols[i] << "->" << int(unsigned char(Symbols[i])) << "\n";
	}
	*/

	
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

