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
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x;
        if(x == 0){
            break;
        }
        cin >> y;
        v[x].push_back(y);
    }
    dfs(s);
    if(ans >= n){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}