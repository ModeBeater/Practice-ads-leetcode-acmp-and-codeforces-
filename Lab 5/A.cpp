#include <iostream>
#include <vector>

using namespace std;

class Heap{
public:
    vector<int> a;
    int size;
    Heap(){
        size = 0;
    }
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return i * 2 + 1;
    }
    int right(int i){
        return i * 2 + 2;
    }
    void insert(int val){
        a.push_back(val);
        shift_up(size,0);
        size++;
    }
    void increase(int i, int x){
        a[i - 1] += x;
        shift_up(i - 1,1);
    }
    void shift_up(int i,int b){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        if(b == 1){
            cout << i + 1 << endl;
        }
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Heap heap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        heap.insert(val);
    }
    int m;
    cin >> m;
    while(m--){
        int i;
        int x;
        cin >> i >> x;
        heap.increase(i,x);
    }
    heap.print();
}