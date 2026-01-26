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
int xc = 1;

ll prodVetorial(const pll& A, const pll& B, const pll &C) {
	return (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);

}

bool onSegment(const pll &A, const pll &B, const pll &P) {
    ll minX = min(A.first, B.first), maxX = max(A.first, B.first);
    ll minY = min(A.second, B.second), maxY = max(A.second, B.second);
    ll cross = prodVetorial(A, B, P);
    return cross == 0 && P.first >= minX && P.first <= maxX && P.second >= minY && P.second <= maxY;
}


bool dentroConvex(const vector<pll>& hull, pll p) {
    int n = hull.size();
    if (n < 3) return false;

    for (int i = 0; i < n; i++) {
        int j = (i+1) % n;
        if (onSegment(hull[i], hull[j], p)) return true;
        if (prodVetorial(hull[i], hull[j], p) < 0) return false;
    }
    return true;
}


vector<pll> convexHull(vector<pll> &pontos) {

	sort(pontos.begin(), pontos.end());

	if (pontos.size() <= 1)
    	return pontos;

	if (pontos.size() == 2) {
    	if (pontos[0] == pontos[1])
        	return {pontos[0]};
    	return pontos;
	}


	if (pontos.size() <= 2) return pontos;

	vector<pll> inferiores, superiores;
	

	for(auto & p : pontos) {
		while(inferiores.size() >= 2 && prodVetorial(inferiores[inferiores.size()-2], inferiores[inferiores.size()-1], p) < 0) {
			inferiores.pop_back();
		}

		inferiores.pb(p);
	}
	
	for(int i = (int) pontos.size()-1; i >= 0;i--){
		auto &p = pontos[i];
		while(superiores.size() >= 2 && prodVetorial(superiores[superiores.size()-2], superiores[superiores.size()-1], p) < 0) {
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
		int p, l, c; cin >> p >> l >> c;
		if(p == 0 and l == 0 and c == 0) {
			return;
		}
		vector<pll> policiais;
		vector<pll> ladroes;
		vector<pll> cidadaos;

		for(int i = 0; i < p; i++) {
			ll x, y; cin >> x >> y;
			policiais.pb({x, y});
		}
	
		for(int i = 0; i < l; i++) {
			ll x, y; cin >> x >> y;
			ladroes.pb({x, y});
		}
		for(int i = 0; i < c; i++) {
			ll x, y; cin >> x >> y;
			cidadaos.pb({x, y});
		}

		vector<pll> cp = convexHull(policiais);
		vector<pll> cl = convexHull(ladroes);
		
		bool podeSafe = (cp.size() > 2);
		bool podeRobbed = (cl.size() > 2);
		cout << "Data set " << xc << ":" << '\n';
		for (auto &p : cidadaos) {
			bool safe = podeSafe && dentroConvex(cp, p);
			bool robbed = (!safe && podeRobbed && dentroConvex(cl, p));
            cout << "     Citizen at (" << p.first << "," << p.second << ") is ";
			if (safe) cout << "safe.\n";
            else if (robbed) cout << "robbed.\n";
            else cout << "neither.\n";
        }

        cout << '\n';

		xc++;
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


