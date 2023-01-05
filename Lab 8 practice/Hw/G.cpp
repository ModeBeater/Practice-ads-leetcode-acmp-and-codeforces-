#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int n,m;
int arr[1000][1000];
vector<pair<int, int> > v;
stack<pair<int, int> > a;
int cnt = 0;
int ans = 0;
void bfs(int i, int j){
    if(i < 0 || j < 0 || i > n || j > m){
        return;
    }
    if(arr[i][j] == 1){
        arr[i][j] = 2;
        v.push_back(make_pair(i,j));
        a.pop();
    }
    ans++;
    if(ans == 1){
        bfs(i - 1, j);
        bfs(i + 1, j);
        bfs(i, j - 1);
        bfs(i, j + 1);
    }
    if(ans > 1){
        return; 
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                v.push_back(make_pair(i,j));
            }
            if(arr[i][j] == 1){
                a.push(make_pair(i,j));
            }
        }
    }
    // cout << v.size() << endl;
    // cout << endl;
    while(!a.empty()){
        // int i = 0;  
        int b = v.size();
        int e = a.size();
        for(int i = 0; i < b; i++){
            bfs(v[i].first, v[i].second);
            ans = 0;
        }
        // while(i < v.size()){
        //     bfs(v[i].first, v[i].second);
        //     i++;
        //     ans = 0;
        // }
        if(e == a.size()){
            cout << -1 << endl;
            return 0;
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        cnt++;
    }
    cout << cnt;
}