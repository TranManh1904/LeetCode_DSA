// find the length of the longest subarray with the same value in each position
// vd : arr = 7 3 3 3 2 2 2 2 
#include <iostream>
using namespace std;

void solution(int numbers[], int n){
    int res = 1; // same value (do dai cua mang con)
    int count = 1; // dem do dai 
    for(int i = 1; i < n ; i++){
        if(numbers[i] == numbers[i - 1]){ // i(1) = 3 ; i(0) = 7 
            count++;
        }else{
            count = 1;
        }

        if (res < count){
            res = count; // update lai res
        }
    }
    cout << "same value : " << res ;
}

int main(){
    int numbers[] = {7, 3, 3, 3, 2, 2, 2, 2};
    int n = 8;
    solution(numbers, n);
    return 0;
} 