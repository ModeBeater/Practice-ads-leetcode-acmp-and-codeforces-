#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
class Heap{
public:
    int parent(int i){
        return (i - 1) / 2;
    }
    int right(int i){
        return i * 2 + 2;
    }
    int left(int i){
        return i * 2 + 1;
    }
    void push(int val){
        v.push_back(val);
    }
    int sift_up(int i){
        while(i > 0 && v[i] > v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
        return i + 1;
    }
    void sift_down(int i){
        if(left(i) > v.size() - 1){
            return;
        }
        int child = left(i);
        if(right(i) < v.size() && v[left(i)] < v[right(i)]){
            child = right(i);
        }
        if(v[child] > v[i]){
            swap(v[child], v[i]);
            sift_down(child);
        }
        else{
            return;
        }
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
    for(int i = v.size() - 1; i >= 0; i--){
        heap.sift_down(i);
    }
    heap.print();
}