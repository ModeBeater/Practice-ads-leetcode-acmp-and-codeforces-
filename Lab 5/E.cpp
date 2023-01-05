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
        cout << sift_up(v.size() - 1) << endl;
    }
    int sift_up(int i){
        while(i > 0 && v[i] > v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
        return i + 1;
    }
    int size(){
        return v.size();
    }
    void sift_down(int i, int b){
        if(left(i) > v.size() - 1){
            if(b == 0){
                cout << i + 1 << " ";
            }
            return;
        }
        int child = left(i);
        if(right(i) < v.size() && v[left(i)] < v[right(i)]){
            child = right(i);
        }
        if(v[child] > v[i]){
            swap(v[child], v[i]);
            sift_down(child, b);
        }
        else{
            if(b == 0){
                cout << i + 1 << " ";
            }
        }
    }
    void increase(int i, int x){
        v[i - 1] += x;
        sift_up(i - 1);
    }
    void decrease(int i, int x){
        v[i - 1] -= x;
        sift_down(i - 1, 0);
    }
    int extractMax(){
        int ans = v[0];
        swap(v[0],v[v.size() - 1]);
        v.pop_back();
        if(v.size() > 0){
            sift_down(0,0);
        }
        else{
            cout << 0 << " ";
        }
        return ans;
    }
    void Remove(int j){
        int ans = v[j - 1];
        swap(v[v.size() - 1], v[j - 1]);
        v.pop_back();
        sift_up(j - 1);
        sift_down(j - 1, 1);
        cout << ans << endl;
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
        if(a == 3){
            int b;
            cin >> b;
            if(heap.size() < b || b < 1){
                cout << -1 << endl;
            }
            else{
                heap.Remove(b);
            }
        }
    }
    heap.print();
}