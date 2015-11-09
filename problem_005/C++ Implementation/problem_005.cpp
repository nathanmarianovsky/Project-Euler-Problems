#include <vector>
#include <iostream>
#include <string>
using namespace std;


//Finds the greatest common divisor of two given inputs
int GCD(int a, int b) {
    int rem = 0;
    if(b == 0) {return a;}
    if(a == 0) {return b;}
    if(b > a) {
    	a = a + b;
        b = a - b;
        a = a - b;
    }
    rem = a % b;
    while(rem > 0) {
      	a = b;
        b = rem;
        rem = a % b;
    }
    if(rem == 0) {return b;}
    else {return rem;}
}   			


//Adds the divisors 1,2,...,N to a divisors vector
void addDivisors(vector<int> &divisors, int N) {
	for(int i = 1; i <= N; i++) {
		divisors.push_back(i);
	}
}


//Finds the lowest common multiple of all the divisors
int LCM(vector<int> divisors) {
	int lcm = divisors[0] * (divisors[1]) / GCD(divisors[0], divisors[1]);
	for(size_t i = 2; i < divisors.size(); i++) {
		lcm *= (divisors[i] / (GCD(lcm, divisors[i])));
	}
	return lcm;
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
	value = LCM(divisors);
	cout << "The smallest integer such that it is divisible by all the numbers 1,2,...," << N << " is: " << value << endl;
	return 0;
}