#include <iostream>
#include <deque>


using namespace std;

void solve(){
    int n,s;
    int sum = 0;
    int cnt = 0;
    cin >> n >> s;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        cin >> dq[i];
        sum += dq[i];
    }
    while(sum != s || !dq.empty()){
        if(dq[0] == 1){
            dq.pop_front();
            cnt++;
            sum--;
            n--;
        }
        else if(dq[n - 1] == 1){
            dq.pop_back();
            cnt++;
            sum--;
            n--;
        }
        else{
            dq.pop_back();
            cnt--;
            n--;
        }
        if(sum < s){
            cout << "-1" << endl;
            break;
        }
    }
    if(sum == s){
        cout << cnt << endl;
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