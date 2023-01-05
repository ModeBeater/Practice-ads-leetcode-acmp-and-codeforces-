#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[105];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    int s, end;
    cin >> s >> end;
    vector<bool> used(n + 2);
    vector<int> d(n + 2), p(n + 2);
    queue<int> q;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                p[to] = v;
                d[to] = d[v] + 1;
            }
        }
    }
    if(used[end]){
        cout << d[end] << endl;
    }
    else{
        cout << -1 << endl;
    }
}