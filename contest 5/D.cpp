#include <iostream>
using namespace std;

int main(){
    int t,s,x;
    cin >> t >> s >> x;
    if(t > x){
        cout << "NO" << endl;
        return 0;
    }
    if(t == x){
        cout << "YES" << endl;
        return 0;
    }
    int ans1 = t;
    int ans2 = t;
    while(ans1 < x){
        ans1 += s;
        ans2 = ans1 + 1;
        // cout << ans1 << " " << ans2 << endl;
        if(ans1 == x || ans2 == x){
            cout << "YES" << endl;
            return 0;
        } 
    }
    cout << "NO";
}