#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    vector<ll> p_pow(n);
    ll p = 5;
    p_pow[0] = 1;
    for(int i = 0; i < n; i++){
        p_pow[i] = p_pow[i - 1] * p;
    }
    // cout << "Powers of " << p << endl;
    // for(int i = 0; i < n; i++){
        // cout << p_pow[i] << ' ';
    // } 
    // cout << endl;
    ll ht = 0;
    for(int i = 0; i < t.size(); i++){
        ht += (t[i] - 'a' + 1) * p_pow[i];
    }
    // cout << "Hash for t: " << ht << endl;
    vector<ll> hs(n);
    for(int i = 0; i < n; i++){
        hs[i] = (s[i] - 96) * p_pow[i];
        if(i > 0){
            hs[i] += hs[i - 1];
        }
    }
    for(auto i : hs){
        cout << i << ' ';
    }
    for(int i = 0; i + t.size() - 1 < n; i++){
        ll cur = hs[i + t.size() - 1];
        if(i > 0){
            cur -= hs[i - 1];
        }
        if(ht * p_pow[i] == cur){
            cout << i << ' ';
        }
    }
}