#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
int color[105];
vector<int> v[105];
void check(int i){
    for(int j = 0; j < v[i].size(); j++){
        if(color[v[i][j]] != color[i]){
            cnt++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                v[i].push_back(j);
                // v[j].push_back(i);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < v[i].size(); j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        color[i] = x;
    }
    for(int i = 1; i <= n; i++){
        check(i);
    }
    cout << cnt / 2;
}