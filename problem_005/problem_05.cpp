/*
Project Euler Problem #5:
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

My Solution:
	I extended this problem to a more general approach. The code below will find the smallest positive number that is divisible
	by all of the numbers from 1 to N.

- Nathan Marianovsky
*/


#include <vector>
#include <iostream>
#include <string>
using namespace std;


//Adds the divisors 1,2,...,N to a divisors vector
void addDivisors(vector<int> &divisors, int N) {
	for(int i = 1; i <= N; i++) {
		divisors.push_back(i);
	}
}


//Finds the smallest integer such that it is divisible by all divisors 1,2,...,N
int findValue(vector<int> divisors) {
	int value = 1;
	for(size_t i = 0; i < divisors.size(); i++) {
		if(value % divisors[i] != 0) {
			value++;
			i = 0;
		}
	}
	return value;
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
	cout << "This code will find the smallest integer such that it is divisible by the numbers 1,2,...,N. What would you like the value of N to be?" << endl;
	cin >> tmp;
	while(!(is_number(tmp)) || (stoi(tmp) == 0)) {
		cout << "Please choose an integer value such that N > 0!" << endl;
		tmp = "";
		cin >> tmp;
	}
	N = stoi(tmp);
	return N;
}


int main() {
	int N = 0;
	int value = 0;
	vector<int> divisors;
	N = findN();
	addDivisors(divisors, N);
	value = findValue(divisors);
	cout << "The smallest integer such that it is divisible by all the numbers 1,2,...," << N << " is: " << value << endl;
	return 0;
}