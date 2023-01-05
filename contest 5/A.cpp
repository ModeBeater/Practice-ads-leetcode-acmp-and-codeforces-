#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<int> v[100005];
int ring = 1;
int bus = 1;
int star = 1;
int d;
// bool ok[10005];
vector<int> c;
void check(int x){
    if(c.size() > 0){
        if(v[x].size() > 1){
            star = 0;
            cout << "unknown topology" << endl;
            exit(0);
        }
    }
    if(v[x].size() > 2){
        bus = 0;
        ring = 0;
        if(c.size() > 0){
            star = 0;
            cout << "unknown topology" << endl;
            exit(0);
        }
        c.push_back(x);
    }
    // ok[x] = true;
}

int main(){
    cin >> n >> m;
    int min = 999999;
    int max = 0;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        if(min > a){
            min = a;
        }
        if(min > b){
            min = b;
        }
        if(max < a){
            max = a;
        }
        if(max < b){
            max = b;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = min; i <= max; i++){
        check(i);
        // for(int j = 0; j < v[i].size(); j++){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
    }
    if(v[max][1] != min){
        ring = 0;
    }
    // cout << v[n][1] << endl;
    if(ring == 1){
        cout << "ring topology" << endl;
        return 0;
    }
    if(bus == 1){
        cout << "bus topology" << endl;
        return 0;
    }
    cout << "star topology";
}