// find the minimum length subarray where the sum is greater than or equal to a target. Assume all the values are positive
// Tìm mảng con có độ dài nhỏ nhất mà tổng lớn hơn hoặc bằng một mục tiêu. Giả sử tất cả các giá trị đều dương
// {2,3,1,2,4,3,0}
// give target = 7 

#include <iostream>
using namespace std;

void solution2(int numbers[], int n, int target){
    int L = 0;
    int res = INT_MAX;
    int sum  = 0;
    for(int R = 0; R < n; R++){
        sum += numbers[R];
        while (sum >= target)
        {
            res = min(res, R - L + 1);
            sum -= numbers[L];
            L++;
        }
    }
    if (res == INT_MAX) {
        cout << "No valid subarray found\n";
    } else {
        cout << "Minimum length subarray = " << res << endl;
    }

}

void solution(int numbers[], int n){ // sai rồi 
    int target = 2;
    int res = 1;
    for(int i = 0; i < n; i++){
        if(numbers[i] < target){
            int sum =  numbers[i] + numbers[i + 1];
            if(sum < target){
                int sum =  numbers[i] + numbers[i + 1] + numbers[i + 2];
                if(sum < target){
                    int sum =  numbers[i] + numbers[i + 1] + numbers[i + 2] + numbers[i+3];
                    if (sum < target)
                    {
                        int sum =  numbers[i] + numbers[i + 1] + numbers[i + 2] + numbers[i+3] + numbers[i+4];
                    }else{
                        res = 4;
                    }
                }else{
                    res = 3;
                }
            }else{
                res = 2;
        }
        }else{
            res = 1;
        }
    }
    cout << "resole: " << res;
}

int main(){
    int target = 7;
    int numbers[] = {2,3,1,2,4,3,0};
    int n = 7;
    solution(numbers, n);
    solution2(numbers, n, target);
    return 0;
}
