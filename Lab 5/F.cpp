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
        sift_up(v.size() - 1);
    }
    int sift_up(int i){
        while(i > 0 && v[i] > v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
        return i + 1;
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
        int a;
        cin >> a;
        heap.push(a);
    }
    heap.print();
}