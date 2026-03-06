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

ll INF = (ll) 1e18;
vector<vector<pll>> grafo((ll) 1e5+10);
ll dist[(ll)1e5+10][2];

void setDist(int n) {
	for(int i = 0; i < n; i++) {
		dist[i][1] = INF;
		dist[i][0] = INF;
	}
}


void djistrka(int vini) {
	priority_queue<tll, vector<tll>, greater<tll>> pq;
	pq.push({0, 0, 0});

	while(pq.size()) {
		auto[d, v, cupom] = pq.top();
		pq.pop();
		
		if(dist[v][cupom] < d) continue;

		for(auto[vizinho, p] : grafo[v]) {
			if(dist[vizinho][cupom] > d + p) {
				dist[vizinho][cupom] = d+p;
				pq.push({d+p, vizinho, cupom});
			}

			if(cupom == 0 && dist[vizinho][1] > d+p/2) {
				dist[vizinho][1] = d + p/2;
				pq.push({d+p/2, vizinho, 1});
			}
		}
	}
}


void solve() {
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int v, u, p; cin >> v >> u >> p;
		v--;
		u--;
		grafo[v].pb({u, p});
	}

	setDist(n);
	djistrka(0);
	cout << dist[n-1][1] << '\n';
}

int main() {
    fastio;

	int n = 1;
	while(n--) {
		solve();
	}

    return 0;
}


