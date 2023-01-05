#include <iostream>

using namespace std;


void solve(){
    char arr[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(arr[i][j] == '#' && arr[i - 1][j - 1] == '#' && arr[i + 1][j + 1] == '#' && arr[i - 1][j + 1] == '#' && arr[i + 1][j - 1] == '#'){
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}