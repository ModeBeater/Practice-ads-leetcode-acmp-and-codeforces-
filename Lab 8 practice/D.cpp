#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long a,b;
    cin >> a >> b;
    while(a != b){
        if(a > b){
            a = a / 2;
        }
        else if(b > a){
            b = b / 2;
        }
    }
    cout << a;
}