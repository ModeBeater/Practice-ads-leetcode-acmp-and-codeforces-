#include <iostream>
#include <vector>

using namespace std;
char arr[305][305];
bool ok[305][305];
int n,m;
int cnt = 0;
int temp = 0;
void bfs(int i, int j){
    if(i < 0 || j < 0 || i > n || j > m){
        return;
    }
    if(ok[i][j]){
        return;
    }
    ok[i][j] = true;
    if(arr[i][j] == '*'){
        bfs(i + 1,j);
        bfs(i - 1, j);
        bfs(i, j + 1);
        bfs(i, j - 1);
        temp++;
    }
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
            bfs(i,j);
            if(temp != 0){
                cnt++;
                temp = 0;
            }
        }
    }
    cout << cnt;
}