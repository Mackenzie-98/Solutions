#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define sz size()
#define eps 0.000001
#define oo 2000000007
#define endl '\n'
#define bg begin()
#define nd end()
#define up upper_bound
#define lw lower_bound
#define debug(x) #x << " = " << x << "; "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;



struct edge {
    int v; ll w;

    bool operator < (const edge &o) const {
        return o.w < w; //invertidos para que la pq ordene de < a >
    }
};

const int MX = 1e5+5; //Cantidad maxima de nodos
vector<edge> g[MX]; //Lista de adyacencia
vector<bool> vis; //Marca los nodos ya visitados
vector<ll> dist; //Almacena la distancia a cada nodo
int pre[MX]; //Almacena el nodo anterior para construir las rutas
int n, m, cant; //Cantidad de nodos y aristas

void dijkstra(int u) {
    priority_queue<edge> pq;
    pq.push({u, 0});
    dist[u] = cant;
    
    while (pq.size()) {
    	u = pq.top().v; pq.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (auto &ed : g[u]) {
            	int v = ed.v;
                //cout<< u << " " << v << " " << dist[v] << " " << dist[u] <<  " " <<  ed.w << " " <<(ed.w*dist[u]+99)/100 << " " << dist[u] - (ed.w*dist[u] +99)/100<< endl;
                if(vis[v]) continue;
                if (dist[v] < dist[u] - (ed.w*dist[u] +99)/100) {
                    dist[v] = dist[u] - (ed.w*dist[u] +99)/100;
                    pq.push({v, -dist[v]});
                }
            }
        }
    }
}

void init() {
    vis.assign(n+1, false);
    dist.assign(n+1, 0);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int uo, uf, a, b, c;
	init();
	cin >> uo >> uf >> cant;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	//cout << dist[uf] << endl;
	dijkstra(uo);
	cout << dist[uf] << endl;
}