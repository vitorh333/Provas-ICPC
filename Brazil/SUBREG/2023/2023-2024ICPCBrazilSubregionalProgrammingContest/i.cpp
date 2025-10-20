#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
 
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
#define rep1(i, a) rep(i, 1, a + 1)
#define repr(i, a, b) for (int i = (b) - 1; i >= (a); i--)
 
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
 
void solve() {
    ll n; cin >> n;
    ll out = 0;
    vll pares(n + 1);
    vll imp(n + 1);
    vll pref(n + 1);
    rep(i, 1, n + 1) {
        ll x; cin >> x;
        if(x == 1LL) {
            pref[i] = pref[i - 1] + 1;
        } else {
            pref[i] = pref[i - 1];
        }
    }
    rep(i, 1, n + 1) {
        if(pref[i] % 2 == 0) {
            pares[i] = pares[i - 1] + 1;
            imp[i] = imp[i - 1];
        } else {
            imp[i] = imp[i - 1] + 1;
            pares[i] = pares[i - 1];
        }
    }
    rep(i, 1, n + 1) {
        if(pref[i] % 2) {
            out += pares[i - 1];
        } else {
            out += imp[i - 1];
        }
    }
    out += imp[n];
    cout << out << endl;
}
 
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--) {
	    solve();
    }
 
    return 0;
}
