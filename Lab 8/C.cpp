#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
vector<int> v[105];
bool ok[105];
void check(int x){
    if(ok[x]){
        return;
    }
    ok[x] = true;
    cnt++;
    for(int i = 0; i < v[x].size(); i++){
        if(!ok[v[x][i]]){
            check(v[x][i]);
        }
    }
}


int main(){
    int n,x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a;
            cin >> a;
            if(a == 1){
                v[i].push_back(j);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < v[i].size(); j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    check(x);
    cout << cnt;
}