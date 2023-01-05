#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
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


void solve(){
    string s;
    cin >> s;
    int sum = 0;
    vector<int> ans = prefix_function("1#" + s);
    for(int i = 0; i < ans.size(); i++){
		// cout << ans[i] << " ";
        if(ans[i] == 1){
            v.push_back(i - 2);
        }
    }
    if(v.size() == 0){
        cout << 0 << endl;
        v.erase(v.begin(), v.end());
        return;
    }
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i + 1] - v[i] != 1){
            sum += v[i + 1] - v[i] - 1;
        }
    }
    cout << sum << endl;
    v.erase(v.begin(), v.end());
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}