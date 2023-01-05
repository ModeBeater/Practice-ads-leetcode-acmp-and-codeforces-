#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    reverse(arr, arr + n);
    map<int,int> mp;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if(mp[arr[i]] == 0){
            mp[arr[i]] = 1;
        }        
        else if(mp[arr[i]] == 1){
            cout << n - mp.size() << endl;
            cnt++;
            break;
        }
    }
    if(cnt == 0){
        cout << 0 << endl;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}