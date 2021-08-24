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
ll solve(vector<int> v, bool mark[], int parity) {
    while (true) {
        //cout << parity << endl;
        //for (auto x : mark) cout << x << " ";
        //cout << endl;
        bool ok = 0;
        forn(i, sz(v)) {
            if (v[i] % 2 == parity && !mark[i]) {
                //cout << v[i] << endl;
                mark[i] = 1;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            break;
        } else {
            parity ^= 1;
        }
    }
    ll ans = 0;
    forn(i, sz(v)) {
        if (!mark[i]) {
            ans += v[i];
        }
    }
    return ans;
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
    vector<int> v;
    forn(i, n) {
        int x;
        cin >> x;
        v.pb(x);
    }
    sort(rall(v));
    bool mark[sz(v)];
    memset(mark, 0, sizeof mark);
    ll ans = solve(v, mark, 0);
    ans = min(ans, solve(v, mark, 1));
    cout << ans << endl;
    return 0;
}
