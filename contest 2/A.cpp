#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;
vector<int> v1;

void naruto(){
    for(int i = v1.size() - 1; i >= 0; i--){
        cout << v1[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    int arr[n];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = x;
        // mp[x] += 1;
        // mp.insert(make_pair(x,1)); 
    }
    for(int i = n - 1; i >= 0; i--){
        mp.insert(make_pair(arr[i],1));
    }
    map<int,int> :: iterator it = mp.begin();
    vector<int> v;
    for(it; it != mp.end(); it++){
        v.push_back(it -> first);
    }
    cout << v.size() << endl;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < v.size(); j++){
            if(arr[i] == v[j]){
                v1.push_back(arr[i]);
                v.erase(v.begin() + j);
                if(v.size() == 0){
                    naruto();
                    return 0;
                }
            }
        }
    }
}