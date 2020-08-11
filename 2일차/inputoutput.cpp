#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream ftxt;
	string s;
	ftxt.open("readme.txt");
	
	ftxt >> s;
	ftxt.get();

	ofstream otxt;
	string str;

	otxt.open("tmp.txt");
	cin >> str;
	otxt << str;
	otxt.close();
}