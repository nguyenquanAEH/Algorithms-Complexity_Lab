#include <vector>
#include <iostream>
#include "Benchmark.h"
std::vector<long> divisors(long n); 
void printVector(std::vector<long> vec);
 
int main() { 
	long input;    
	std::cout << "Enter an integer:";    
	std::cin >> input;    
	Benchmark<std::chrono::nanoseconds> t;
	std::vector<long> div = divisors(input);
	std::cout << t.elapsed()<<std::endl;   
	return 0; 
}
std::vector<long> divisors(long n) { 
	std::vector<long> result;    
	for (long i = 1; i <= n; i++) { 
		if (n % i == 0) { 
			result.push_back(i); 
		} 
	}    
	return result; 
}
void printVector(std::vector<long> vec) { 
	for (long i = 0; i < vec.size(); i++) { 
		std::cout << vec[i] << " "; 
	} 
}
