#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


//Computes the sum of all numbers divisible by either 3 or 5 but less than N
int findSum(int N) {
	int sum = 0;
	int k1 = floor(N/3);
	int k2 = floor(N/5);
	for(int i = 1; i < k1; i++) {sum += 3*i;}
	for(int j = 1; j < k2; j++) {
		if(5*j % 3 != 0) {
			sum += 5*j;
		}
	}
	if(k1 * 3 < N) {sum += 3*k1;}
	if(k2 * 5 < N) {sum += 5*k2;}
	return sum;
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
	sum = findSum(N);
	printSum(N, sum);
	return 0;
}