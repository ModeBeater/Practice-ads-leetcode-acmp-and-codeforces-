#include <iostream>
#include <vector>

using namespace std;

int n,m;
char g[105][105];
bool used[105][105];
int color[105];

void dfs(int i, int j){
    if(i > n || j > m || i < 1 || j < 1){
        return;
    }
    if(g[i][j] == '.'){
        return;
    }
    if(used[i][j]){
        return;
    }
    used[i][j] = true;
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i - 1, j);
    dfs(i + 1, j);
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!used[i][j] && g[i][j] == '#'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
}