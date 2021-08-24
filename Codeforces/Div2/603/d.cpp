#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
vector<int> G[30];
bool vis[30];
void dfs(int s) {
    vis[s] = 1;
    for (auto u : G[s]) {
        if (!vis[u]) dfs(u);
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    string arr[n];
    memset(vis, 0, sizeof vis);
    bool mark[26];
    memset(mark, 0, sizeof mark);
    forn(i, n) {
        cin >> arr[i];
        for (int j = 0; j < sz(arr[i]) - 1; j++) {
            mark[arr[i][j] - 'a'] = 1;
            int x, y;
            x = arr[i][j] - 'a';
            y = arr[i][j + 1] - 'a';
            G[x].pb(y);
            G[y].pb(x);
        }
        mark[arr[i][sz(arr[i]) - 1] - 'a'] = 1;
    }
    int components = 0;
    forn(i, 26) {
        if (!vis[i] && mark[i]) {
            dfs(i);
            components++;
        }
    }
    cout << components << endl;
    return 0;
}