#include <iostream>
using namespace std;
int L,R;
void binSearch(int arr[], int l, int r, int x, int n){
    int ok = 0;
    int okey = 0;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] < x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
        if(arr[l] == x){
            ok = 1;
            break;
        }
    }
    L = l;
    l = 0;
    r = n - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] > x){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
        if(arr[r] == x){
            okey = 1;
            break;
        }
    }
    R = r;
    if(ok == 1 && okey == 1){
        cout << L + 1 << " " << R + 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(x < arr[0] || x > arr[n - 1]){
            cout << 0 << endl;
        }
        else{
            binSearch(arr, 0, n - 1, x, n);
        }
    }
}