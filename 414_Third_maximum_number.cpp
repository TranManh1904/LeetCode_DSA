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

void solution3(int numbers[], int n){
	int first = INT_MIN; // vd fist = -10
	int second = INT_MIN; // vd second = -10
	int third = INT_MIN; // vd third = -10
	// 2,7,6,5,7,3

	for (int i = 0; i < n; i++){
		if (numbers[i]>first){ // vd 2 > -10
			third = second; // -10 = -10  
			second = first; // luc nay first = -10 => second = -10
			first = numbers[i]; //number[i] = 2 => first = 2
		}
		else if (numbers[i] > second && numbers[i] != first){ // i = 1, numbers[1] = 7 > second(-10) && 7 != first(2)
			third = second;
			second = numbers[i];
		}
		else if (numbers[i] > third && numbers[i] != second && numbers[i] != first){
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
	cout << endl;
	cout << "solution 3: ";
	solution3(numbers, n);
	return 0;
}
