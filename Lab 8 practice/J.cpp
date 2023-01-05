#include <iostream>
#include <vector>

using namespace std;

int n,m;
char g[105][105];
bool used[105][105];
int color[105];
int cnt = 0;
void dfs(int i, int j){
    if(i > n || j > n || i < 1 || j < 1){
        cnt++;
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
    cin >> n;
    for(int i = 1; i <= )
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!used[i][j] && g[i][j] == '#'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << (cnt - 4) * n * n;
}