/*
Project Euler Problem #6:
	The sum of the squares of the first ten natural numbers is: (1^2) + (2^2) + ... + (10^2) = 385
	The square of the sum of the first ten natural numbers is: (1 + 2 + ... + 10)^2 = 55^2 = 3025
	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

My Solution:
	I extended this problem to a more general approach. The code below will find the difference between the sum of the squares
	and the square of the sum of the first N natural numbers.

	Luckily enough we do not have to iterate through a loop to find the sums. The formulas for a given N are given as:
		\sum_{i=1}^N i = (N(N+1))/2
		\sum_{i=1}^N i^2 = (N(N+1)(2N+1))/6

- Nathan Marianovsky
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


//Finds the sum of the squares of the first N natural numbers
int find_sum_of_squares(int N) {
	return (N * (N + 1) * ((2 * N) + 1)) / 6;
}


//Finds the square of the sum of the first N natural numbers
int find_square_of_sum(int N) {
	return pow((N * (N + 1)) / 2, 2);
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
	cout << "This code will find the difference between the sum of the squares and the square of the sum of the first N natural numbers."
	"What would you like the value of N to be?" << endl;
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
	int sum_of_squares = 0;
	int square_of_sum = 0;
	N = findN();
	sum_of_squares = find_sum_of_squares(N);
	square_of_sum = find_square_of_sum(N);
	cout << "The difference between the square of the sum and the sum of the squares for the first " << N << " natural numbers is:" << abs(sum_of_squares - square_of_sum) << endl;
	return 0;
}