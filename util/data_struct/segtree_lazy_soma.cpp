struct segtree {
    vector<ll> seg, lazy;
    int n;
 
    segtree(int n, const vll &v) {
        this->n = n;
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, v);
    }
 
    void build(int p, int l, int r, const vll &v) {
        if(l == r) {
            seg[p] = v[l];
            return;
        }
 
        int m = (l + r) / 2;
        build(2*p, l, m, v);
        build(2*p+1, m+1, r, v);
        seg[p] = seg[2*p] + seg[2*p+1];
    }
 
    void push(int p, int l, int r) {
        if(lazy[p] == 0) return;
 
        int m = (l + r) / 2;
 
        apply(2*p, l, m, lazy[p]);
        apply(2*p+1, m+1, r, lazy[p]);
 
        lazy[p] = 0;
    }
 
    void apply(int p, int l, int r, ll val) {
        // para trocar de soma para atribuicao é so seg[p] = val * (r-l+1)
		seg[p] += val * (r - l + 1);
        lazy[p] += val;
    }
 
    void update(int p, int l, int r, int i, int j, ll val) {
        if(r < i || l > j) return;
 
        if(i <= l && r <= j) {
            apply(p, l, r, val);
            return;
        }
 
        push(p, l, r);
 
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, val);
        update(2*p+1, m+1, r, i, j, val);
 
        seg[p] = seg[2*p] + seg[2*p+1];
    }
 
    ll query(int p, int l, int r, int i, int j) {
        if(r < i || l > j) return 0;
 
        if(i <= l && r <= j) return seg[p];
 
        push(p, l, r);
 
        int m = (l + r) / 2;
        return query(2*p, l, m, i, j) +
               query(2*p+1, m+1, r, i, j);
    }
 
    void update(int l, int r, ll val) {
        update(1, 0, n-1, l, r, val);
    }
 
    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
}; 
