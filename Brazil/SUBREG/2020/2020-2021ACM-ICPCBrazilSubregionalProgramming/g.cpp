#include "bits/stdc++.h"
using namespace std;
 
#define endl '\n'
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
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int maxx = 100;
    int saldo = 100;
    rep0(i, n) {
        int x; cin >> x;
        if(saldo + x > maxx) {
            maxx = saldo + x;
        }
        saldo += x;
    }
    cout << maxx << endl;
}
