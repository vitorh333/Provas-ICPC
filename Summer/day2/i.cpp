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

void solve() {
	int n, t; cin >> n >> t;
	vector<vector<pii>> grafo(n);

    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
			u--;
			v--;
            grafo[v].emplace_back(u, i);
			grafo[u].emplace_back(v, i);
        }
    }


	int k; cin >> k;
	vi a(k);
	vector<vi> pos(t);

	for(int i = 0; i < k; i++) {
		int x; cin >> x;
		x--;
		a[i] = x;
		pos[x].pb(i);
	}


	vi dist(n, -1);
	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.emplace(0, 0);

	while(!pq.empty()) {
		auto [d, x] = pq.top();
		pq.pop();

		if(dist[x] != -1) continue;
		dist[x] = d;

		for(auto [y, moment]: grafo[x]) {
			auto it = lower_bound(pos[moment].begin(), pos[moment].end(), d);
			if(it != pos[moment].end()) {
				pq.emplace(*it + 1, y);
			}

		}
	}



	cout << dist[n-1] << '\n';
}

int main() {
    fastio;

	int n = 1;
	while(n--) {
		solve();
	}

    return 0;
}


