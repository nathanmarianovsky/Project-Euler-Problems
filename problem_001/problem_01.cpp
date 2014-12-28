/*
Project Euler Problem #1:
	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	Find the sum of all the multiples of 3 or 5 below 1000.

My Solution:
	I extended this problem to a more general approach. The code below will find the sum of all the multiples of 3 or 5 below N.

- Nathan Marianvosky
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


//Find all natural numbers below N that are divisible by 3 or 5
void findElements(vector<int> &array, int N) {
	for(size_t i = 0; i < N; i++) {
		if((remainder(i, 3) == 0) || (remainder(i, 5) == 0)) {
			array.push_back(i);
		}
	}
}


//Computes the sum of all numbers divisible by either 3 or 5 but less than N
int findSum(vector<int> &array) {
	int sum = 0;
	if(array.size() == 0) {
		return sum;
	}
	else {
		for(size_t i = 0; i < array.size(); i++) {
			sum += array[i];
		}
	return sum;
	}
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
	cout << "This code will find the sum of all the multiples of 3 or 5 below N. What would you like N to be?" << endl;
	cin >> tmp;
	while(!(is_number(tmp)) || (stoi(tmp) == 0)) {
		cout << "Please choose an integer value such that N > 0!" << endl;
		tmp = "";
		cin >> tmp;
	}
	N = stoi(tmp);
	return N;
}


//Print out the sum
void printSum(int N, int sum) {
	cout << "The sum of all integers less than " << N << " and divisible by either 3 or 5 is:" << endl;
	cout << sum << endl;
}


int main() {
	int N = 0;
	int sum = 0;
	vector<int> array;
	N = findN();
	findElements(array, N);
	sum = findSum(array);
	printSum(N, sum);
	return 0;
}