#include <iostream>
#include <cmath>
#include <string>
using namespace std;


//Finds the difference between the square of the sum and the sum of the squares of the first N natural numbers
int find_difference(int N) {
	return (pow(N,4) / 4) + (pow(N,3) / 6) - (pow(N,2) / 4) - (N / 6);
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
	N = findN();
	cout << "The difference between the square of the sum and the sum of the squares for the first " << N << " natural numbers is: " << find_difference(N) << endl;
	return 0;
}