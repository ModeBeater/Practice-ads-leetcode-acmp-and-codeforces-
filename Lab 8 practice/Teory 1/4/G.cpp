#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int x[8] = {1,2,2,1,-1,-2,-2,-1};
int y[8] = {2,1,-1,-2,-2,-1,1,2};
queue <pair<int,int> > g;
int d[25][25];
int e[25][25];
int min1 = 1e9;
int main(){
    string a,b;
    cin >> a >> b;
    int x1 = a[0] - 'a' + 1;
    int x2 = b[0] - 'a' + 1;
    int y1 = a[1] - '1' + 1;
    int y2 = b[1] - '1' + 1;
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    g.push(make_pair(x1,y1));
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            d[i][j] = 1e9;
        }
    }
    d[x1][y1] = 0;
    while(!g.empty()){
        int i = g.front().first;
        int j = g.front().second;
        g.pop();
        for(int k = 0; k < 8; k++){
            int tox = i + x[k];
            int toy = j + y[k];
            if(tox > 0 && tox <= 8 && toy > 0 && toy <= 8){
                if(d[tox][toy] > d[i][j] + 1){
                    d[tox][toy] = d[i][j] + 1;
                    g.push(make_pair(tox,toy));
                }
            }
        }
    }
    while(!g.empty()){
        g.pop();
    }
    g.push(make_pair(x2,y2));
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            e[i][j] = 1e9;
        }
    }
    e[x2][y2] = 0;
    while(!g.empty()){
        int i = g.front().first;
        int j = g.front().second;
        g.pop();
        for(int k = 0; k < 8; k++){
            int tox = i + x[k];
            int toy = j + y[k];
            if(tox > 0 && tox <= 8 && toy > 0 && toy <= 8){
                if(e[tox][toy] > e[i][j] + 1){
                    e[tox][toy] = e[i][j] + 1;
                    g.push(make_pair(tox,toy));
                }
            }
        }
    }
    for (int i = 1; i <= 8; i ++){
        for (int j = 1; j <= 8; j ++){
            if(e[i][j] == d[i][j]){
                if(min1 > e[i][j]){
                    min1 = e[i][j];
                }
            }
        }
    }
    if(min1 != 1e9){
        cout << min1;
    }
    else{
        cout << -1;
    }
}