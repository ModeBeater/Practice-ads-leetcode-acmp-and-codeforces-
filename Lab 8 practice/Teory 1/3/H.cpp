#include <iostream>
#include <vector>

using namespace std;
vector<int> v[10000];
int ok[10000];
vector <int> a;
vector <int> b;
int c = 1;
void dfs(int x){
    ok[x] = c;
    for(int i = 0; i < v[x].size(); i++){
        if(ok[v[x][i]] == 0){
            dfs(v[x][i]);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        c = x;
        dfs(x);
        a.push_back(x);
    }
    for(int i = 0; i < k; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(ok[j] == a[i]){
                cnt++;
            }
        }
        b.push_back(cnt);
    }
    for(int i = 0; i < k; i++){
        cout << b[i] << endl;
        for(int j = 1; j <= n; j++){
            if(ok[j] == a[i]){
                cout << j << " ";
            }
        }
        cout << endl;
    }
}