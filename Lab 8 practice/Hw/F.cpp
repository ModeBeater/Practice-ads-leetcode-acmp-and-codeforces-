#include <iostream>
#include <vector>
using namespace std;
vector <pair<int,int> > g[100005];
#define INF 1e9
int n,m;
int Dijksta(int s, int a){
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
    // for(int i = 1; i <= n; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;   
    return d[a];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v,w));
    }
    int s,a,b,f;
    cin >> s >> a >> b >> f;
    int ans = Dijksta(s,a) + Dijksta(a,b) + Dijksta(b,f);
    int ans1 = Dijksta(s,b) + Dijksta(b,a) + Dijksta(a,f);
    // cout << (min(ans,ans1) >= INF ? -1 : min(ans,ans1));
    if(min(ans,ans1) >= INF){
        cout << -1 << endl;
    }
    else{
        cout << min(ans,ans1);
    }
}