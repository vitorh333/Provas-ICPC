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
const int N = 1e5+10;

vi grafo[N];
int in[N];
int out[N];
int euler[N];
int timer = 0;
vll seg(4*N);
vll lazy(4*N);


void dfs(int v, int pai) {
	in[v] = timer;
	euler[timer] = v;
	timer++;

	for(int u : grafo[v]) {
		if(u != pai) {
			dfs(u, v);
		}
	}

	out[v] = timer -1;

}

void propagate(int k, int l, int r) {
	if(lazy[k] != -1) {
		seg[k] += (r-l+1) * lazy[k];
 
		if(l!=r) {
			lazy[2*k] = lazy[k];
			lazy[2*k+1] = lazy[k];
		}
 
		lazy[k] = -1;
	}
}


void build(int k, int l, int r, vll &euler) {
	if(l==r) {
		seg[k] = euler[r];
		return;
	}

	int meio = (l+r)/2;
	build(2*k, l, meio, euler);
	build(2*k+1, meio+1, r, euler);

	seg[k] = seg[2*k] + seg[2*k+1];
}

ll query(int k, int l, int r, int lq, int rq) {
	propagate(k, l, r);
	if(l > rq || lq > r) {
		return 0;
	}

	if(l >= lq && r <= rq) {
		return seg[k];
	}

	int meio = (l+r)/2;
	return query(2*k, l, meio, lq, rq) + query(2*k+1, meio+1, r, lq, rq);
}

void update(int k, int l, int r, int lq, int rq, ll value) {
	propagate(k, l, r);

	if(lq > r || l > rq) {
		return;
	}

	if(l >= lq && r <= rq) {
		seg[k] += (r-l+1)*value;
		if(l!=r) {
			lazy[2*k] = value;
			lazy[2*k+1] = value;
		}

		return;
	}

	int meio = (l+r)/2;
	update(2*k, l, meio, lq, rq, value);
	update(2*k+1, meio+1, r, lq, rq, value);
	seg[k] = seg[2*k] + seg[2*k+1];

}





void solve() {
	int n; cin >> n;
	for(int i = 0; i < n-1; i++) {
		v--;
		u--;

		int u, v; cin >> u >> v;
		grafo[v].pb(u);
		grafo[u].pb(v);
	}
	
	dfs(0, -1);
	
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		int t, x; cin >> t >> x;
		x--;
		if(t==1) {
			update(1, 0, n-1, in[x], out[x], 1);
		}

		if(t==2) {
			update(1, 0, n-1, in[x], out[x], 0);

		}

		if(t==3) {
			cout << query(1, 0, n-1, in[x], in[x]) << '\n';

		} 
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


