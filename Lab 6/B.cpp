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
    string s;
    cin >> s;
    vector<int> ans = prefix_function(s);
	int n = s.length();
	// cout << ans[n - 1] << endl;
	int k = n - ans[n - 1];
	if(n % k == 0){
		cout << n / k;
	}
	else{
		cout << 1;
	}
}