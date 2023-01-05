#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int x[8] = {1,2,2,1,-1,-2,-2,-1};
int y[8] = {2,1,-1,-2,-2,-1,1,2};
queue <pair<int,int> > g;
vector<pair<int,int> > path;
vector<pair<int,int> > ans;
pair<int,int> p[22][22];
int d[25][25];

int main(){
    int n;
    cin >> n;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    g.push(make_pair(x1,y1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
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
            if(tox > 0 && tox <= n && toy > 0 && toy <= n){
                if(d[tox][toy] > d[i][j] + 1){
                    d[tox][toy] = d[i][j] + 1;
                    g.push(make_pair(tox,toy));
                    p[tox][toy] = make_pair(i,j);
                }
            }
        }
    }
    for(pair<int,int> v = p[x2][y2]; v != p[x1][y1]; v = p[v.first][v.second]){
        cout << v.first << " " << v.second << endl;
        path.push_back(make_pair(v.first,v.second));
    }
    // path.reverse(path.begin(),path.end());
    for(int i = path.size() - 1; i >= 0; i--){
        ans.push_back(make_pair(path[i].first, path[i].second));
    }
    for(int i = 0; i < path.size(); i++){
        cout << path[i].first << " " << path[i].second << endl;
    }
    // for (int i = 0; i <= n; i ++){
    //     for (int j = 0; j <= n; j ++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << d[x2][y2];
}