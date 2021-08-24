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
    int n;
    cin >> n;
    vector<ll> v(n);
    forn(i, n) cin >> v[i];
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        ll a = lower_bound(all(v), x) - v.begin() - 1;
        ll b = upper_bound(all(v), x) - v.begin();
        if (a == -1)
            cout << "X ";
        else
            cout << v[a] << " ";
        if (b == n)
            cout << "X" << endl;
        else
            cout << v[b] << endl;
    }
    return 0;
}