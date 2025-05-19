// C++ program to find k largest elements in an 
// array using sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kLargest(vector<int> &arr, int k) {
  
    // sort the given array in descending order
    sort(arr.begin(), arr.end(), greater<int>());
	
  	// store the first k element in result array
    vector<int> res(arr.begin(), arr.begin() + k);
  	return res;
}

int main() {
    vector<int>arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
 
    vector<int> res = kLargest(arr, k);
  	for(int ele : res)
      	cout << ele << " ";
  
  	return 0;
}