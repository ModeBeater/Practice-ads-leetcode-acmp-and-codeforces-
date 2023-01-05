#include <iostream>
#include <vector>

using namespace std;
vector<int> v[105];
int color[105];

void check(int x, int c){
    if(color[x] != 0){
        if(color[x] != c){
            cout << "NO";
            exit(0);
        }
    }
    if(color[x] == c){
        return;
    }
    color[x] = c;
    for(int i = 0; i < v[x].size(); i++){
        if(c == 2){
            check(v[x][i],1);
        }
        else{
            check(v[x][i],2);
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            check(i,1);
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++){
        if(color[i] == 1){
            cout << i << endl;
        }
    }
}