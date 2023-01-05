#include <iostream>
#include <vector>

using namespace std;
vector <int> v[30005];
int main(){
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    int c = 0;
    for(int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        if(c == 0){
            c = x;
        }
        v[x].push_back(i + 1);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}