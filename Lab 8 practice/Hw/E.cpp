#include <iostream>
#include <vector>
using namespace std;
vector <pair<int,int> > g[105];
#define INF 1e9
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v,w));
    }
    int s = 1;
    vector<int> d (n + 2, INF), p(n + 2);
    d[s] = 0;
    vector<char> u(n);
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!u[j] && (v == -1 || d[j] < d[v])){
                v = j;
            }
        }
        if(d[v] == INF){
            break;
        }
        u[v] = true;
        for(int j = 0; j < g[v].size(); j++){
            int to = g[v][j].first;
            int len = g[v][j].second;
            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
}