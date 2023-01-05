#include <iostream>
#include <vector>

using namespace std;

class Heap{
public:
    vector <int> v;
    int parent(int i){
        return (i - 1) / 2;
    }
    int right(int i){
        return (i * 2) + 2;
    }
    int left(int i){
        return (i * 2) + 1;
    }
    void push(int val){
        v.push_back(val);
        sift_up(v.size() - 1,0);
    }
    void sift_up(int i,int b){
        while(i > 0 && v[i] >= v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
        if(b == 1){
            cout << i + 1 << endl;
        }
    }
    void increase(int i, int x){
        v[i - 1] += x;
        sift_up(i - 1,1);
    }
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
    }
};



int main(){
    Heap heap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int j,x;
        cin >> j >> x;
        heap.increase(j,x);
    }
    heap.print();
}