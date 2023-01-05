#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    string t = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            t += "0";
        }
        else if(s[i] == '-' && s[i + 1] != '-'){
            t += "1";
            i += 1;
        }
        else if(s[i] == '-' && s[i + 1] == '-'){
            t += "2";
            i += 1;
        }
    }
    cout << t;
}