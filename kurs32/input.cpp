#include "input.h"
using namespace std;

bool Number(const string& str){
	for (auto c = str.begin(); c != str.end(); c++)
	{
		if (std::isdigit (*c)==0) return false;}
	return true;}

int numCheck(istream& Enter) {
	string str;
	while (1) {
		Enter >> str;
		if (Number(str)) {
			return(atoi(str.c_str()));}
		cout << "Неправильный тип данных! Нужно вводить цифры.\n";}}


