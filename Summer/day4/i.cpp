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
ll prodVetorial(const pll& A, const pll& B, const pll &C) {
	return (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);

}

vector<pll> convexhull(vector<pll> &pontos) {

	sort(pontos.begin(), pontos.end());
	pontos.erase(unique(pontos.begin(), pontos.end()), pontos.end());

	if (pontos.size() <= 1)
    	return pontos;

	if (pontos.size() == 2) {
    	if (pontos[0] == pontos[1])
        	return {pontos[0]};
    	return pontos;
	}


	if (pontos.size() <= 2) return pontos;

	vector<pll> inferiores, superiores;
	
	sort(pontos.begin(), pontos.end());
    pontos.erase(unique(pontos.begin(), pontos.end()), pontos.end());

	for(auto & p : pontos) {
		while(inferiores.size() >= 2 && prodVetorial(inferiores[inferiores.size()-2], inferiores[inferiores.size()-1], p) <= 0) {
			inferiores.pop_back();
		}

		inferiores.pb(p);
	}
	
	for(int i = (int) pontos.size()-1; i >= 0;i--){
		auto &p = pontos[i];
		while(superiores.size() >= 2 && prodVetorial(superiores[superiores.size()-2], superiores[superiores.size()-1], p) <= 0) {
			superiores.pop_back();
		}

		superiores.pb(p);
	}

	inferiores.pop_back();
	superiores.pop_back();

	inferiores.insert(inferiores.end(), superiores.begin(), superiores.end());

	return inferiores;
}

void solve() {
	while(true) {
		int n; cin >> n;
		if(n==0) {
			return;
		}

		vector<pll> pontos;
		for(int i = 0; i < n; i++) {
			ll x, y; cin >> x >> y;
			pontos.pb({x, y});
		}

		vector<pll> resp = convexhull(pontos);
		cout << (int) resp.size() << '\n';
		for(int i = 0; i < (int) resp.size(); i++) {
			cout << resp[i].first << " " << resp[i].second << '\n';
		}
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


