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
 
set<pii> ind;
int n, m;
 
bool isvalid(vector<vector<bool>> &a, int i, int j) {
    if(i >= 0 && i < n && j >= 0 && j < m && a[i][j]) {
        return true;
    }
    return false;
}
 
bool isp(vector<vector<bool>> &a, int i, int j) {
    if(isvalid(a, i, j + 1) && isvalid(a, i, j + 2) && isvalid(a, i + 1, j) && isvalid(a, i + 2, j) && isvalid(a, i + 3, j) && isvalid(a, i + 4, j) && isvalid(a, i + 1, j + 2) && isvalid(a, i + 2, j + 2) && isvalid(a, i + 2, j + 1)) {
        a[i][j] = false;
        a[i][j+1] = false;
        a[i][j+2] = false;
        a[i+1][j] = false;
        a[i+2][j] = false;
        a[i+3][j] = false;
        a[i+4][j] = false;
        a[i+1][j+2] = false;
        a[i+2][j+2] = false;
        a[i+2][j+1] = false;
        ind.insert(mp(i + 2, j + 2));
        return true;
    }
    return false;
}
 
bool ist(vector<vector<bool>> &a, int i, int j) {
    if(isvalid(a, i, j + 1) && isvalid(a, i, j + 2) && isvalid(a, i + 1, j + 1) && isvalid(a, i + 2, j + 1) && isvalid(a, i + 3, j + 1) && isvalid(a, i + 4, j + 1)) {
        a[i][j] = false;
        a[i][j+1] = false;
        a[i][j+2] = false;
        a[i+1][j+1] = false;
        a[i+2][j+1] = false;
        a[i+3][j+1] = false;
        a[i+4][j+1] = false;
        return true;
    }
    //###
    //.#.
    //.#.
    //.#.
    //.#.
    return false;
}
 
void solve() {
	cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m, false));
    rep0(i, n) {
        string s; cin >> s;
        rep0(j, m) {
            if(s[j] == '#') {
                a[i][j] = true;
            }
        }
    }
    //
    int t = 0, ah = 0, p = 0;
    rep0(i, n) {
        rep0(j, m) {
            if(a[i][j]) {
                if(ist(a, i, j)) {
                    t++;
                } else if(isp(a, i, j)) {
                    p++;
                }
            }
        }
    }
    //isso so acontece depois de eu ter considerado todos os "p" e todos os "t";
    for(auto [x, y] : ind) {
        if(isvalid(a, x + 1, y) && isvalid(a, x + 2, y)) {
            a[x+1][y] = false;
            a[x+2][y] = false;
            p--;
            ah++;
        }
    }
    cout << t << " " << ah << " " << p << endl;
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
 
