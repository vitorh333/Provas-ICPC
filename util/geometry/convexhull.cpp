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


