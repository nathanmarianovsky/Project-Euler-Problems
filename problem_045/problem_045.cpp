#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


//Check if a given number is a triangle numbers
bool is_triangle(long t) {
	double tmp = -1 + sqrt(1 + (8 * t));
	return (remainder(tmp, 2) == 0);
}


//Check if a given number is a pentagon number
bool is_pentagon(long p) {
	double tmp = 1 + sqrt(1 + (24 * p));
	return (remainder(tmp, 6) == 0);
}


//Check if a given number is a hexagonal number
bool is_hexagon(long h) {
	double tmp = 1 + sqrt(1 + (8 * h));
	return (remainder(tmp, 4) == 0);
}


//Finds the value that satisfies being a triangle, hexagon, and pentagon number simultaneously
long find_value(long index) {
	long current = 2;
	vector<long> list;
	while(true) {
		if(is_triangle(current) && is_hexagon(current) && is_pentagon(current)) {
			list.push_back(current);
			cout << current << endl;
		}
		if(list.size() == index) {
			return list.back();
		}
		current++;
	}
}


int main() {
	long N = 0;
	long value = 0;
	cout << "This code will find the Nth number that is simultaneously a triangle, pentagon, and hexagon number. What would you like N to be?" << endl;
	cin >> N;
	value = find_value(N);
	cout << "The " << N << "th number is " << value << endl;
	return 0;
}