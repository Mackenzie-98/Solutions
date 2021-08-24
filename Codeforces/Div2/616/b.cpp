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
        vector<ll> a(n);
        forn(i, n) cin >> a[i];
        int pre = 0, suf = 0;
        forn(i, n) {
            if (a[i] >= i) {
                pre++;
            } else {
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= n - i - 1) {
                suf++;
            } else {
                break;
            }
        }
        if ((n - suf + 1) <= pre)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}