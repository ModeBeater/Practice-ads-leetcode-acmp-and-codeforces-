#include <iostream>

using namespace std;

void binSearch(int arr[], int l, int r, int x){
    while(l <= r){
        int m = l + (r - l)/ 2;
        if(arr[m] <= x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
        if(arr[m] == x){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    // cout << arr[r] << endl;
    // if(arr[r] == x){
    //     cout << "YES" << endl;
    // }
    // else{
    //     cout << "NO" << endl;
    // }
}


int main(){
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int j = 0; j < m; j++){
        int x;
        cin >> x;
        binSearch(arr,0, n - 1, x);
    }
}