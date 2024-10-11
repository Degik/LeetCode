#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(long int x) {
        long rev_num = 0;
        while(x != 0){
            int number = x % 10;
            if((rev_num > INT_MAX / 10)|| (rev_num < INT_MIN / 10)){
                return 0;
            }
            rev_num = number + rev_num * 10;
            x /= 10;
        }
        return rev_num;
    }
};

int main(){
    Solution sol;
    long int x = -2147483648;
    int result = sol.reverse(x);
    cout << result << endl;
    return 0;
}