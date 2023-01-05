#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a;
    int ok = 0;
    if(n > m){
        a = n;
        while(ok == 0){
            if(a % n == 0 && a % m == 0){
                break;
            }
            a++;
        }
    }
    if(m > n){
        a = m;
        while(ok == 0){
            if(a % n == 0 && a % m == 0){
                break;
            }
            a++;
        }
    }
    if(m == n){
        a = m;
    }
    cout << a;
}