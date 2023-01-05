#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap{
public:
    vector <int> v;
    int left(int i){
        return i*2+1;
    }
    int right(int i){
        return i*2+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int val){
        v.push_back(val);
        cout<<shift_up(v.size()-1)<<endl;
    }
    int shift_up(int i){
        while(i > 0 && v[parent(i)] < v[i]){
            swap(v[parent(i)] , v[i]);
            i = parent(i);
        }
        return i + 1;
    }
    void shift_down(int i, int b){
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
            shift_down(child, b);
        }
        else{
            if(b == 0){
                cout << i + 1 << " ";
            }
        }
    }
    int del(int i){
        int ans = v[i - 1];
        swap(v[i - 1],v[v.size()-1]);
        v.pop_back();
        shift_up(i - 1);
        shift_down(i - 1,1);
        return ans;
    }
    int extract_max(){
        int ans = v[0];
        swap(v[0] , v[v.size()-1]);
        v.pop_back();
        if(v.size()>0){
            shift_down(0,0);
        }else cout<<0<<" ";
        return ans;
    }
    void print(){
        for (int i = 0; i < v.size(); ++i){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Heap heap;
    int n,m;;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int q;
        cin>>q;
        if(q==1){
            if(heap.v.size()==0){
                cout<<-1<<endl;
            }
            else{
                cout<<heap.extract_max()<<endl;
            }
        }
        if(q==2){
            int x;
            cin>>x;
            if(heap.v.size() < n){
                heap.insert(x);
            }
            else cout<<-1<<endl;
        }
        if(q==3){
            int index;
            cin>>index;
            if(index < 1 || index > heap.v.size()){
                cout<<-1<<endl;
            }else{
                cout<<heap.del(index)<<endl;;
            }
        }
    }
    heap.print();
}