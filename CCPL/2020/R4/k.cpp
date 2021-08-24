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
    int cases = 0;
    while (t--) {
        cases++;
        int n;
        cin >> n;
        vector<int> v(n);
        ll cost1 = 0, cost2 = 0;
        forn(i, n) cin >> v[i], cost1 += (v[i] + 30) / 30, cost2 += (v[i] + 60) / 60;
        cout << "Case " << cases << ": ";
        if (10 * cost1 < 15 * cost2)
            cout << "Mile " << 10 * cost1 << endl;
        else if (15 * cost2 < 10 * cost1)
            cout << "Juice " << 15 * cost2 << endl;
        else
            cout << "Mile Juice " << 15 * cost2 << endl;
    }
    return 0;
}