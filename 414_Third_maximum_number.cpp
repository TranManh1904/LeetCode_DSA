// 414. Third Maximum number
// vd: Array, numbers[] = {8,4,6,2,7,5} => third maximum number
#include <iostream>
using namespace std;

void solution1(int numbers[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n;j++){
			if(numbers[i] > numbers[j]){
				swap(numbers[i], numbers[j]);
			}
		}
	}
	
	cout << "sort: ";
	for(int i = 0; i < n; i++){
		cout << numbers[i] << " ";
	}
	int distinct = 1; // 
	int firstNumber = numbers[n-1];
	for(int i = n-2; i > 0; i--){
		if(firstNumber != numbers[i]){
			distinct++;
			firstNumber = numbers[i];
		}
		if(distinct == 3){
			cout << endl;
			cout << "third maximum number " << firstNumber;
			return;
		}
	}
	cout << endl;
	cout << "chuong trinh khong du gia tri :" << numbers[n-1];
}


void solution2(int numbers[], int n){
	int first = numbers[0];
	for(int i = 0; i < n; i++){
		if(first < numbers[i]){
			first = numbers[i];
		}
	}
	int second = INT_MIN;
	for(int i = 0; i < n; i++){
		if(second < numbers[i] && numbers[i] != first){
			second = numbers[i];
		}
	}
	int third = INT_MIN;
	for(int i = 0; i < n; i++){
		if(third < numbers[i] && numbers[i] != first && numbers[i] != second){
			third = numbers[i];
		}
	}
	cout << endl;
	cout << "first: " << first;
	cout << endl;
	cout << "second: " << second;
	cout << endl;
	cout << "third number: " << third;
}


int main(){
	int numbers[] = {2,7,6,5,7,3};
	int n = 6;
	solution1(numbers, n);
	solution2(numbers, n);
}
