#include <iostream>
#include <vector>
using namespace std;
vector <int> v[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for(int i = 1; i < n; i++){
        if(v[i].size() != v[i + 1].size()){
            cout << "NO" << endl;
            return 0;
        }
        // for(int j = 0; j < v[i].size(); j++){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
    }
    cout << "YES";
}