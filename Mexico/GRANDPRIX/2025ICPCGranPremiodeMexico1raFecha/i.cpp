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
#define fastio ios::sync_with_stdio(false); cin.tie(0);

int n, q;
vi hab;
vector<vi> grafo;
vector<vector<pii>> querys;
vi resp;

map<int,int> dfs(int v, int pai) {
    map<int,int> freq;

    for (int vizinho : grafo[v]) {
        if (vizinho == pai) continue;

        map<int,int> freqVizinho = dfs(vizinho, v);

        if (freqVizinho.size() > freq.size()) swap(freq, freqVizinho);

        for (auto &pr : freqVizinho) {
            freq[pr.first] += pr.second;
        }
    }

    freq[hab[v]] += 1;

    for (auto &qq : querys[v]) {
        int color = qq.first;
        int idx = qq.second;
        auto it = freq.find(color);
        resp[idx] = (it == freq.end() ? 0 : it->second);
    }

    return freq;
}

void solve() {
    cin >> n >> q;
    hab.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> hab[i];

    grafo.assign(n, vi());
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        grafo[x].pb(y);
        grafo[y].pb(x);
    }

    querys.assign(n, vector<pii>());
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        --x;
        querys[x].pb({k, i});
    }

    resp.assign(q, 0);
    dfs(0, -1);

    for (int i = 0; i < q; ++i) cout << resp[i] << '\n';
}

int main() {
    fastio;
    int t = 1;
    while (t--) solve();
    return 0;
}

