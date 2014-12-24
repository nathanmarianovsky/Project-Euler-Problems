/*
Project Euler Problem #1:
	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	Find the sum of all the multiples of 3 or 5 below 1000.
My Solution:
	Find the sum of all the multiples of 3 or 5 below some input N.
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


//Find all natural numbers below N that are divisible by 3 or 5
void findElements(vector<int> &array, int N) {
	if(N > 0) {
		for(size_t i = 0; i < N; i++) {
			if((remainder(i, 3) == 0) || (remainder(i, 5) == 0)) {
				array.push_back(i);
			}
		}
	}
	else {
		cout << "N has to be a positive integer!" << endl;
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


//Ask for the value of N
int findN() {
	int N = 0;
	cout << "What would you like the value of N to be?" << endl;
	cin >> N;
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