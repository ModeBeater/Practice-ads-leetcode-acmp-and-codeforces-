#include <iostream>

using namespace std;

int L,R;
int binSearch(int a[], int l, int r, int x, int n){
    if (x < a[0] || x > a[n - 1]){
        cout << 0 << endl;
        return 0;
    }
    while(l <= r){
        int m = l + (r - l) / 2;
        if(a[m] <= x){
            l = m + 1;
        }
        else{ 
            r = m - 1;
        }
    }
    R = r;
    l = 0;
    r = n - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if (a[m] >= x){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    L = l;
    cout << L + 1 << " " << R + 1 << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    binSearch(a,0,n - 1, x, n);
}