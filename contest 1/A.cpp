#include <iostream>


using namespace std;

void solve(){
    int a,b,c,d; 
    cin >> a >> b >> c >> d;
    int sum = 0;
    if (b > a){
        sum++;
    }
    if (c > a){
        sum++;
    }
    if (d > a){
        sum++;
    }
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}