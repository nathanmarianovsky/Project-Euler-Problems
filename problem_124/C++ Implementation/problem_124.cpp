#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


//Class to hold all the information needed for a divisor of some number
class Divisor {
	public:
		Divisor(int _base, int _power) : base(_base), power(_power) {}
		int getBase() { return this->base; }
		int getPower() { return this->power; }
		void changePower(int newPower) { this->power = newPower; }
	private:
		int base;
		int power;
};


//Class to hold the value n, rad(n), and all the divisors of n
class Number {
	public:
		Number(int num) : value(num) {
			this->rad = 1;
			int k = 2;
			while(true) {
				if(num == 1) {
					Divisor trivial(1, 1);
					this->divisors.push_back(trivial);
					break;
				}
				if(num % k == 0) {
					size_t l = 0;
					for(; l < this->divisors.size(); l++) {
						if(this->divisors[l].getBase() == k) {
							this->divisors[l].changePower((this->divisors[l].getPower()) + 1);
							break;
						}
					}
					if(l == this->divisors.size()) {
						Divisor tmp(k, 1);
						this->divisors.push_back(tmp);
					}
					num /= k;
					k = 2;
				}
				else {
					k++;
				}
			}
			for(size_t i = 0; i < this->divisors.size(); i++) {
				this->rad *= this->divisors[i].getBase();
			}
		}
		int getValue() { return this->value; }
		int getRad() { return this->rad; }
	private:
		vector<Divisor> divisors;
		int value;
		int rad;
};


/*
A comparison function to determine whether lhs < rhs. 
First we check against values of rad(n) then by n.
This is a comparison operator designed specifically to 
sort the list the way the problems wants it to be organized.
*/
bool comparison(Number lhs, Number rhs) {
	if(lhs.getRad() < rhs.getRad()) { return true; }
	else if(lhs.getRad() == rhs.getRad()) {
		if(lhs.getValue() < rhs.getValue()) { return true; }
		else { return false; }
	}
	else { return false; }
}


//Generates the unsorted list
void generateList(int N, vector<Number> &list) {
	for(int i = 1; i <= N; i++) {
		Number tmp(i);
		list.push_back(tmp);
	}
}


//Sorts the list of generated numbers
void organizeList(vector<Number> &list) {
	sort(list.begin(), list.end(), comparison);
}


//Checks whether or not a given string is an integer or not
bool is_number(const string &s) {
	string::const_iterator it = s.begin();
	while(it != s.end() && isdigit(*it)) {
		++it;
	}
	return (!s.empty()) && (it == s.end());
}


//Asks the user for the input on what value N should be and makes sure that N is an integer
int findN() {
	int N = 0;
	string tmp;
	cout << "This code will find any element produced in the rad(k) sorted list. What would you like the value of N to be where N is the size of the list?" << endl;
	cin >> tmp;
	while(!(is_number(tmp)) || (stoi(tmp) == 0)) {
		cout << "Please choose an integer value such that N > 0!" << endl;
		tmp = "";
		cin >> tmp;
	}
	N = stoi(tmp);
	return N;
}


//Asks the user for an input position, k, and evaluates E(k) 
void findElement(vector<Number> list) {
	int position = 0;
	string tmp;
	cout << "What position would you like to access from the sorted list noting the fact that the first position is given by the value 1?" << endl;
	cin >> tmp;
	while(!(is_number(tmp))) {
		cout << "Please choose an integer value!" << endl;
		tmp = "";
		cin >> tmp;
	}
	position = stoi(tmp);
	cout << "The element located at the " << position << "th position in the sorted list is: " << list[position-1].getValue() << endl;
}


int main() {
	int N = 0;
	vector<Number> list;
	N = findN();
	generateList(N, list);
	organizeList(list);
	findElement(list);
	return 0;
}
