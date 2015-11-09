#include <iostream>
#include <string>
using namespace std;


//Checks whether or not a given string is an integer or not
bool is_number(const string &s) {
	string::const_iterator it = s.begin();
	while(it != s.end() && isdigit(*it)) {
		++it;
	}
	return (!s.empty()) && (it == s.end());
}


//Asks the user for the input on what value N should be and makes sure that N is an integer
int find_num_of_divisors() {
	int N = 0;
	string tmp;
	cout << "This code will find the first triangle number to have N divisors. What would you like N to be?" << endl;
	cin >> tmp;
	while(!(is_number(tmp)) || (stoi(tmp) == 0)) {
		cout << "Please choose an integer value such that N > 0!" << endl;
		tmp = "";
		cin >> tmp;
	}
	N = stoi(tmp);
	return N;
}


//Finds the number of divisors a given number has
int find_num_of_divisors(int num) {
	int num_of_divisors = 1;
    int exponent = 1;
    int i = 2;
    while(i <= num) {
        if(num % i == 0) {   
            exponent++; 
            num /= i;
        }
        else {
            num_of_divisors *= exponent;
            exponent = 1;
            i++;
        }
    }
    num_of_divisors *= exponent;
    return num_of_divisors;
}


//Finds the triangle number that has at least n distinct divisors
void find_num(int num_of_divisors) {
	int position = 1;
	int sum = 1;
	while(true) {
		if(find_num_of_divisors(sum) >= num_of_divisors) { break; }
		position++;
		sum += position;
	}
	cout << "The first value to have at least " << num_of_divisors << " distinct divisors is: " << sum << endl;
}


int main() {
	int num_of_divisors = 0;
	num_of_divisors = find_num_of_divisors();
	find_num(num_of_divisors);
	return 0;
}