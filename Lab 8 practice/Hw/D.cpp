#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x == 1){
                cnt++;
            }
        }
        arr[i] = cnt;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}