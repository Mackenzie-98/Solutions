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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    vector<int> pre(n);
    pre[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre[i] = min(pre[i - 1], v[i]);
    }
    int ans = 0;
    forn(i, n) {
        if (pre[i] >= v[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}