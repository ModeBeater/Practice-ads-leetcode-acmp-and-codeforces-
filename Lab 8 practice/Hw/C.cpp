#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){
            int a;
            cin >> a;
            arr[i][a - 1] = 1;
        }
    }
    cout << n << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}