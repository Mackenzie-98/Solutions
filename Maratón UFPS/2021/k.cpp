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

int MX = 510;
int dist[510][510]; //Almacena la distancia a cada nodo
int di[] = {-1, 0, 0, 1};
int dj[] = {0, 1, -1, 0};
string way = "URLD";
int diR[] = {1, 0, 0, -1};
int djR[] = {0, -1, 1, 0};
string wayR = "DLRU";
string ans;
int n, m; //filas, columnas
char grid[510][510];

bool inGrid(int i, int j){
	if(i < 0) return false;
	if(i >= n) return false;
	if(j < 0) return false;
	if(j >= m) return false;
	return true;
}

bool isAble (int i, int j){
	if(grid[i][j] != '#') return true;
	return false;
}

bool isAbleR(int i, int j){
	if(grid[i][j] != '#') return true;
	return false;
}

void bfs(int i, int j) {
    queue<pii> q;
    pii u = {i, j};
    q.push(u);
    dist[u.F][u.S] = 0;
	while (q.size()) {
        u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            pii v = {u.F + di[k], u.S + dj[k]};
            if (inGrid(v.F, v.S) && isAble(v.F, v.S) && dist[v.F][v.S] == -10) {
                dist[v.F][v.S] = dist[u.F][u.S] + 1;
                q.push(v);
            }
        }
    }
}

void recons(pii u){
	//cout << dist[u.F][u.S] << " " << u.F << " " << u.S << endl;
	for (int k = 0; k < 4; k++) {
        pii v = {u.F + di[k], u.S + dj[k]};
        if (inGrid(v.F, v.S) && isAbleR(v.F, v.S) && dist[v.F][v.S] == dist[u.F][u.S] - 1) {
            ans.pb(way[k]);
            recons(v);
            break;
        }
    }
}

void init() {
    ans = "";
    for (int i = 0; i <= 500; i++) {
        for(int j = 0; j <= 500; j++){
        	dist[i][j] = -10;
        	grid[i][j] = '#';
        }
    }
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		pii starting, ending;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
				if(grid[i][j] == 'S') starting = {i, j};
				if(grid[i][j] == 'X') ending = {i, j};
			}
		}
		
		bfs(ending.F, ending.S);
		if(dist[starting.F][starting.S] == -10) cout << "No exit" << endl;
		else{
			recons(starting);
			//for(int i = ans.size() -1; i >= 0; i--){
			//	cout << ans[i];
			//}
			//cout << endl;
			cout << ans << endl;
		}
	}
}