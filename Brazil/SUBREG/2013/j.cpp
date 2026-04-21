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
 
ll const INF = 1e18;
ll const MAX = 1e5 + 10;
 
struct dsu {
	vector<int> id, sz;
	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }
	int find(int a) {return a == id[a] ? a : id[a] = find(id[a]);}
 
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(a==b) return;
		if(sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};
 
 
namespace seg {
    static ll st[4 * MAX];
    int n;
 
 
    void build(int p, int l, int r, int v[]) {
        if (l == r) {
            st[p] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * p, l, m, v);
        build(2 * p + 1, m + 1, r, v);
        st[p] = min(st[2 * p], st[2 * p + 1]);
    }
 
    void build(int _n, int v[]) {
        n = _n;
        build(1, 0, n - 1, v);
    }
 
 
    ll query(int p, int l, int r, int i, int j) {
        if (r < i || l > j) return INF;
        if (i <= l && r <= j) return st[p];
        int m = (l + r) / 2;
        return min(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
    }
 
    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
 
 
    void update(int p, int l, int r, int i, int j, ll val) {
		if (r < i || l > j) return;
		if(l==r) {
			st[p] = val;
			return;
		}
		
		int m = (l + r) / 2;
        update(2 * p, l, m, i, j, val);
        update(2 * p + 1, m + 1, r, i, j, val);
        st[p] = min(st[2 * p], st[2 * p + 1]);
    }
 
    void update(int l, int r, ll val) {
        update(1, 0, n - 1, l, r, val);
    }
}
 
namespace hld {
	vector<pair<int, int> > g[MAX];
	//vizinho, peso
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;
 
	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.first != p) {
			auto [u, w] = i;
			sobe[u] = w; pai[u] = k;
			h[u] = (i == g[k][0] ? h[k] : u);
			build_hld(u, k, f); sz[k] += sz[u];
 
			if (sz[u] > sz[g[k][0].first] or g[k][0].first == p)
				swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	ll query_path(int a, int b) {
		if (a == b) return INF;
		if (pos[a] < pos[b]) swap(a, b);
 
		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return min(seg::query(pos[h[a]], pos[a]), query_path(pai[h[a]], b));
	}
	void update_path(int a, int b, int x) {
		if (a == b) return;
		if (pos[a] < pos[b]) swap(a, b);
 
		if (h[a] == h[b]) return (void)seg::update(pos[b]+1, pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	ll query_subtree(int a) {
		if (sz[a] == 1) return 0;
		return seg::query(pos[a]+1, pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		if (sz[a] == 1) return;
		seg::update(pos[a]+1, pos[a]+sz[a]-1, x);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}
 
 
void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<tll> aux;
	
	for(int i = 0; i < m; i++) {
		ll v, u, p; cin >> v >> u >> p;
		v--; u--;
		aux.pb({p, v, u});
	}
 
	dsu d = dsu(n);
	sort(aux.begin(), aux.end());
	reverse(aux.begin(), aux.end());
 
	for(auto [p, v, u] : aux) {
		if(d.find(v) != d.find(u)) {
			hld::g[v].pb({u, p});
			hld::g[u].pb({v, p});
 
			//cout << v << " " << u << " " << p << '\n';
 
			d.unite(v, u);
		}
	}
 
	hld::build(0);
 
	for(int i = 0; i < q; i++) {
		int v, u; cin >> v >> u;
		v--; u--;
		ll s = hld::query_path(v, u);
		//assert(s != INF);
		assert(s != 0);
		cout << s << '\n';
 
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
