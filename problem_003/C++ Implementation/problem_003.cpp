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
		while(true) {
			if(num == 1) {
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
	}
	int getValue() { return this->value; }
	int getNumberOfPrimes() { return divisors.size(); }
	int largest_prime() {
		int largest = divisors[0].getBase();
		for(size_t i = 1; i < divisors.size(); i++) {
			if(divisors[i].getBase() > largest) {
				largest = divisors[i].getBase();
			}
		}
		return largest;
	}
private:
	vector<Divisor> divisors;
	int value;
};


//Finds the largest prime factor of a given input N
void get_largest_prime() {
	unsigned long long N = 0;
	cout << "This code will find the largest prime factor of N. What would you like the value of N to be?" << endl;
	cin >> N;
	Number tmp(N);
	int largest = tmp.largest_prime();
	cout << "The largest prime factor of " << N << " is " << largest << endl;
}


int main() {
	get_largest_prime();
	return 0;
}