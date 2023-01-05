#include <iostream>
#include <vector>


using namespace std;
int ans = 0;
bool used[105];
vector<int> v[105];

void dfs(int a){
    used[a] = true;
    ans++;
    for(int i = 0; i < v[a].size(); i++){
        int to = v[a][i];
        if(!used[to]){
            dfs(to);
        }
    }
}


int main(){
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                v[i].push_back(j);    
            }
        }
    }
    dfs(s);
    cout << ans - 1;
}