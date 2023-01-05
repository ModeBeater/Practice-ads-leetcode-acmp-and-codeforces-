#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[10000];

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
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        if(v[i].size() != n - 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES";
}