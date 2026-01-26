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
const ll INF = 1e18;

struct SegTree {
    int n;
    vector<ll> seg, lazy;
    bool isMax;

    SegTree(int n, bool isMax): n(n), isMax(isMax) {
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    ll merge(ll a, ll b) {
        return isMax ? max(a, b) : min(a, b);
    }

    void push(int k) {
        if (lazy[k] != 0) {
            for (int c : {2*k, 2*k+1}) {
                seg[c] += lazy[k];
                lazy[c] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void update(int k, int l, int r, int ql, int qr, ll v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            seg[k] += v;
            lazy[k] += v;
            return;
        }
        push(k);
        int m = (l + r) / 2;
        update(2*k, l, m, ql, qr, v);
        update(2*k+1, m+1, r, ql, qr, v);
        seg[k] = merge(seg[2*k], seg[2*k+1]);
    }

    ll query(int k, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return isMax ? -INF : INF;
        if (ql <= l && r <= qr)
            return seg[k];
        push(k);
        int m = (l + r) / 2;
        return merge(
            query(2*k, l, m, ql, qr),
            query(2*k+1, m+1, r, ql, qr)
        );
    }
};


void solve() {
    int n, d, k;
    cin >> n >> d >> k;

    SegTree stMax(n+d, true);
    SegTree stMin(n+d, false);

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        stMax.update(1, 0, n+d-1, l, r, 1);
        stMin.update(1, 0, n+d-1, l, r, 1);
    }

    ll bestMax = -INF, bestMin = INF;
    int dayMax = 1, dayMin = 1;

    for (int i = 0; i < n; i++) {
        ll mx = stMax.query(1, 0, n+d-1, i, i+d-1);
        ll mn = stMin.query(1, 0, n+d-1, i, i+d-1);

        if (mx > bestMax) {
            bestMax = mx;
            dayMax = i + 1;
        }
        if (mn < bestMin) {
            bestMin = mn;
            dayMin = i + 1;
        }
    }

    cout << dayMax << " " << dayMin << "\n";
}


int main() {
    fastio;

	int n; cin >> n;
	while(n--) {
		solve();
	}

    return 0;
}


