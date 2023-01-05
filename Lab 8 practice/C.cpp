#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;   
    int arr[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    int b[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == 1 && b[i] != b[j]){
                cnt++;
            }
        }
    }
    cout << cnt / 2;
}