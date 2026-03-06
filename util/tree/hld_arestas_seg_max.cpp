namespace seg {
    static ll st[4 * MAX];
    int n;

    // ---- build ----

    void build(int p, int l, int r, int v[]) {
        if (l == r) {
            st[p] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * p, l, m, v);
        build(2 * p + 1, m + 1, r, v);
        st[p] = max(st[2 * p], st[2 * p + 1]);
    }

    void build(int _n, int v[]) {
        n = _n;
        build(1, 0, n - 1, v);
    }

    // ---- query ----

    ll query(int p, int l, int r, int i, int j) {
        if (r < i || l > j) return -INF;
        if (i <= l && r <= j) return st[p];
        int m = (l + r) / 2;
        return max(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // ---- update ----

    void update(int p, int l, int r, int i, int j, ll val) {
		if (r < i || l > j) return;
		if(l==r) {
			st[p] = val;
			return;
		}
		
		int m = (l + r) / 2;
        update(2 * p, l, m, i, j, val);
        update(2 * p + 1, m + 1, r, i, j, val);
        st[p] = max(st[2 * p], st[2 * p + 1]);
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
		if (a == b) return 0;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return max(seg::query(pos[h[a]], pos[a]), query_path(pai[h[a]], b));
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


