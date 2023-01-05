#include <iostream>
#include <vector>

using namespace std;
vector <int> v[105];
bool ok[105];
int ans = 0;
void dfs(int x){
    if(ok[x]){
        return; 
    }
    ans++;
    ok[x] = true;
    for(int i = 0; i < v[x].size(); i++){
        if(!ok[v[x][i]]){
            dfs(v[x][i]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int edge = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                edge++;
                v[i].push_back(j);
            }
        }
    }
    if(edge / 2 != n - 1){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        dfs(i);
        if(ans != n){
            cout << "NO" << endl;
            return 0;
        }
        ans = 0;
        for(int i = 1; i <= n; i++){
            ok[i] = false;
        }
    }
    cout << "YES";
}