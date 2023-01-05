#include <iostream>
#include <vector>

using namespace std;

int color[105];
vector<int> g[105];

void dfs(int v, int c){
    if(color[v] != 0){
        if(color[v] != c){
            cout << "NO";
            exit(0);
        }
    }
    if(color[v] == c){
        return;
    }
    color[v] = c;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(c == 2){
            dfs(to, 1);
        }
        else{
            dfs(to, 2);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= m; i++){
        if(color[i] == 0){
            dfs(i,1);
        }
    }
    cout << "YES" << endl;
}