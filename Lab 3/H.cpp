#include <iostream>

using namespace std;

// void binSearch(int arr[], int l, int r, int x){
//     int cnt1 = 0;
//     while(l <= r){
//         int m = l + (r - l) / 2;
//         if(arr[m] <= x){
//             l = m + 1;
//         }
//         else{
//             r = m - 1;
//         }
//         cnt1++;
//         if(arr[m] == x){
//             break;
//         }
//     }
//     int cnt2 = 0;
//     l = 0;
//     r = x - 1;
//     while(l <= r){
//         int m = l + (r - l) / 2;
//         if(arr[m] >= x){
//             r = m - 1;
//         }
//         else{
//             l = m + 1;
//         }
//         cnt2++;
//         if(arr[m] == x){
//             break;
//         }
//     }
//     cout << min(cnt1, cnt2);
// }


int main(){
    int n;
    cin >> n;
    int arr[n];
    int cnt = 0;
    int a = 1;
    // for(int i = 0; i < n; i++){
    //     arr[i] = i + 1;
    // }
    while(a < n){
        a = a * 2;
        cnt++;
    }
    cout << cnt;
    // binSearch(arr,0,n - 1, n);
}