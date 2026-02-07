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
using i128 = __int128_t;

// multiplicação segura
ll mod_mul(ll a, ll b, ll MOD) {
	return (i128)a*b % MOD;
}

// Exponenciação rápida
ll mod_pow(ll a, ll d, ll MOD) {
	ll res = 1;
	while(d) {
		if(d & 1) res = mod_mul(res, a, MOD);
		a = mod_mul(a, a, MOD);
		d >>= 1;
	}

	return res;
}

//funcao otimizada para calculo de primalidade
bool isPrime(ll n) {
	if(n < 2) return false;
	for(ll p: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if(n % p == 0) return n==p;
	}

	ll d = n-1, s = 0;
	while((d & 1) == 0) {
		d >>= 1;
		s++;
	}

	for(ll a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if(a % n == 0) continue;
		
		ll x = mod_pow(a, d, n);
		if(x==1 || x==n-1) continue;

		bool composite = true;
		for(int i = 1; i < s; i++) {
			x = mod_mul(x, x, n);
			if(x==n-1) {
				composite = false;
				break;
			}
		}
		if(composite) return false;
	}

	return true;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//funcao de dispersao da sequencia de pollard
ll f(ll x, ll c, ll MOD) {
	return (mod_mul(x, x, MOD) +c) % MOD;
}

// daqui para baixo, magia
ll pollard_rho(ll n) {
	if(n % 2 == 0) return 2;
	if(n % 3 == 0) return 3;

	ll x = uniform_int_distribution<ll>(2, n-2)(rng);
	ll y = x;
	ll c = uniform_int_distribution<ll>(1, n-1)(rng);
	ll d = 1;

	while(d==1) {
		x = f(x, c, n);
		y = f(f(y, c, n), c, n);
		d = gcd(abs(x-y), n);
	}

	if(d==n) return pollard_rho(n);
	return d;
}

void factor(ll n, map<ll, int> &fatores) {
	if(n==1) return;
	if(isPrime(n)) {
		fatores[n]++;
	}
	else {
		ll d = pollard_rho(n);
		factor(d, fatores);
		factor(n/d, fatores);
	}
}



void solve() {
	ll m, n, d; cin >> m >> n >> d;
	vll v(n);
	for(int i = 0; i < n; i++) {
		ll k; cin >> k;
		v[i] = k;
	}

	for(int i = 0 ; i < d; i++) {
		ll a, b, c; cin >> a >> b >> c;
	}
	
	setll resp;
	for(auto k : v) {
		map<ll, int> fatores;
		factor(k, fatores);
		for(auto[x, p] : fatores) {
			resp.insert(x);
		}
	}

	for(auto x : resp) {
		cout << x << " ";
	}

	cout << '\n';
}

int main() {
    fastio;

	int n = 1;
	while(n--) {
		solve();
	}

    return 0;
}


