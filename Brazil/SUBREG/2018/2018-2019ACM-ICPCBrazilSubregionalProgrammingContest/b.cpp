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

const int N = 101;
int est[N][N];

void solve() {
	int n; cin >> n;
	vector<pii> pos;
	for(int i = 0; i < n; i++) {
		int l, c; cin >> l >> c;
		if(l==c) {
			// KARALHO COMO PODE O CARA SER BURRO ASSIM
			//cout << "Yes" << '\n';
			cout << "Y" << '\n';
			return;
		} else pos.pb({l, c});
	}

	//ANIMAL
	for(int i = 0; i < N; i++) {
		est[0][i] = -1;
		est[i][0] = -1;
		est[i][i] = -1;
	}

	for(int i = 1; i < N; i++) {
		for(int j = 1; j < N; j++) {
			if(i==j) continue;
			set<int> trans;
			int ii = i-1;
			int jj = j-1;
			while(jj >= 0) {
				trans.insert(est[i][jj]);
				jj--;		
			}

			while(ii >= 0) {
				trans.insert(est[ii][j]);
				ii--;

			}

			ii = i-1;
			jj = j-1;
			while(ii >= 0 and jj >= 0) {
				trans.insert(est[ii][jj]);
				jj--;
				ii--;
			}
			
			int mex = 0;
			while(trans.find(mex) != trans.end()) {
				mex++;
			}

			est[i][j] = mex;
		}
	}

	//for(int i = 0; i < 11; i++) {
		//for(int j = 0; j < 11; j++) {
			//cout << est[i][j] << " ";
		//}

		//cout << '\n';
	//}

	int xxor = 0;
	for(auto [l, c] : pos) {
		xxor ^= est[l][c];
	}

	if(xxor != 0) cout << "Y" << '\n';
	else cout << "N" << '\n';

}

int main() {
    fastio;

	int n = 1;
	while(n--) {
		solve();
	}

    return 0;
}


