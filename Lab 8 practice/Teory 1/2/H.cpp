#include <iostream>
#include <vector>

using namespace std;
vector<int> v[1000];
vector<int> a[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                v[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }
    vector<int> v2;
    vector<int> v1;
    for(int i = 1; i <= n; i++){
        if(v[i].size() == 0){
            v2.push_back(i);
            // cout << i << " ";
        }
        if(a[i].size() == 0){
            v1.push_back(i);
            // cout << i << " 
        }
        // for(int j = 0; j < v[i].size(); j++){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
    }
    cout << v1.size() << " ";
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl << v2.size() << " ";
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
}