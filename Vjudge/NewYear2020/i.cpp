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
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MAX = 626;
ll g[MAX][MAX];
int n;

void floydWarshall() {
    for (int k = 0; k < n * n; k++)
        for (int i = 0; i < n * n; i++)
            for (int j = 0; j < n * n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init() {
    for (int i = 0; i <= n * n; i++) {
        for (int j = 0; j <= n * n; j++) {
            g[i][j] = (i == j ? 0 : INF);
        }
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int f, t;
    int test = 0;
    while (cin >> n >> f >> t && !(n == 0 && f == 0 && t == 0)) {
        test++;
        ll mat[n][n];
        forn(i, n) {
            forn(j, n) {
                cin >> mat[i][j];
            }
        }
        vector<pii> friends;
        forn(i, f) {
            int x, y;
            cin >> x >> y;
            friends.pb({x, y});
        }
        init();
        forn(i, n) {
            forn(j, n) {
                int cur = i * n + j;
                g[cur][cur] = 0;
                if (i != 0) {
                    g[cur][cur - n] = mat[i][j];
                }
                if (j != 0) {
                    g[cur][cur - 1] = mat[i][j];
                }
                if (i != n - 1) {
                    g[cur][cur + n] = mat[i][j];
                }
                if (j != n - 1) {
                    g[cur][cur + 1] = mat[i][j];
                }
            }
        }
        floydWarshall();
        ll mn = INF;
        int ansx = 0, ansy = 0;
        forn(i, n) {
            forn(j, n) {
                ll cost = 0;
                bool ok = 0;
                // if (f < 3) {
                forn(k, sz(friends)) {
                    if (abs(friends[k].F - i) + abs(friends[k].S - j) <= t) {
                        int cur = friends[k].F * n + friends[k].S;
                        cost += g[cur][i * n + j];
                        ok = 1;
                    } else {
                        ok = 0;
                        break;
                    }
                }
                if (cost < mn && ok) {
                    mn = cost;
                    ansx = i;
                    ansy = j;
                }

                // } else {
                // for (int a = 0; a < sz(friends) - 2; a++) {
                //     for (int b = a + 1; b < sz(friends) - 1; b++) {
                //         for (int c = b + 1; c < sz(friends); c++) {
                //             ok = 0;
                //             cost = 0;
                //             if (abs(friends[a].F - i) + abs(friends[a].S - j) <= t && abs(friends[b].F - i) + abs(friends[b].S - j) <= t && abs(friends[c].F - i) + abs(friends[c].S - j) <= t) {
                //                 cost += g[friends[a].F * n + friends[a].S][i * n + j];
                //                 cost += g[friends[b].F * n + friends[b].S][i * n + j];
                //                 cost += g[friends[c].F * n + friends[c].S][i * n + j];
                //                 ok = 1;
                //             }
                //             if (cost < mn && ok) {
                //                 mn = cost;
                //                 ansx = i;
                //                 ansy = j;
                //             }
                //         }
                //     }
                // }
                // }
            }
        }
        if (mn != INF) {
            cout << "Case #" << test << ": Selected city (" << ansx << "," << ansy << ") with minimum cost " << mn << "." << endl;
        } else {
            cout << "Case #" << test << ": Impossible." << endl;
        }
    }
    return 0;
}