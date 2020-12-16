#include "day13.hpp"

using namespace std; 

int main(int a, char** b) { 
    cout << "#1: " << day13::solve1(); 
    return 0; 
} 

namespace day13 {

vector<int> num;
vector<int> rem;

void setup() {
	num = vector<int>{17, 41, 37, 367, 19, 23, 29, 613, 13};
	rem = vector<int>{0, 7, 11, 17, 36, 40, 46, 48, 61};
}

int solve1() {
	return find_min(num, rem);
}
  
long find_min(vector<long> num, vector<long> rem) {
	long total_product = 1; 
	for (uint i = 0; i < num.size(); i++) {
		total_product *= num[i]; 
	}
	long sum = 0;
	long j, part_product;
	for (uint i = 0; i < num.size(); i++) { 
		part_product = total_product / num[i]; 
		for (j = 0; (j * part_product) % num[i] != rem[i] % num[i]; j++) { }
		sum += j * part_product;
	} 
	return abs(sum % total_product - total_product);
} 

}  // namespace day13
