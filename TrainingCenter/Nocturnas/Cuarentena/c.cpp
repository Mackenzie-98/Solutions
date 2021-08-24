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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        sort(all(v));
        int ans = 0;
        set<pair<int, pair<int, int>>> st;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    //cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                    if (!st.count({v[i], {v[j], v[k]}}) && v[i] * v[i] + v[j] * v[j] == v[k] * v[k]) ans++, st.insert({v[i], {v[j], v[k]}});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}