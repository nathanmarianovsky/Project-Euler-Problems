#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


//Class for the Pythagorean triplets to hold all variables
class Pythagorean {
	public:
		Pythagorean(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
		int get_a() {return a;}
		int get_b() {return b;}
		int get_c() {return c;}
	private:
		int a;
		int b;
		int c;
};


//Checks whether a given triplet is a Pythagorean triplet
bool is_pythagorean(int a, int b, int c) {
	if((pow(a,2) + pow(b,2) == pow(c,2)) && (a > 0) && (b > 0) && (c > 0)) {return true;}
	else {return false;}
}


//Generates the Pythagorean triplets based on the reduction to a 2 variable system
void generate_pythagorean(int N, vector<Pythagorean> &list) {
	int a = 0;
	int b = 0;
	int c = 0;
	for(int n = 0; n < N; n++) {
		double m1 = (-n + sqrt(pow(n,2) + (2 * N))) / 2;
		if(floor(m1) == m1) {
			a = pow(m1,2) - pow(n,2);
			b = 2 * m1 * n;
			c = pow(m1,2) + pow(n,2);
			if(is_pythagorean(a,b,c)) {
				Pythagorean tmp(a, b, c);
				list.push_back(tmp);
			}
		}
		double m2 = (-n + sqrt(pow(n,2) - (2 * N))) / 2;
		if(floor(m2) == m2) {
			a = pow(m2,2) - pow(n,2);
			b = 2 * m2 * n;
			c = pow(m2,2) + pow(n,2);
			if(is_pythagorean(a,b,c)) {
				Pythagorean tmp(a, b, c);
				list.push_back(tmp);
			}
		}
	}
}


//Prints out all of the Pythagorean triplets that have been found to satisfy the condition
void print_pythagorean(int N, vector<Pythagorean> list) {
	cout << "Here are the Pythagorean triplets that satisfy the condition a + b + c = " << N << ":" << endl;
	if(list.size() == 0) {
		cout << "It seems there were none that could satisfy the condition" << endl;
	}
	else {
		for(size_t i = 0; i < list.size(); i++) {
			cout << "Triplet #" << i + 1 << endl;
			cout << "a = " << list[i].get_a() << "\tb = " << list[i].get_b() << "\tc = " << list[i].get_c() << "\tabc = " << list[i].get_a() * list[i].get_b() * list[i].get_c() << endl;
			cout << "\n";
		}
	}
}


int main() {
	int N = 0;
	vector<Pythagorean> list;
	cout << "This code will compute the Pythagorean triplets, a^2 + b^2 = c^2, such that a + b + c = N. What would you like N to be?" << endl;
	cin >> N;
	generate_pythagorean(N, list);
	print_pythagorean(N, list);
	return 0;
}