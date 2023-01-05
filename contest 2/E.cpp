#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int b[n - 1];
    for(int i = 0; i < n - 1; i++){
        cin >> b[i];
    }
    sort(b, b + n - 1);
    int c[n - 2];
    for(int i = 0; i < n - 2; i++){
        cin >> c[i];
    }
    sort(c, c + n - 2);
    int i = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] != b[i]){
            cout << arr[j] << endl;
            break;
        }
        i++;
    }
    i = 0;
    for(int j = 0; j < n - 1; j++){
        if(b[j] != c[i]){
            cout << b[j] << endl;
            return 0;
        }
        i++;
    }
}