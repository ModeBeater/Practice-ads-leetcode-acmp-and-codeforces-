#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int min = -9999;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        if(m > min){
            min = m;
        }
    }
    cout << min;
}