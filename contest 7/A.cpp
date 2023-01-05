#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 2; i < s.size(); i++){
        if(s[i] - 65 > 26){
            cout << "NO";
            return 0;
        }
        if(int(s[i - 2]) + int(s[i - 1]) - 130 != int(s[i]) - 65){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    // char a = 'H';
    // cout << int(a);
}