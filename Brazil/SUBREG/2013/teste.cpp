#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define len(x) ((int)(x).size())
#define seti set<int>
#define setll set<ll>
 
 
#define sortarr(x) sort(all(x))
 
#define dict(key, value) map<key, value>
#define udict(key, value) unordered_map<key, value>
 
#define pii pair<int,int>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
 
#define fastio ios::sync_with_stdio(false); cin.tie(0);
 
struct segtree {
    vector<ll> seg, lazy;
    int n;
 
    segtree(int n, vll v) {
        this->n = n;
        seg.assign(4*n, 0);
        //lazy.assign(4*n, 0);
        build(1, 0, n-1, v);
    }
 
    void build(int p, int l, int r, vll &v) {
        if(l == r) {
            seg[p] = v[l];
            return;
        }
 
        int m = (l + r) / 2;
        build(2*p, l, m, v);
        build(2*p+1, m+1, r, v);
        seg[p] = seg[2*p] + seg[2*p+1];
    }
 
    //void push(int p, int l, int r) {
        //if(lazy[p] == 0) return;
 
        //int m = (l + r) / 2;
 
        //apply(2*p, l, m, lazy[p]);
        //apply(2*p+1, m+1, r, lazy[p]);
 
        //lazy[p] = 0;
    //}
 
    void apply(int p, int l, int r, ll val) {
        seg[p] += val * (r - l + 1);
        //lazy[p] += val;
    }
 
    void update(int p, int l, int r, int i, int j, ll val) {
        if(r < i || l > j) return;
 
        if(i <= l && r <= j) {
            apply(p, l, r, val);
            return;
        }
 
        //push(p, l, r);
 
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, val);
        update(2*p+1, m+1, r, i, j, val);
 
        seg[p] = seg[2*p] + seg[2*p+1];
    }
 
    ll query(int p, int l, int r, int i, int j) {
        if(r < i || l > j) return 0;
 
        if(i <= l && r <= j) return seg[p];
 
        //push(p, l, r);
 
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
 
 
	int kth(int p, int l, int r, int k) {
    	if(l == r) return l;
 
    	//push(p, l, r);
 
    	int m = (l + r) / 2;
 
    	if(seg[2*p] >= k)
        	return kth(2*p, l, m, k);
    	else
        	return kth(2*p+1, m+1, r, k - seg[2*p]);
	}
};
 
void solve() {
    int n; cin >> n;
 
    vll v(n, 1);
    segtree s(n, v);
 
    vi a(n/2), b(n/2);
    for(int i = 0; i < n/2; i++) cin >> a[i];
    for(int i = 0; i < n/2; i++) cin >> b[i];
 
    vi x, y;
 
    for(int i = 0; i < n/2; i++) {
        int pos = s.kth(1, 0, n-1, a[i]);
        x.pb(pos + 1);
        s.update(pos, pos, -1);
 
        pos = s.kth(1, 0, n-1, b[i]);
        y.pb(pos + 1);
        s.update(pos, pos, -1);
    }
 
    for(int i : x) cout << i << " ";
    cout << '\n';
    for(int i : y) cout << i << " ";
    cout << '\n';
}
 
 
int main() {
    fastio;
 
	int t = 1; //cin >> t;
	while(t--) {
		solve();
	}
 
    return 0;
}
 
 
