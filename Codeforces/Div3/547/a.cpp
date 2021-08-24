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
int n, m;
int dfs(int x, int cnt, int &ans) {
    if (x == m) {
        ans = cnt;
        return 1;
    }
    if (x > m) return 0;
    if (dfs(2 * x, cnt + 1, ans)) {
        return 1;
    }
    if (dfs(3 * x, cnt + 1, ans)) {
        return 1;
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif

    cin >> n >> m;
    int ans = -1;
    dfs(n, 0, ans);
    cout << ans << endl;
    return 0;
}