#include <iostream>

using namespace std;


void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    while(n % 3 != 0 && n > 3){
        n -= 2;
        cnt++;
    }
    if(n % 3 == 0){
        cnt += n / 3;
        n = 0;
    }
    while(n > 0){
        if(n == 1){
            cnt = 2;
            break;
        }
        n -= 2;
        cnt++;
    }
    
    cout << cnt << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}