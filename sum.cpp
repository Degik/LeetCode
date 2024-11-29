#include <iostream>
#include <algorithm>

using namespace std;

void miniMaxSum(vector<long> arr) {
    sort(arr.begin(), arr.end());
    long sum = arr[1] + arr[2] + arr[3];
    cout << sum+arr[0] <<  " " << sum+arr[4];
}

int main(void){
    vector<long> arr = {942381765, 627450398, 954173620, 583762094, 236817490};
    miniMaxSum(arr);
}