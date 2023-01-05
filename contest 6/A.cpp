#include <iostream>
#include <vector>
using namespace std;
vector<int> prefix_function (string s) {
	int n = s.length();
	vector<int> v(n);
	for (int i = 1; i < n; i++) {
		int j = v[i - 1];
		while (j > 0 && s[i] != s[j]){
			j = v[j - 1];
		}
		if (s[i] == s[j]){
			j++;
		}
		v[i] = j;
	}
	return v;
}
int main(){
    string s,t;
    cin >> s >> t;
    string a = s;
    string b = t;
    int c = 0;
    int d = 0;
    vector<int> ans = prefix_function(t + "#" + s);
    for(int i = 0; i < ans.size(); i++){
		// cout << ans[i] << " ";
        if(ans[i] == t.size()){
            t.erase(t.end() - 1, t.end());
        }
        else if(t.size() > 1){
            c = t.size();
            break;
        }
    }
    if(c == 0){
        c = -1;
    }
    vector<int> ansd = prefix_function(a + "#" + b);
    for(int i = 0; i < ansd.size(); i++){
		// cout << ans[i] << " ";
        if(ansd[i] == a.size()){
            a.erase(a.end() - 1, a.end());
        }
        else if(a.size() > 1){
            d = a.size();
            break;
        }
    }
    if(d == 0){
        d = -1;
    }
    if(d > c){
        cout << d;
    }
    if(c > d){
        cout << c;
    }
    else{
        cout << -1;
    }
}