#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     size_t len1 = nums1.size();
    //     size_t len2 = nums2.size();
    //     size_t fusion_size = len1+len2;
    //     vector<int> fusion = vector<int>(fusion_size);
    //     merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), fusion.begin());

    //     int center = fusion_size / 2;
    //     double result;
    //     if((fusion_size % 2) == 0){
    //         return (double)(fusion[center-1] + fusion[center]) / 2;
    //         //return static_cast<double>(fusion[center-1] + fusion[center]) / 2;
    //     }
    //     else {
    //         return (double)(fusion[center]);
    //         //return static_cast<double>(fusion[center]);
    //     }
    // }

    
};

int main(){
    // Generate two sorted arrays with dim 1000
    vector<int> nums1(10000000);
    vector<int> nums2(10000000);
    for(int i=0; i<10000000; i++){
        nums1[i] = i;
        nums2[i] = i+1000;
    }
    Solution sol;
    auto start = chrono::high_resolution_clock::now();
    double result = sol.findMedianSortedArrays(nums1, nums2);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time: " << duration.count() << " milliseconds" << endl;
    cout << result << endl;
    return 0;
}
