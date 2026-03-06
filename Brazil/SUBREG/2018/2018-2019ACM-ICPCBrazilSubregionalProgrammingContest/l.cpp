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


// Ordenação estilo Python .sort()
#define sortarr(x) sort(all(x))

// Map estilo Python dict
#define dict(key, value) map<key, value>
#define udict(key, value) unordered_map<key, value>

// Pair
#define pii pair<int,int>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
// Fast IO
#define fastio ios::sync_with_stdio(false); cin.tie(0);

const int MAX = 1e5+10;

namespace seg {
    static ll st[4 * MAX];
    static ll lazy[4 * MAX];
    int n;

    void push(int p, int l, int r) {
        if (lazy[p] == 0) return;

        st[p] += (r - l + 1) * lazy[p];

        if (l != r) {
            lazy[2 * p]     += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    // ---- build ----

    void build(int p, int l, int r, int v[]) {
        lazy[p] = 0;
        if (l == r) {
            st[p] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * p, l, m, v);
        build(2 * p + 1, m + 1, r, v);
        st[p] = st[2 * p] + st[2 * p + 1];
    }

    void build(int _n, int v[]) {
        n = _n;
        build(1, 0, n - 1, v);
    }

    // ---- query ----

    ll query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (r < i || l > j) return 0;
        if (i <= l && r <= j) return st[p];
        int m = (l + r) / 2;
        return query(2 * p, l, m, i, j)
             + query(2 * p + 1, m + 1, r, i, j);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // ---- update ----

    void update(int p, int l, int r, int i, int j, ll val) {
        push(p, l, r);
        if (r < i || l > j) return;
        if (i <= l && r <= j) {
            lazy[p] += val;
            push(p, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(2 * p, l, m, i, j, val);
        update(2 * p + 1, m + 1, r, i, j, val);
        st[p] = st[2 * p] + st[2 * p + 1];
    }

    void update(int l, int r, ll val) {
        update(1, 0, n - 1, l, r, val);
    }
}

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	ll query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	ll query_subtree(int a) {
		return seg::query(pos[a], pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		seg::update(pos[a], pos[a]+sz[a]-1, x);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}

	int kth_up(int a, int k) {
	
		while (true) {
		int head = h[a];
		int dist = pos[a] - pos[head];

		if (k <= dist)
			return inv[pos[a] - k];

		k -= dist + 1;
		a = pai[head];
		
		}
	}

	int kth_path(int a, int b, int k) {
		int l = lca(a, b);

		int distA = pos[a] - pos[l];
		int distB = pos[b] - pos[l];

		int len = distA + distB + 1;

		if (k <= distA + 1)
			return kth_up(a, k-1);
		else
			return kth_up(b, len-k);
	}
}



void solve() {
	int n, q; cin >> n >> q;
	for(int i = 0; i < n-1; i++) {
		int v, u; cin >> v >> u;
		v--;
		u--;
		hld::g[v].pb(u);
		hld::g[u].pb(v);
	}
	
	for(int i = 0; i < n; i++) {
		hld::peso[i] = 0;
	}

	hld::build(0);

	for(int i = 0; i < q; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		hld::update_path(a, b, 1);
		cout << hld::query_path(c, d) << '\n';
		hld::update_path(a, b, -1);
	}
}

int main() {
    fastio;

	int n = 1;
	while(n--) {
		solve();
	}

    return 0;
}


