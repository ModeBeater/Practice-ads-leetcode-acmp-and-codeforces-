#include <iostream>
#include <vector>

using namespace std;
vector <long long> v[100005];
long long ok[100005];
void check(int x, int c){
    if(ok[x] == c){
        return;
    }
    ok[x] = c;
    for(int i = 0; i < v[x].size(); i++){
        if(c == 2){
            check(v[x][i], 1);
        }
        else{
            check(v[x][i], 2);
        }
    }
}
int main(){
    long long n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(ok[i] == 0){
            check(i,1);
        }
    }
    long long cnt1 = 0;
    long long cnt2 = 0;
    for(int i = 1; i <= n; i++){
        if(ok[i] == 2){
            cnt2++;
            // cout << i << endl;
        }
        if(ok[i] == 1){
            cnt1++;
        }
    }
    long long ans = cnt1 * cnt2;
    cout << ans - n + 1;
}