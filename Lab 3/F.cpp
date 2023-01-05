#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int min = 0;
    int max = 100;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > min){
            min = arr[i];
        }
        if(arr[i] < max){
            max = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == min){
            arr[i] = max;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}