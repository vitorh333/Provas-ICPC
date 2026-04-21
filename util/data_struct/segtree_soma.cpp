struct segtree {
	
	vector<ll> seg;
    int n;
 
    segtree(int n, const vll &v) {
        this->n = n;
        seg.assign(4*n,0);
		build(1,0,n-1,v);
    }
 
	void build(int p, int l, int r, const vll &v) {
		if(l==r) {
			seg[p] = v[l];
			return;
		}
 
		int meio = (l + r) / 2;
		build(2 * p, l, meio, v);
		build(2*p+1, meio+1, r, v);
		seg[p] = seg[2*p+1] + seg[2*p];
	}
 
	void build(int _n, vll v) {
		int n = _n;
		build(1, 0, n-1, v);
	}
 
	ll query(int p, int l, int r, int i, int j) {
		if(r < i || l > j) return 0;
		if(i <= l && r <= j) return seg[p];
		int meio = (l + r) / 2;
 
		 
		return query(2 * p, l, meio, i, j) + query(2 * p + 1, meio + 1, r, i, j);
	}
 
	ll query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
 
	void update(int p, int l, int r, int pos, ll val) {
		if(l == r) {
			seg[p] = val;
			return;
		}
 
		int meio = (l+r) / 2;
		
		if(pos <= meio) update(2*p, l, meio, pos, val);
		else update(2*p+1, meio+1, r, pos, val);
		
		seg[p] = seg[2 * p] + seg[2 * p + 1];
	}
 
	void update(int pos, ll val) {
		update(1, 0, n-1, pos, val);
	}
};
 
