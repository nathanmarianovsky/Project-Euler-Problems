#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


//Class to hold all the pairs of the numbers such that they, their sum, and their difference are all Pentagon numbers
class PentagonPair {
	public:
		PentagonPair(int _num1, int _num2) : num1(_num1), num2(_num2), sum(_num1 + _num2), difference(abs(num1 - num2)) {}
		int getDifference() { return this->difference; }
		int getSum() { return this->sum; }
		int getNum1() { return this->num1; }
		int getNum2() { return this->num2; }
	private:
		int num1;
		int num2;
		int sum;
		int difference;
};


/*
Returns a boolean telling whether a value is a Pentagon number or not.
	Since we know: P_n = (1/2)n(3n-1)
	Solving for n gives: n = (1/6)(1 +/- sqrt(1 + 24P_n))
But since we restrict the domain to be the natural numbers, we can also restrict the inverse:
	n = (1/6)(1 + sqrt(1 + 24P_n))
Since we know that n is a natural numbers, [(1 + sqrt(1 + 24P_n)) % 6 == 0] if it is a Pentagon number.
*/
bool isPentagon(double N) {
	double tmp = 1 + sqrt(1 + (24 * N));
	if(remainder(tmp, 6) == 0) { return true; }
	else { return false; }
}


/*
First generates a list of Pentagon numbers below N.
Then checks to see which pairs have it such that they,
their sum, and their difference are all Pentagon numbers.
*/
void generatePentagonPair(int N, vector<PentagonPair> &list) {
	vector<double> candidates;
	int candidate = 0;
	int iter = 0;
	while(candidate < N) {
		iter++;
		candidate = (iter * ((3 * iter) - 1)) / 2;
		if(candidate < N) {candidates.push_back(candidate);}
	}
	for(size_t i = 0; i < candidates.size(); i++) {
		for(size_t j = 0; j < i; j++) {
			if(isPentagon(abs(candidates[i] - candidates[j])) && isPentagon(candidates[i] + candidates[j])) {
				PentagonPair tmp(candidates[i], candidates[j]);
				list.push_back(tmp);
			}
		}
	}
}


//Comparison function written to check which Pentagon Pair is "bigger". This is done by comparing the difference values.
bool comparison(PentagonPair lhs, PentagonPair rhs) {
	if(lhs.getDifference() < rhs.getDifference()) { return true; }
	else { return false; }
}


//Prints out all the candidates for Pentagon Pairs
void displayPentagonPair(vector<PentagonPair> &list) {
	sort(list.begin(), list.end(), comparison);
	cout << "The Pentagon Pair having both their difference and sum be both Pentagon numbers, as well as having the smallest difference are: ";
	cout << list[0].getNum1() << " and " << list[0].getNum2() << "\nThe sum is given as: " << list[0].getSum() << " and the difference: " << list[0].getDifference() << endl;
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
	cout << "This code will find the pair of numbers such that they, their difference, and their sum are all Pentagon numbers."
	"In order to do this, where would you like for me to cap the Pentagon sequence?" << endl;
	cin >> tmp;
	while(!(is_number(tmp)) || (stoi(tmp) < 10000000)) {
		cout << "Please choose an integer value such that N > 10000000!" << endl;
		tmp = "";
		cin >> tmp;
	}
	N = stoi(tmp);
	return N;
}


int main() {
	int N = 0;
	vector<PentagonPair> list;
	N = findN();
	generatePentagonPair(N, list);
	displayPentagonPair(list);
	return 0;
}
