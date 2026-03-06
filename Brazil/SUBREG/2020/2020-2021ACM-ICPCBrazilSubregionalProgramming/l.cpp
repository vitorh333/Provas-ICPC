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
 
#define mp make_pair
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
 
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
 
set<string> pal;
 
void norte(int i, int j, vector<vector<char>> & mat, map<pair<int, int>, set<string>> & out) {
        vector<pair<int, int>> vis;
        string atual = "";
        while(i >= 0) {
                vis.pb(mp(i, j));
                atual = atual + mat[i][j];
                sort(all(atual));
                if(pal.find(atual) != pal.end()) {
                        rep0(a, vis.size()) {
                                pair<int, int> par = vis[a];
                                out[par].insert(atual);
                        }
                }
                i--;
        }
}
void leste(int i, int j, vector<vector<char>> & mat, map<pair<int, int>, set<string>> & out) {
        vector<pair<int, int>> vis;
        string atual = "";
        while(j < mat[0].size()) {
                vis.pb(mp(i, j));
                atual = atual + mat[i][j];
                sort(all(atual));
                if(pal.find(atual) != pal.end()) {
                        rep0(a, vis.size()) {
                                pair<int, int> par = vis[a];
                                out[par].insert(atual);
                        }
                }
                j++;
        }
}
void nordeste(int i, int j, vector<vector<char>> & mat, map<pair<int, int>, set<string>> & out) {
        vector<pair<int, int>> vis;
        string atual = "";
        while(i >= 0 && j < mat[0].size()) {
                vis.pb(mp(i, j));
                atual = atual + mat[i][j];
                sort(all(atual));
                if(pal.find(atual) != pal.end()) {
                        rep0(a, vis.size()) {
                                pair<int, int> par = vis[a];
                                out[par].insert(atual);
                        }
                }
                i--;
                j++;
        }
}
void sudeste(int i, int j, vector<vector<char>> & mat, map<pair<int, int>, set<string>> & out) {
        vector<pair<int, int>> vis;
        string atual = "";
        while(i < mat.size() && j < mat[0].size()) {
                vis.pb(mp(i, j));
                atual = atual + mat[i][j];
                sort(all(atual));
                if(pal.find(atual) != pal.end()) {
                        rep0(a, vis.size()) {
                                pair<int, int> par = vis[a];
                                out[par].insert(atual);
                        }
                }
                i++;
                j++;
        }
}
 
void solve() {
        int outt = 0;
        int n, m; cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        map<pair<int, int>, set<string>> out;
        rep0(i, n) {
                string s; cin >> s;
                rep0(j, m) {
                        mat[i][j] = s[j];
                }
        }
        int p; cin >> p;
        rep0(i, p) {
                string s; cin >> s;
                sort(all(s));
                pal.insert(s);
        }
        rep0(i, n) {
                rep0(j, m) {
                        norte(i, j, mat, out);
                        leste(i, j, mat, out);
                        nordeste(i, j, mat, out);
                        sudeste(i, j, mat, out);
                }
        }
        for(auto [c, conj] : out) {
                if(conj.size() > 1) {
                        outt++;
                }
        }
        cout << outt << endl;
}
 
int main() {
    fastio;
 
        int n = 1;
        while(n--) {
                solve();
        }
 
    return 0;
}
