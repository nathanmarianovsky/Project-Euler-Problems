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


//Class to hold the value n and all the divisors of n
class Number {
public:
	Number(int num) : value(num) {
		int k = 2;
		while (true) {
			if (num == 1) {
				Divisor trivial(1, 1);
				divisors.push_back(trivial);
				break;
			}
			if (num % k == 0) {
				size_t l = 0;
				for (; l < this->divisors.size(); l++) {
					if (this->divisors[l].getBase() == k) {
						this->divisors[l].changePower((this->divisors[l].getPower()) + 1);
						break;
					}
				}
				if (l == this->divisors.size()) {
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
	Divisor getDivisor(int position) { return divisors[position]; }
private:
	vector<Divisor> divisors;
	int value;
};


//Finds the Nth prime number
void findElement(int position) {
	int i = 2;
	int check = 0;
	vector<Number> list;
	while (true) {
		Number tmp(i);
		if (tmp.getNumberOfPrimes() == 2) {
			for (size_t j = 0; j < tmp.getNumberOfPrimes(); j++) {
				check = 0;
				if (((tmp.getDivisor(j).getBase() == i) || (tmp.getDivisor(j).getBase() == 1)) && (tmp.getDivisor(j).getPower() == 1)) {
					check++;
				}
				else {
					break;
				}
			}
			if (check == 1) {
				list.push_back(tmp);
			}
		}
		if (list.size() == position) {
			break;
		}
		else {
			i++;
		}
	}
	cout << "The " << position << "th prime number is: " << list.back().getValue() << endl;
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
	cout << "This code will find the Nth prime number. What would you like the value of N to be?" << endl;
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
	findElement(N); 
	return 0;
}