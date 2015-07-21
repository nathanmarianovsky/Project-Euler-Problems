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
	Number(unsigned long long num) : value(num) {
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
	int num_of_prime_factors() {
		int sum = 0;
		for(size_t i = 0; i < divisors.size(); i++) {
			sum += divisors[i].getPower();
		}
		return sum;
	}
private:
	vector<Divisor> divisors;
	unsigned long long value;
};


void find_comp(unsigned long long N, int p) {
	vector<Number> list;
	for(int i = 2; i < N; i++) {
		Number tmp(i);
		if(tmp.num_of_prime_factors() == p) {
			list.push_back(tmp);
		}
	}
	cout << "There are " << list.size() << " integers that have precisely two factors whole value is below " << N << endl;
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
void findN(unsigned long long &N, int &p) {
	string tmp;
	cout << "This code will find the number of integers below N who are composed of p prime factors. What would you like the value of N to be?" << endl;
	cin >> N;
	cout << "What would you like the value of p to be?" << endl;
	cin >> tmp;
	while (!(is_number(tmp)) || (stoi(tmp) == 0)) {
		cout << "Please choose an integer value such that p > 0!" << endl;
		tmp = "";
		cin >> tmp;
	}
	p = stoi(tmp);
}


int main() {
	unsigned long long N = 0;
	int p = 0;
	findN(N, p);
	find_comp(N,p);
	return 0;
}