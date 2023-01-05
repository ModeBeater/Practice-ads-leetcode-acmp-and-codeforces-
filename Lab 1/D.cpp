#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    multimap <int,string> mp;
    while(cin >> n){
        string s;
        cin >> s;
        mp.insert(make_pair(n,s));
    }
    multimap <int,string> :: iterator it = mp.begin();
    for(it; it != mp.end(); it++){
        cout << it -> first << " " << it -> second << endl;
    }
}