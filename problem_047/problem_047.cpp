/*
Project Euler Problem #47:
	The first two consecutive numbers to have two distinct prime factors are:
			14 = 2 × 7
			15 = 3 × 5
	The first three consecutive numbers to have three distinct prime factors are:
			644 = 2² × 7 × 23
			645 = 3 × 5 × 43
			646 = 2 × 17 × 19.
	Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?

My Solution:
	I extended this problem to a more general approach. The code below will find the first N consecutive integers such
	that they all have N distinct prime factors.

- Nathan Marianvosky
*/


#include <vector>
#include <iostream>
#include <string>
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
		int k = 2;
		while(true) {
			if (num == 1) {
				//Divisor trivial(1, 1);
				//this->divisors.push_back(trivial);
				break;
			}
			if(num % k == 0) {
				size_t l = 0;
				for (; l < this->divisors.size(); l++) {
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
	}
	int getValue() { return this->value; }
	int getNumberOfPrimes() { return divisors.size(); }
private:
	vector<Divisor> divisors;
	int value;
};


//Generates a list of our initial values of N consecutive integers
void generateList(int distinctPrimes, vector<Number> &list) {
	for (int i = 1; i <= distinctPrimes; i++) {
		Number tmp(i);
		list.push_back(tmp);
	}
}


//Finds the N consecutive integers such that they all have the same number of distinct prime factors
void findIntegers(vector<Number> list) {
	size_t i = 0;
	for(; i < list.size(); i++) {
		if(list[i].getNumberOfPrimes() != list.size()) {
			break;
		}
	}
	if(i == list.size()) {
		cout << "The consecutive integers which have " << list.size() << " distinct prime factors are:" << endl;
		for (size_t k = 0; k < list.size(); k++) {
			cout << list[k].getValue() << endl;
		}
	}
	else {
		while(true) {
			for(size_t j = 0; j < list.size(); j++) {
				Number tmp(list[j].getValue() + 1);
				list[j] = tmp;
			}
			i = 0;
			for(; i < list.size(); i++) {
				if(list[i].getNumberOfPrimes() != list.size()) {
					break;
				}
			}
			if(i == list.size()) {
				break;
			}
		}
		cout << "The consecutive integers which have " << list.size() << " distinct prime factors are:" << endl;
		for (size_t k = 0; k < list.size(); k++) {
			cout << list[k].getValue() << endl;
		}
	}
}


//Checks whether or not a given string is an integer or not
bool is_number(const string &s) {
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) {
		++it;
	}
	return (!s.empty()) && (it == s.end());
}


//Asks the user for the input on what value N should be and makes sure that N is an integer
int findN() {
	int N = 0;
	string tmp;
	cout << "This code will find the list of N consecutive integers such that they all have N distinct prime factors. What would you like the value of N to be?" << endl;
	cin >> tmp;
	while (!(is_number(tmp)) || (stoi(tmp) == 0)) {
		cout << "Please choose an integer value such that N > 0!" << endl;
		tmp = "";
		cin >> tmp;
	}
	N = stoi(tmp);
	return N;
}


int main() {
	int N = 0;
	vector<Number> list;
	N = findN();
	generateList(N, list);
	findIntegers(list);
	return 0;
}