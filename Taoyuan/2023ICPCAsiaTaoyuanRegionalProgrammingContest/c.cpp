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

// Fast IO
#define fastio ios::sync_with_stdio(false); cin.tie(0);
int N = 1e6+10;
vector<pll> seg(4*N);
// 0 soma, 1 validos
vll lazy(4*N);

// É GUERRA LENNER
// É GUERRA BARALHAS
// É GUERAAAAAAAAAAAAAAAAAAAAAAA

void propagate(int k, int l, int r) {
	if(lazy[k] != 0) {
		seg[k].first = seg[k].second - seg[k].first;

		if(l!=r) {
			lazy[2*k] ^= 1;
			lazy[2*k+1] ^= 1;
		}

		lazy[k] = 0;
	}
}


void update(int k, int l, int r, int lq, int rq) {
	propagate(k, l, r);

	if(lq > r || l > rq) {
		return;
	}

	if(l >= lq && r <= rq) {
		seg[k].first = seg[k].second -seg[k].first;
		if(l != r) {
			lazy[2*k] ^= 1;
			lazy[2*k+1] ^= 1;

		}

		return;
	}

	int meio = (l+r)/2;
	update(2*k, l, meio, lq, rq);
	update(2*k+1, meio+1, r, lq, rq);
	seg[k].first = seg[2*k].first + seg[2*k+1].first;
	seg[k].second = seg[2*k].second + seg[2*k+1].second;
}

ll query(int k, int l, int r, int lq, int rq) {
	propagate(k, l, r);
	if(l > rq || lq > r) {
		return 0;
	}
	if(l >= lq && r <= rq) {
		return seg[k].first;
	}

	int meio = (l+r)/2;
	return query(2*k, l, meio, lq, rq) + query(2*k+1, meio+1, r, lq, rq);
}

void build(int k, int l, int r, vector<ll> &v) {
    if (l == r) {
		if(v[l] == -1) {
			seg[k].first = 0;
			seg[k].second = 0;
		} else {
			seg[k].first = v[l];
			seg[k].second = 1;
		}

		return;
    }

    int meio = (l + r) / 2;
    build(2*k, l, meio, v);
    build(2*k+1, meio+1, r, v);

    seg[k].first = seg[2*k].first + seg[2*k+1].first;
	seg[k].second = seg[2*k].second + seg[2*k+1].second;

}

void solve() {
	int n, q; cin >> n >> q;
	ll soma = 0;
	vll v(n);
	for(int i = 0; i < n; i++) {
		ll k, p; cin >> k >> p;
		soma += p;
		v[i] = k;
	}

	build(1, 0, n-1, v);

	for(int i = 0; i < q; i++) {
		char t; cin >> t;
		if(t=='W') {
			int lq, rq; cin >> lq >> rq;
			update(1, 0, n-1, lq, rq);
		} else {
			int c; cin >> c;
			soma += c * query(1, 0, n-1, 0, n-1);
		}
	}

	cout << soma << '\n';
}

int main() {
    fastio;

	int n = 1;
	while(n--) {
		solve();
	}

    return 0;
}



