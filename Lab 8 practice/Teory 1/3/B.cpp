#include <iostream>
#include <vector>

using namespace std;
vector <int> v[105];
int ans = 0;
bool ok[105];
void check(int x){
    if(ok[x]){
        return;
    }
    ok[x] = true;
    ans++;
    for(int j = 0; j < v[x].size(); j++){
        if(!ok[v[x][j]]){
            check(v[x][j]);
        }
    }
}

int main(){
    int n,x;
    cin >> n >> x;
    while(true){
        int a,b;
        cin >> a;
        if(a == 0){
            break;
        }
        cin >> b;
        v[a].push_back(b);
    }
    check(x);
    if(ans == n){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}