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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    set<int> st;
    forn(i, n) {
        int v;
        cin >> v;
        st.insert(v);
    }
    int mn = 1e9;
    for (int it = 0; it < 1e5; it++) {
        int x = uniform_int_distribution<int>(1e4, 1e9)(rng);
        int mx1, mx2 = 0;
        for (auto &y : st) {
            int xor1 = y ^ x;
            int xor2 = it ^ y;
            mx1 = max(mx1, xor1);
            mx2 = max(mx2, xor2);
        }
        if (mx1 < mn || mx2 < mn) {
            mn = min(mx1, mx2);
        }
    }
    cout << mn << endl;
    return 0;
}