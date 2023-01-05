#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    int min,max;
    cin >> n >> m;
    int arr[n][m];
    int cnt = 0;
    int a[n];
    int b[m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        max = arr[i][0];
        for(int j = 1; j < m; j++){
            if(max > arr[i][j]){
                max = arr[i][j];
            }
        }
        a[i] = max;
    }
    for(int i = 0; i < m; i++){
        min = arr[0][i];
        for(int j = 1; j < n; j++){
            if(min < arr[j][i]){
                min = arr[j][i];
            }
        }
        b[i] = min;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
}