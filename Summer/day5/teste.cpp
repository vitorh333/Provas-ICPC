#include "bits/stdc++.h"
using namespace std;
    
const int64_t inf = (int64_t) 1e18;
template<class T> struct seg_tree {
    struct node {
        T x;
        node() : x(0) {}
        node(T x) : x(x) {}
        node operator+(const node &o) const {
            return node(x + o.x);
        }
    };
    int n;
    vector<node> tree;
    vector<T> lazy;
    seg_tree(vector<T> a){
        n = a.size();
        tree.resize(n * 4);
        lazy.resize(n * 4);
        build(1,0,n - 1,a);
    }
    inline int left(int id) {return (id << 1);}
    inline int right(int id) {return (id << 1) | 1;}
    

    void build(int id, int l,int r,const vector<T> & a){
        if (l == r) tree[id] = node(a[l]);
        else {
            int m = (l + r) >> 1;
            build(left(id),l,m,a);
            build(right(id),m + 1,r,a);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    inline void push(int id,int l,int r){
        if (lazy[id]){
            tree[id].x += lazy[id];
            if (l != r){
                lazy[left(id)] += lazy[id];
                lazy[right(id)] += lazy[id];
            }
            lazy[id] = 0;
        }
    }
    void update(int id ,int l, int r,int lq,int rq, T val){
        push(id,l,r);
        if (l > rq || r < lq) return;
        if (lq <= l && r <= rq){
            lazy[id] += val;
            push(id,l,r);
        }else {
            int mid = (l + r) >> 1;
            update(left(id),l,mid,lq,rq,val);
            update(right(id),mid + 1,r,lq,rq,val);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    node query(int id,int l,int r, int lq,int rq){
        push(id,l,r);
        if (l > rq || r < lq) return node();
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;
        return query(left(id),l,mid,lq,rq) + query(right(id), mid + 1,r,lq,rq);
    }
    void update(int l,int r, T val) {update(1,0,n-1,l,r,val);}
    node query(int l,int r) {return query(1,0,n - 1,l,r);}
};

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;

    while(t--){
        int n,d,k; cin >> n >> d >> k;
        vector<int64_t> v(n+d+1,0);
        seg_tree sg(v);

        for (int i = 0; i < k; i++){
            int l,r; cin >> l >> r;
            int inicio = max(1, l - d + 1);
            int fim = min(n - d + 1,r);
            sg.update(inicio,fim,1);
        }

        int64_t filho = 1;
        int64_t mfilho = 0;
        int64_t mae = 1;
        int64_t mmae = inf;
        for (int i = 1; i <= n; i++){
            int64_t at = sg.query(i,i).x;
            //cout << "at,i: " << at << " " << i << '\n';
            if (at > mfilho){
                filho = i;
                mfilho = at;
            }
            if (at < mmae){
                mae = i;
                mmae = at;
            }
        }
        cout << filho << " " << mae << '\n';

    }
    return 0;
}
  
