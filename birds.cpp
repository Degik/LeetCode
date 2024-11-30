#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(vector<int> arr) {
    map<int, int> numbers;
    int max_value = 0;
    int max_count = 0;
    for(int i = 0; i < arr.size(); i++){
        int curr = arr[i];
        if(numbers.find(curr) == numbers.end()){ // Not found!
            numbers.insert({curr, 1});
        } else {
            int curr_count = numbers[curr]++;
            if(max_value != curr && curr_count > max_count){
                max_count = curr_count;
                max_value = curr;
            } else if (curr_count == max_count){
                max_value = min(max_value, curr);
            } else if(max_value == curr){
                max_count++;
            }
        }
    }
    return max_value;
}

int main(void){
    freopen("input/birds.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << migratoryBirds(arr) << endl;;
    return 0;
}