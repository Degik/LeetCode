#include <iostream>
#include <string>

using namespace std;


string caesarCipher(string s, int k) {
    int len = s.length();
    string result = "";
    for(int i = 0; i < len; i++){
        if(isalpha(s[i]) != 0){ // if != 0 is alphabet
            int number = s[i] + k;
            if(isupper(s[i]) == 0){ // if !=0 is upper
                // [97, 122] the interval for upper alpha
                cout << "(" << char(s[i]) <<  ")" << "Lower: ";
                int diff = 122 - 97 + 1;
                while (number > 122){
                    cout << number << endl;
                    // goes back
                    number -= diff;
                }
            } else {
                // [65, 90]
                cout << "(" << char(s[i]) <<  ")" << "Upper: ";
                int diff = 90 - 65 + 1;
                while (number > 90){
                    // goes back
                    cout << number << " ";
                    number -= diff;
                }
            }
            cout << "Result: " << number << "(" << char(number) << ")" << endl;
            result += number; //
        } else {
            result += s[i];
        }
    }
    return result;
}


int main(int argc, char* argv[]){
    string s = "Pz-/aI/J`EvfthGH";
    int k = 66;
    cout << caesarCipher(s, k) << endl;
    return 0;
}