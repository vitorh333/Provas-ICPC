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
	int depth[MAX];
	int v_pos[MAX];

	void build_hld(int k, int p = -1, int f = 1) {
		if(p==-1) depth[k] = 0;
		else depth[k] = depth[p] +1;
		v_pos[t] = k;
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
	

	int get_dist(int a, int b) {
		return depth[a] + depth[b] - 2 * depth[lca(a, b)];
    }

	int kth_ancestor(int u, int k) {
        if (k < 0) return -1;
        while (true) {
            int head = h[u];
            int pos_in_chain = pos[u] - pos[head];
            if (k <= pos_in_chain) return v_pos[pos[u] - k];
            k -= (pos_in_chain + 1);
            u = pai[head];
        }
    }

	int kth_path(int u, int v, int k) {
        int lc = lca(u, v);
        int d1 = depth[u] - depth[lc];
        int d2 = depth[v] - depth[lc];

        if (k <= d1) return kth_ancestor(u, k);
        if (k <= d1 + d2) return kth_ancestor(v, d1 + d2 - k);

        return -1; // k maior que o caminho
    }


}

