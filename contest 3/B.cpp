#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    sort(arr, arr + n);
    // int j = 1;
    int cnt = 1;
    cout << n << endl;
    int check;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[j] << " ";
            cnt++;
        }
        cout << endl;
        swap()
    }
    // do{
    //     if(j == 1){
    //         for(int i = 0; i < n; i++){
    //             if(arr[i] == j + 1){
    //                 check = i;
    //             }
    //             cout << arr[i] << " ";
    //         }
    //         cout << endl;
    //         j++;
    //         cnt++;
    //     }
    //     if(arr[check] == j){
    //         cnt++;
    //         j++;
    //         for(int i = 0; i < n; i++){
    //             if(arr[i] == j){
    //                 check = i;
    //             }
    //             cout << arr[i] << " ";
    //         }
    //         cout << endl;
    //     }
    // } while(next_permutation(arr,arr + n) && cnt != n);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}