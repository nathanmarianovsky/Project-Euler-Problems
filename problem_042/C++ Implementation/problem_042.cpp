#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


//Class for each letter to hold the actual letter and its corresponding numerical value
class Letter {
	public:
		Letter(char _letter, int _value) : value(_value), letter(_letter) {}
		int get_value() {return value;}
		char get_letter() {return letter;}
	private:
		int value;
		char letter;
};


//Check if a given number is a triangle number
bool is_triangle(int t) {
	double rem = 0;
	double n = (-1 + sqrt(1 + (8 * t))) / 2;
	if(modf(n, &rem) == 0) {return true;}
	else {return false;}
}


//Generate all of the English letters and their corresponding numerical values
void generate_characters(vector<Letter> &list) {
	Letter A('A',1);
	list.push_back(A);
	Letter B('B',2);
	list.push_back(B);
	Letter C('C',3);
	list.push_back(C);
	Letter D('D',4);
	list.push_back(D);
	Letter E('E',5);
	list.push_back(E);
	Letter F('F',6);
	list.push_back(F);
	Letter G('G',7);
	list.push_back(G);
	Letter H('H',8);
	list.push_back(H);
	Letter I('I',9);
	list.push_back(I);
	Letter J('J',10);
	list.push_back(J);
	Letter K('K',11);
	list.push_back(K);
	Letter L('L',12);
	list.push_back(L);
	Letter M('M',13);
	list.push_back(M);
	Letter N('N',14);
	list.push_back(N);
	Letter O('O',15);
	list.push_back(O);
	Letter P('P',16);
	list.push_back(P);
	Letter Q('Q',17);
	list.push_back(Q);
	Letter R('R',18);
	list.push_back(R);
	Letter S('S',19);
	list.push_back(S);
	Letter T('T',20);
	list.push_back(T);
	Letter U('U',21);
	list.push_back(U);
	Letter V('V',22);
	list.push_back(V);
	Letter W('W',23);
	list.push_back(W);
	Letter X('X',24);
	list.push_back(X);
	Letter Y('Y',25);
	list.push_back(Y);
	Letter Z('Z',26);
	list.push_back(Z);
}


//Read all of the words from the text file and add them to the list
void read_file(vector<string> &list) {
	ifstream file("words.txt");
	while(file) {
		string s;
		if(!getline(file, s)) {break;}
		istringstream ss(s);
		while(ss) {
			string t;
			if(!getline(ss, t, ',')) {break;}
			t.erase(t.begin());
			t.erase(t.end() - 1);
			list.push_back(t);
		}
	}
}


//Check the list obtained from the text file to see how many words are triangle words
int count_triangle_words(vector<string> list, vector<Letter> characters) {
	int sum = 0;
	for(size_t i = 0; i < list.size(); i++) {
		int candidate = 0;
		for(size_t j = 0; j < list[i].size(); j++) {
			for(int k = 0; k < characters.size(); k++) {
				if(list[i][j] == characters[k].get_letter()) {
					candidate += characters[k].get_value();
					break;
				}
			}
		}
		if(is_triangle(candidate)) {sum++;}
	}
	return sum;
}


int main() {
	int count = 0;
	vector<string> list;
	vector<Letter> characters;
	generate_characters(characters);
	read_file(list);
	count = count_triangle_words(list, characters);
	cout << "There are " << count << " words in this text file that are triangle words!" << endl;
	return 0;
}