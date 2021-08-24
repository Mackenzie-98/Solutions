//@autor: Paula&Edinsson

#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
const int MAX = 25;
pii t1[MAX], t2[MAX];
vector<int> g[MAX];
bool mark[MAX][MAX];
int dist[MAX];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int dot(pii a, pii b) {
    return a.F * b.F + a.S * b.S;
}

bool in_disk(pii a, pii b, pii p) {
    return dot({a.F - p.F, a.S - p.S}, {b.F - p.F, b.S - p.S}) <= 0;
}

int cross(pii a, pii b) {
    return a.F * b.S - a.S * b.F;
}

int orient(pii a, pii b, pii c) {
    return cross({b.F - a.F, b.S - a.S}, {c.F - a.F, c.S - a.S});
}

bool on_segment(pii a, pii b, pii p) {
    return orient(a, b, p) == 0 && in_disk(a, b, p);
}

//0 si no encuentra ninguno, 1 si es t1 o 2 si es t2 y su id
pii check(int i, int j) {
    forn(k, n)if(on_segment(t1[i], t1[j], t2[k]))return {2, k};
    forn(k, n)if(k != i && k != j && on_segment(t1[i], t1[j], t1[k]))return {1, k};
    return {0, 0};
}
void init() {
    forn(i, n + 1) {
        g[i].clear();
        dist[i] = -1;
    }
}
bool ok(int i, int j) {
    return mark[i][j];
}

int main() {
#ifdef LOCAL
    freopen ( "in.txt", "r", stdin );
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin >> n;
    init();
    memset(mark, 0, sizeof mark);
    forn(i, n)cin >> t1[i].F >> t1[i].S;
    forn(i, n)cin >> t2[i].F >> t2[i].S;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            pii v = check(i, j);
            if(v.F == 0) {
                if(!ok(i, j)) {
                    g[i].pb(j), g[j].pb(i);
                    mark[i][j] = mark[j][i] = true;
                }
            } else {
                if(v.F == 1) {
                    if(ok(i, v.S))continue;
                    if(i != v.S && !ok(i, v.S)) {
                        g[i].pb(v.S), g[v.S].pb(i);
                        mark[i][v.S] = mark[v.S][i] = true;
                    }
                    if(v.S != j && !ok(v.S, j)) {
                        g[v.S].pb(j), g[j].pb(v.S);
                        mark[v.S][j] = mark[j][v.S] = true;
                    }
                }
            }
        }
    }
    bfs(0);
    cout << dist[n - 1] << endl;
    return 0;
}
