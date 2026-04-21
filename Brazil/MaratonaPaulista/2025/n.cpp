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

const ll MAXN = 1e6+10;
vll v(MAXN, 0);

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
		seg[p] = max(seg[2*p+1], seg[2*p]);
	}
 
	void build(int _n, vll v) {
		int n = _n;
		build(1, 0, n-1, v);
	}
 
	ll query(int p, int l, int r, int i, int j) {
		if(r < i || l > j) return 0;
		if(i <= l && r <= j) return seg[p];
		int meio = (l + r) / 2;
 
		 
		return max(query(2 * p, l, meio, i, j), query(2 * p + 1, meio + 1, r, i, j));
	}
 
	ll query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
 
	void update(int p, int l, int r, int pos, ll val) {
		if(l == r) {
			seg[p] = max((ll)0, seg[p] + val);
			return;
		}
 
		int meio = (l+r) / 2;
		
		if(pos <= meio) update(2*p, l, meio, pos, val);
		else update(2*p+1, meio+1, r, pos, val);
		
		seg[p] = max(seg[2 * p], seg[2 * p + 1]);
	}
 
	void update(int pos, ll val) {
		update(1, 0, n-1, pos, val);
	}
};
 


set<ll> fat(int x) {
	int d = 2;
	set<ll> divs;
	while(d * d <= x) {
		if(x % d == 0) {
			divs.insert(d);
			x = x / d;
		}

		else d++;
	}

	if(x != 0) divs.insert(x);
	
	return divs;
}


void muda(set<ll> aux, int v, segtree &s) {
	for(auto x : aux) {
		s.update(x,v);
	}
}


void solve() {
	int n; cin >> n;
	map<int, set<ll>> fatores;
	map<int, bool> ligado;

	segtree s = segtree(MAXN, v);

	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		set<ll> aux;
		if((int) fatores[x].size() != 0) {
			aux = fatores[x];
		}
		
		else {
			aux = fat(x);
			fatores[x] = aux;
		}

		//for(auto x : aux) cout << x << " ";
		//cout << '\n';

		if(!ligado[x]) {
			muda(aux, 1, s);
			ligado[x] = true;
		}
		else { 
			muda(aux, -1, s);
			ligado[x] = false;
		}

		cout << s.query(1, MAXN) << '\n';
	}

}



int main() {
    fastio;

	int t = 1; //cin >> t;
	while(t--) {
		solve();
	}

    return 0;
}


