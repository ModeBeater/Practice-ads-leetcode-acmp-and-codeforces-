#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x == 1){
                v.push_back(make_pair(i + 1,j + 1));
                // cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    cout << n << " " << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}