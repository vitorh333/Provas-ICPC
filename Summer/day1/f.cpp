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

int N = 4 * 1e5;
vll seg(4*N);
vll lazy(4*N);

void propagate(int k) {
	if(lazy[k] != -1) {
		seg[2*k] = lazy[k];
		seg[2*k+1] = lazy[k];
		lazy[2*k] = lazy[k];
		lazy[2*k+1] = lazy[k];
		lazy[k] = -1;
	}
}

void update(int k, int l, int r, int lq, int rq, int value) {
    if (rq < l || r < lq) return;

    if (lq <= l && r <= rq) {
        seg[k] = value;
        lazy[k] = value;
        return;
    }

    propagate(k);

    int m = (l + r) / 2;
    update(2*k, l, m, lq, rq, value);
    update(2*k+1, m+1, r, lq, rq, value);

    if (seg[2*k] == seg[2*k+1])
        seg[k] = seg[2*k];
    else
        seg[k] = -1;
}

void build(int k, int l, int r) {
    seg[k] = -1;
    lazy[k] = -1;

    if (l == r) return;

    int m = (l + r) / 2;
    build(2*k, l, m);
    build(2*k+1, m+1, r);
}


void query(int k, int l, int r, seti &s) {
	if(seg[k] != -1) {
		s.insert(seg[k]);
		return;
	}

	if(l==r) return;

	int meio = (l+r)/2;
	query(2*k, l, meio, s);
	query(2*k+1, meio+1, r, s);

}


void solve() {
	int n; cin >> n;
	vector<pii> p(n);
	vi coords;

	for(int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		p[i].first = l;
		p[i].second = r;

		coords.pb(p[i].first);
		coords.pb(p[i].second);
	}


	sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto get = [&](int x) {
		return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
	};

	int m = coords.size();
	build(1, 0, m-1);



	for(int i = 0;i < n; i++) {
		int l = get(p[i].first);
		int r = get(p[i].second);

		update(1, 0, m-1, l, r, i);
	}

	seti vis;
	query(1, 0, m-1, vis);
	cout << vis.size() << '\n';

}

int main() {
    fastio;

	int n; cin >> n;
	while(n--) {
		solve();
	}

    return 0;
}


