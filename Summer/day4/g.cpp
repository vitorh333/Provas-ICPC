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
ll MOD = 1e9+7;
ll fact[1000000+300];

ll powpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll comb(ll k) {
	return (fact[2*k] * powpow(fact[k] * fact[k], MOD -2)) % MOD;
}

void solve() {
	int n; cin >> n;

	if(n%2==1) {
		cout << 0 << '\n';
	}

	else {
		fact[0] = 1;
		int k = n/2;
		for(int i = 1; i <= 2 * k; i++) {
			fact[i] = (fact[i-1] * i) % MOD;
		}
		ll resp = (comb(k) * powpow(k+1, MOD -2)) % MOD;
		cout << resp << '\n';
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


