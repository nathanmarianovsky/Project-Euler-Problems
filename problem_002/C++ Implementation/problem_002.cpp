#include <iostream>
#include <string>
#include <cmath>
using namespace std;


//Computes the sum of all even Fibonacci numbers less than N
int findSum(int N) {
	int sum = 0;
	double phi = (1 + sqrt(5)) / 2;
	int F = 1;
	int iter = 1;
	while(F < N) {
		if(F % 2 == 0) {sum += F;}
		iter++;
		F = (pow(phi,iter) - pow(-phi,-iter)) / sqrt(5);
	}
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
	cout << "This code will find the sum of the even valued terms in the Fibonacci sequence whose value does not exceed N. What would you like N to be?" << endl;
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
	cout << "The sum of all even Fibonacci numbers less than " << N << " is:" << endl;
	cout << sum << endl;
}


int main() {
	int N = 0;
	int sum = 0;
	N = findN();
	sum = findSum(N);
	printSum(N, sum);
	return 0;
}
