#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int sum1 = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        sum1 += arr[i];
        sum -= arr[i];
        cnt++;
        if(sum1 > sum){
            break;
        }
    }
    cout << cnt;
}