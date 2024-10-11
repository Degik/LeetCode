#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        size_t len_string = s.length();
        char *str = new char[len_string+1];
        // Each block has distance (N*2)-2
        int pos = 0;
        // Create the lines
        for (int r = 0; r < numRows; r++){
            int current_pos = r;
            bool first = true;
            // Iterate over all the line and stop when there is not more char
            while(current_pos < len_string) {
                // First line element
                if(first){
                    if(checkStackSafe(current_pos, len_string)){
                        str[pos] = s[current_pos];
                        pos++;
                        first = false;
                    } else {
                        break;
                    }
                }
                // Continue the line
                int jump = r == numRows-1 ? distance(numRows, 0) : distance(numRows, r);
                current_pos += jump;
                //If is the first or the last row
                //We need to put only one element in case
                if (checkStackSafe(current_pos, len_string)){
                    if(r == 0 || r == numRows - 1){ // Only one element
                        str[pos] = s[current_pos];
                        pos++;
                    }else{                          // Two element
                        str[pos] = s[current_pos];
                        pos++;
                        // Second position
                        int r_t = abs(r - numRows) - 1;
                        jump = distance(numRows, r_t);
                        current_pos += jump;
                        if (checkStackSafe(current_pos, len_string)){
                            str[pos] = s[current_pos];
                            pos++;
                        } else {
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
        }
        str[pos] = '\0';
        string result(str);
        delete[] str;
        return result;
    }
private:
    /*
      f(R) = {(N*2) - 2 - 2R} 
    */
    int distance(int n_rows, int row){
        return (n_rows*2) - 2 - 2*row;
    }

    bool checkStackSafe(int new_pos, size_t len){
        return new_pos < len ? true : false;
    }
};


int main(){
    string s = "PAYPALISHIRING";
    int numRows = 2;
    Solution sol;
    cout << sol.convert(s, numRows) << endl;
    return 0;
}