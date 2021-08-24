/**
 * @author: Mackenzie
**/
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
int n, m;
const ll INF = 1e9;
const int MAX = 405;
ll g[MAX][MAX];
char mat[MAX][MAX];
void floydWarshall() {
    for (int k = 0; k < max(n * n, m * m); k++)
        for (int i = 0; i < max(n * n, m * m); i++)
            for (int j = 0; j < max(n * n, m * m); j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init() {
    for (int i = 0; i <= max(n * n, m * m); i++) {
        for (int j = 0; j <= max(n * n, m * m); j++) {
            g[i][j] = (i == j ? 0 : INF);
        }
    }
}
bool ok(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin >> n >> m;
    forn(i, n) {
        string s;
        cin >> s;
        forn(j, m) {
            mat[i][j] = s[j];
        }
    }
    init();
    forn(i, n) {
        forn(j, m) {
            if (mat[i][j] != '#') {
                int cur = i * m + j;
                g[cur][cur] = 0;
                if (ok(i, j + 1) && mat[i][j + 1] == '.') {
                    g[cur][cur + 1] = 1;
                }
                if (ok(i, j - 1) && mat[i][j - 1] == '.') {
                    g[cur][cur - 1] = 1;
                }
                if (ok(i + 1, j) && mat[i + 1][j] == '.') {
                    g[cur][cur + m] = 1;
                }
                if (ok(i - 1, j) && mat[i - 1][j] == '.') {
                    g[cur][cur - m] = 1;
                }
            }
        }
    }
    floydWarshall();
    ll mx = 0;
    forn(i, n) {
        forn(j, m) {
            if (mat[i][j] != '#') {
                forn(a, n) {
                    forn(b, m) {
                        if (mat[a][b] != '#') {
                            ll dis = g[i * m + j][a * m + b];
                            //cout << "[" << i * m + j << ", " << a * m + b << " ] = " << dis << endl;
                            if (dis != INF) mx = max(mx, dis);
                        }
                    }
                }
            }
        }
    }
    cout << mx << endl;
    return 0;
}