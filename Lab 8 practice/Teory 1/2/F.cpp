#include <iostream>
#include <vector>
using namespace std;
vector <int> v1[1000];
vector <int> v2[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                if(i == j){
                    cout << "NO" << endl;
                    return 0;
                }
                v1[i].push_back(j);
                v2[j].push_back(i);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < v1[i].size(); j++){
            if(v1[i][j] != v2[i][j]){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO";
}