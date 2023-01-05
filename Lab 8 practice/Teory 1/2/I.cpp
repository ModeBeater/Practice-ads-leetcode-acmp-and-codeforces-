#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[105][105];
int main(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    while(m--){
        int a,b;
        cin >> a >> b;
        arr[a][b]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j){
                if(arr[i][j] + arr[j][i] != 1){
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i][j] != 0){
            cout << "NO";
            return 0;
        }
        j++;
    }
    cout << "YES";
}