#include <iostream>
#include <vector>

using namespace std;
bool ok[5005];
vector<int> v[5005];
int NEW = 0;
int during = 1;
int visited = 2;
vector<int> state(5005, NEW);
vector<int> path(5005);
void check(int x){
    if(state[x] == during){
        cout << "No" << endl;
        exit(0);
    }
    if(state[x] == visited){
        return;
    }
    state[x] = during;
    for(int i = 0; i < v[x].size(); i++){
        path[v[x][i]] = x;
        check(v[x][i]);
    } 
    state[x] = visited;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(state[i] == NEW){
            path[i] = i;
            check(i);
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++){
        cout << path[i] << endl;
    }
}