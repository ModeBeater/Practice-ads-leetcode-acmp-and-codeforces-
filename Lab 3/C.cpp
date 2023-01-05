#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int min = -9999;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        if(m > min){
            min = m;
            cnt = i + 1;
        }
    }
    cout << cnt;
}