#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,x;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);
    int l,r;
    l = 0;
    r = n - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if (arr[m] == x){
            cout << "Found at " << m << " index " << endl;
            return 0;
        }
        if (arr[m] < x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout << "Element " << x << " does not exist" << endl;
}