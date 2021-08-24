#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define eb emplace_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {
    cerr << endl;
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}
int ini = 0, fin = 0;
const ll INF = (1ll << 60);
const int MAX = 4e6 + 5;
vector<pii> g[MAX];
long long dist[MAX];
pii pre[MAX];
int n, m;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (q.size()) {
        u = q.front();
        q.pop();
        //cout << "Nodo: " << u + 1 << endl;
        for (auto v : g[u]) {
            if (dist[v.F] == -1) {
                dist[v.F] = dist[u] + 1;
                q.push(v.F);
                pre[v.F] = {u, v.S};
                //debug(v.F + 1, pre[v.F].F + 1, pre[v.F].S);
            }else{
                if(dist[u]+1==dist[v.F]&&v.S<pre[v.F].S){
                        pre[v.F]={u,v.S};
                      //  debug(v.F + 1, pre[v.F].F + 1, pre[v.F].S);
                }
            }

        }
    }
}
void init() {
    for(int i = 0; i <= n * m + 1; i++) {
        pre[i] = {-1, INF};
        g[i].clear();
        dist[i] = -1;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    cin >> n >> m;
    vector<string> v(n);
    forn(i, n)cin >> v[i];
    int l[n + 4][m + 4], r[n + 4][m + 4], u[n + 4][m + 4], d[n + 4][m + 4];
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    memset(u, 0, sizeof u);
    memset(d, 0, sizeof d);

    init();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(v[i - 1][j - 1] == 'S')ini = (i - 1) * m + j - 1;
            if(v[i - 1][j - 1] == 'E')fin = (i - 1) * m + j - 1;
            if(v[i - 1][j - 1] == 'X')l[i][j] = l[i][j - 1] + 1;
            else l[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            if(v[i - 1][j - 1] == 'X')r[i][j] = r[i][j + 1] + 1;
            else r[i][j] = 0;
        }
    }
    for(int j = 1; j <= m; j++) {
        for(int i = 1; i <= n; i++) {
            if(v[i - 1][j - 1] == 'X')u[i][j] = u[i - 1][j] + 1;
            else u[i][j] = 0;
        }
    }
    for(int j = 1; j <= m; j++) {
        for(int i = n; i >= 1; i--) {
            if(v[i - 1][j - 1] == 'X')d[i][j] = d[i + 1][j] + 1;
            else d[i][j] = 0;
        }
    }
    forn(i, n) {
        forn(j, m) {
            if(v[i][j] != 'X') {
                int cur = i * m + j;
                //Con espacios sucios entre sí
                int rr = r[i + 1][j + 2] + 1, dd = d[i + 2][j + 1] + 1;
                if(j + rr < m && v[i][j + rr] != 'X')
                    g[cur].eb(cur + rr, 2), g[cur + rr].eb(cur, 3);
                if(i + dd < n && v[i + dd][j] != 'X')
                    g[cur].eb(cur + dd * m, 4), g[cur + dd * m].eb(cur, 1);
            }
        }
    }
    bfs(fin);
    if(dist[ini] != -1) {
        string path = "";
        int cur = pre[ini].F, aux = ini;
        while(cur != -1) {
            int ia = aux / m, ja = aux - ia * m;
            int ic = cur / m, jc = cur - ic * m;
            int ra = r[ia + 1][ja + 2] + 1, rc = r[ic + 1][jc + 2] + 1;
            //debug(ia,ja,ic,jc);
            //debug(aux,cur,ra,rc);
            if(cur < aux) {
                if(ja-rc>=0&&aux - rc == cur)path += 'L';
                else path += 'U';
            } else {
                if(ja+ra<m&&aux + ra == cur)path += 'R';
                else path += 'D';
            }
            aux = cur;
            cur = pre[cur].F;
        }
        cout << sz(path) << endl;
        cout << path << endl;
    } else cout << -1 << endl;
    return 0;
}
