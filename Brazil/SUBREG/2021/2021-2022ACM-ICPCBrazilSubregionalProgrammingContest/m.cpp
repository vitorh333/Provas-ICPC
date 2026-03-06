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

// Fast IO
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

int N = 1e5 + 10;
vector<vector<int>> grafo(N);
vector<bool> vivo(N, true);
deque<int> fila;

int dfs(int v) {
    if(vivo[v]) return v;

    for(int filho: grafo[v]) {
        int k = dfs(filho);
        if(k != -1) return k;
    }

    return -1;
}

void solve() {
    int q; cin >> q;
    int chefe = 1;
    int prox = 2;
    fila.pb(1);

    while(q--) {
        int t, x; cin >> t >> x;

        if(t == 1) {
            grafo[x].push_back(prox);
            fila.pb(prox);
            prox++;
        } else {
            vivo[x] = false;

            if(x != chefe) {
                cout << chefe << '\n';
            } else {
                int k = dfs(chefe);

                if(k != -1) {
                    chefe = k;
                } else {
                    while(!fila.empty() && !vivo[fila.front()]) {
                        fila.pop_front();
                    }
                    chefe = fila.front();
                }

                cout << chefe << '\n';
            }
        }
    }
}

int main() {
    fastio;
	int n = 1;
	while(n--) {
		solve();
	}
}

