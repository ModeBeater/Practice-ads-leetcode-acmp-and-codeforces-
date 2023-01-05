#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[11];
int i = 1;
 
void solve(){
    int n;
    cin >> n;
    double a = n / 2;
    int d = ceil(a);
    int ans = 0;
    int b = 0;
    v[i].push_back(ans);
    v[i].push_back(1);
    if(n == 1){
        i++;
        return;
    }
    while(ans < n){
        // cout << a << endl;
        ans = n / d;
        floor(ans);
        if(ans != b){
            v[i].push_back(ans);
        }
        a = a / 2;
        d = ceil(a);
        if(d == 0){
            break;
        }
        // cout << d << endl;
        b = ans;
    }
    i++;
}
 
 
int main(){
    int t;
    cin >> t;
    int m = t;
    while(t--){
        solve();
    }
    for(int k = 1; k <= m; k++){
        cout << v[k].size() << endl;
        sort(v[k].begin(), v[k].end());
        for(int j = 0; j < v[k].size(); j++){
            cout << v[k][j] << " ";
        }
        cout << endl;
    }
}