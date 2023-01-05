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
    void sift_up(int i){
        while(i > 0 && v[i] > v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
        cout << i + 1 << endl;
    }
    int size(){
        return v.size();
    }
    void sift_down(int i){
        if(left(i) > v.size() - 1){
            cout << i + 1 << " ";
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
            cout << i + 1 << " ";
        }
    }
    void increase(int i, int x){
        v[i - 1] += x;
        sift_up(i - 1);
    }
    void decrease(int i, int x){
        v[i - 1] -= x;
        sift_down(i - 1);
    }
    int extractMax(){
        int ans = v[0];
        swap(v[0],v[v.size() - 1]);
        v.pop_back();
        if(v.size() > 0){
            sift_down(0);
        }
        else{
            cout << 0 << " ";
        }
        return ans;
    }
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
    }
};



int main(){
    Heap heap;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        if(a == 1){
            if(heap.size() == 0){
                cout << -1 << endl;
            }
            else{
                cout << heap.extractMax() << endl;
            }
        }
        if(a == 2){
            int b;
            cin >> b;
            if(heap.size() < n){
                heap.push(b);
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    heap.print();
}