vector<bool> vis(n, false);
vector<int> tin(n, -1), low(n-1	);
int timer = 0;

void dfs(int v, int p) {
	vis[v] = true;
	tin[v] = low[v] = timer++;
	bool parent_skipped = false;
	for(int vizinho : g[v]) {
		if(vizinho == p && !parent_skipped) {
			parent_skipped = true;
			continue;
		}

		if(vis[vizinho]) {
			low[v] = min(low[v], tin[vizinho]);
		} else {
			dfs(vizinho, v);
			low[v] = min(low[v], low[vizinho]);
			if(low[to] > tin[v]) {
				//IS BRIDGE
			}
		}
	}
}
