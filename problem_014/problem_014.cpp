#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Class to hold the necessary information on any value and its collatz chain
class Collatz {
	public:
		Collatz(long _value, long _chain) : value(_value), chain(_chain) {}
		Collatz() {}
		long get_value() {return this->value;}
		long get_chain() {return this->chain;}
		void change_value(long new_value) {this->value = new_value;}
		void change_chain(long new_chain) {this->chain = new_chain;}
		Collatz operator=(Collatz tmp) {
			Collatz final;
			final.value = tmp.get_value();
			final.chain = tmp.get_chain();
			return final;
		}
	private:
		long value;
		long chain;
};


//Returns the next value in the collatz sequence
long next(long current) {
	if(current % 2 == 0) {return (current / 2);}
	else {return (current * 3) + 1;}
}


//Given a value, its corresponding collatz object is created
void find_chain(long current, Collatz &tmp) {
	long chain = 1;
	long start = current;
	while(next(start) != 1) {
		chain++;
		start = next(start);
	}
	tmp.change_value(current);
	tmp.change_chain(chain);
}


//Generates all of the collatz objects until the cap is met
void generate_list(long cap, vector<Collatz> &list) {
	long start = 1;
	while(start < cap) {
		Collatz tmp;
		find_chain(start, tmp);
		list.push_back(tmp);
		start++;
	}
}


//Returns the position that contains the longest chain
int largest_chain(vector<Collatz> list) {
	long chain = 0;
	int position = 0;
	for(size_t i = 0; i < list.size(); i++) {
		if(list[i].get_chain() > chain) {
			chain = list[i].get_chain();
			position = (int) i;
		}
	}
	return position;
}


int main() {
	long N = 0;
	int position = 0;
	vector<Collatz> list;
	cout << "This code will find the starting number under N that produces the longest chain. What would you like N to be?" << endl;
	cin >> N;
	while(N <= 1) {
		cout << "Please choose a number bigger than 1!" << endl;
		cin >> N;
	}
	generate_list(N, list);
	position = largest_chain(list);
	cout << "The number " << list[position].get_value() << " produces a Collatz chain of length " << list[position].get_chain() << " which is the biggest chain produced for all values below " << N << endl; 
	return 0;
}





