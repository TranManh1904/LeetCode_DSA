// 217 contains duplicate 
#include <iostream>
#include <unordered_set>

using namespace std;

bool solution1(int nums[], int n);
void solution2(int nums[], int n);
bool solution3(int nums[], int n);

int main(){
	int nums[] = {1,4,3,2,4,5};
	int n = 6;
	if (solution1(nums, n) == true){
		cout << "true";
	}else{
		cout << "false";
	}
	
	cout << endl;
	solution2(nums, n);
	
	cout << endl;
	cout << "solution 3: use set => ";
	if(solution3(nums, n) == true){
		cout << "true";
	}else{
		cout << "false";
	}
		return 0;
}	

bool solution1(int nums[], int n) {
	for(int i = 0; i < n -1; i++){
		for (int j = i + 1; j < n; j++){
			if(nums[i] == nums[j]){
				return true;
			}
		}
	}
	return false;
	
	solution2(nums, n); 
}

void solution2(int nums[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(nums[i] > nums[j]){
				swap(nums[i], nums[j]);
			}
		}
	}
	cout << "sort: ";
	for (int i = 0; i < n ; i ++){
		cout << nums[i] << " ";
	}
	
	cout << endl;
	
	bool Duplicate = false;
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
			if(nums[i] == nums[j]){
				Duplicate = true;
			}
		}
	}
	if(Duplicate == true){
		cout << "true";
	}else{
		cout << "false";
	}
}

bool solution3(int nums[], int n){
	unordered_set<int> seen; // luu các phan tu da duy qua
	for (int i = 0; i < n; i++){
		if(seen.find(nums[i]) != seen.end()){
			return true;
		}
		seen.insert(nums[i]);
	}
}
