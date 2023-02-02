#include <iostream>

using namespace std;

void replace(char* str,char* word,char* word1) {
	int n = 0;
	char* p = str;
	while (p = strstr(p, word))
	{
		n++;
		p += strlen(word);
	}
	int length = strlen(str) - n * strlen(word) + n * strlen(word1) + 1;
	char* res_str = new char[length] {};

	char* p2 = str;
	while (p = strstr(p2, word)) {
		strncat_s(res_str, length, p2, strlen(p2) - strlen(p));
		strcat_s(res_str, length, word1);
		p2 = p + strlen(word);
	}
	if (strlen(p2) > 0) strcat_s(res_str, length, p2);
	puts(res_str);
}

void upper(char* str )
{
	if (str[0] > 'а' && str[0] < 'я')
	{
		str[0] = (char)((int)str[0] - 32);
	}

	for (int i = 2; str[i] != '\0'; i++)
	{
		if (str[i - 2] == '.' && str[i] > 'а' && str[i] < 'я')
		{
			str[i] = (char)((int)str[i] - 32);
		}
	}
	cout << str << endl;
}

void count(char* str)
{
	int count = 0;
	int newLine = 1;
	for (int i = int('А'); i != int('я') + 1; i++, count = 0, newLine++){
		for (int j = 0; str[j] != '\0'; j++){
			if (str[j] == (char)i){
				count++;
			}
		}
		cout << (char)i << " = " << count << "\t";
		if (i == int('\0')){
			i = int('а') - 1;
		}
		if (newLine % 7 == 0){
			cout << endl;
		}
	}
	cout << endl;
}

void number(char* str) {
	int alpha = 0, digit = 0, other = 0;
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i]))digit++;
	}
	cout << digit;
}

int main()
{
	setlocale(LC_ALL, "");
	char* str = new char[60] { "в магазине 4 товара. купили 2 товара, сколько осталось?" };
	/*Найдите и замените вхождение некоторого слова на
	заданное пользователем слово.
	char* searc = new char[10] { "товара" };
	char* repl = new char[10] { "игрушки" };
	replace(str,searc,repl);*/
	/*Изменить текст таким образом, чтобы каждое предложение начиналось с большой буквы.
	upper(str); */
	/*Посчитайте сколько раз каждая буква встречаетсяв тексте.
	count(str);*/
	/*Посчитайте сколько раз цифры встречаются в тексте.
	number(str);*/
}