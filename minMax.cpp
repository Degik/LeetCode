#include <algorithm>
#include <iostream>

using namespace std;

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());

    int min_elem = INT32_MAX;

    for(int i = 0; i <= arr.size() - k; i++){
        int minimal = arr[i+k-1] - arr[i]; // Take max(0+5-1) = max(arr[4])
        min_elem = min(minimal, min_elem);
    }
    return  min_elem;
}


int main(void){
    // Read input file
    vector<int> arr;
    int n;
    cin >> n;
    cout << "N: " << n << endl;
    int k;
    cin >> k;
    cout << "K: " << k << endl;
    for(int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }
    // Call function
    int result = maxMin(k, arr);
    cout << "Result: " << result << endl;
}