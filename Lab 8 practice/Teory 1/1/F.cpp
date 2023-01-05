#include <iostream>
#include <vector>

using namespace std;
vector<int> v[10000];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(v[i].size() >= 2){
            cnt++;
        }
        // cout << i << " ";
        // for(int j = 0; j < v[i].size(); j++){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
    }
    cout << cnt;
}