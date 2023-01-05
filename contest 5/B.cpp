#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1000];
bool ok[1000];
vector<int> ans[1000];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int j = 2;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        while(ans[i].size() < 2){
            if(v[i].size() != 0){
                for(int k = 0; k < v[i].size(); k++){
                    if(v[i][k] == j){
                        i++;
                        cnt++;
                        break;
                    }
                }
            }
            ans[i].push_back(j);
            ans[j].push_back(i);
            j++;
            if(j > n){
                break;
            }
        }
        if(j > n){
            break;
        }
    }
    // cout << 1 << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " ";
        for(int k = 0; k < ans[i].size(); k++){
            cout << ans[i][k] << " ";
        }
        cout << endl;
    }
}