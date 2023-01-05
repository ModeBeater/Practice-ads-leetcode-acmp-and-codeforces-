#include <iostream>
#include <vector>

using namespace std;
int n,m;
char arr[105][105];
int cnt = 0;
bool ok[105][105];
void check(int i, int j){
    if(i < 0 || j < 0 || j > m - 1 || i > n - 1){
        return;
    }
    if(ok[i][j]){
        return;
    }
    ok[i][j] = true;
    if(arr[i][j] == '.'){
        return;
    }
    check(i + 1, j);
    check(i - 1, j);
    check(i, j + 1);
    check(i, j - 1);
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '#' && ok[i][j] == 0){
                check(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
}