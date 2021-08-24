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
        ll a = 0, b = 0, lasta = 0, lastb = 0;
        int l = -1, r = n;
        bool flag = 0;
        int it = 0;

        while (l + 1 < r) {
            it++;
            // cout << l << " " << r << " " << lasta << " " << lastb << endl;
            if (!flag) {
                while (l < r - 1) {
                    l++;
                    a += v[l];
                    lasta += v[l];
                    if (lasta > lastb) {
                        lastb = 0;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) break;
            } else {
                while (r > l + 1) {
                    r--;
                    b += v[r];
                    lastb += v[r];
                    if (lastb > lasta) {
                        lasta = 0;
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) break;
            }
        }
        cout << it << " " << a << " " << b << endl;
    }
    return 0;
}