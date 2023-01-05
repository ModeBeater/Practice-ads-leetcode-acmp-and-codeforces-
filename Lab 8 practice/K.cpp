#include <iostream>
#include <vector>

using namespace std;

int n,m;
char g[105][105];
bool used[105][105];
int color[105];

void dfs(int i, int j, int c){
    if(i > n || j > m || i < 1 || j < 1){
        return;
    }
    if(g[i][j] == c){
        return;
    }
    if(used[i][j]){
        return;
    }
    used[i][j] = true;
    dfs(i, j + 1, c == 'W' ? 'B' : 'W');
    dfs(i, j - 1, c == 'W' ? 'B' : 'W');
    dfs(i - 1, j, c == 'W' ? 'B' : 'W');
    dfs(i + 1, j, c == 'W' ? 'B' : 'W');
}


int main(){
    n = 8, m = 8;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!used[i][j] && g[i][j] == 'W'){
                dfs(i,j,'B');
                cnt++;
            }
            else if(!used[i][j] && g[i][j] == 'B'){
                dfs(i,j,'W');
                cnt++;
            }
        }
    }
    cout << cnt;
}