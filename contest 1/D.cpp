#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


void solve(){
    string s;
    cin >> s;
    int a;
    cin >> a;
    int h = 0;
    while(a > 59){
        a = a - 60;
        h++;
    }
    int sum = 0;
    string t = s;
    stringstream s1;
    int h1;
    int m1;
    s1 << (s[0] + s[1]);
    s1 >> h1;
    h1 = h1 + h;
    stringstream s2;
    s2 << (s[3] + s[4]);
    s2 >> m1;
    m1 = m1 + a;
    stringstream s3;
    s3 << h1;
    string c1 = s3.str();
    stringstream s4;
    s4 << m1;
    string c2 = s4.str();
    s = c1 + ':' + c2;
    string d = s;
    reverse(d.begin(), d.end());
    if(s == d){
        sum++;
    }
    while(s != t){
        stringstream s1;
        int h1;
        int m1;
        s1 << (s[0] + s[1]);
        s1 >> h1;
        h1 = h1 + h;
        stringstream s2;
        s2 << (s[3] + s[4]);
        s2 >> m1;
        m1 = m1 + a;
        stringstream s3;
        s3 << h1;
        string c1 = s3.str();
        stringstream s4;
        s4 << m1;
        string c2 = s4.str();
        s = c1 + ':' + c2;
        string d = s;
        reverse(d.begin(), d.end());
        if(s == d){
            sum++;
        }        
    }
    cout << sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}