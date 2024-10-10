#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int index[128] = {0};
        for(int i=0, j=0; j<n; j++){
            i = max(index[s[j]], i);
            ans = max(ans, j-i+1);
            index[s[j]] = j+1;
        }
        return ans;
    }
};

int main(){
    string s = "bbbbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}