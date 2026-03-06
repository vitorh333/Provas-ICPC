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

// Pair
#define pii pair<int,int>

// Fast IO
#define fastio ios::sync_with_stdio(false); cin.tie(0);

const ll INF = 100000000000;

void build(int k, int l, int r, vll &seg, vll &a) {
	if(l == r) {
		seg[k] = a[l];
		return;
	}

	int meio = (l + r) / 2;
	build(2*k, l, meio, seg, a);
	build(2*k+1, meio + 1, r, seg, a);

	seg[k] = min(seg[2*k], seg[2*k+1]);
}


ll query(int k, int l, int r, int lq, int rq, ll value, vll &seg) {
    if (r < lq || l > rq || seg[k] >= value)
        return INF;

    if (l == r)
        return l;

    int meio = (l + r) / 2;

    ll left = query(2*k, l, meio, lq, rq, value, seg);
    if (left != INF)
        return left;

    return query(2*k+1, meio+1, r, lq, rq, value, seg);
}

void solve() {
    int n; cin >> n;
	vll seg(4*n);
	
	vll a(n);
	vll b(n);

	for(int i = 0; i < n; i++) {
		ll k; cin >> k;
		a[i] = k;
	}

	for(int i = 0; i < n; i++) {
		ll k; cin >> k;
		b[i] = k;
	}

	build(1, 0, n-1, seg, a);

	vi resp;

	for(int i = 0; i < n-1; i++) {
		ll r = query(1, 0, n-1, i+1, n-1, a[i], seg);
		
		//cout << r << " ";

		if(r == INF) {
			resp.pb(i+1);
		} else {
			if(b[i] > b[r]) {
				resp.pb(i+1);
			}
		}
	}

	resp.pb(n);
	cout << (int) resp.size() << endl;

	for(int i = 0; i < (int) resp.size(); i++) {
		cout << resp[i] << " ";
	}

	cout << endl;
}

int main() {
    fastio;

    int n = 1;
    while(n--) {
        solve();
    }

    return 0;
}





