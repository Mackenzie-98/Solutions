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
const int MAXN = 1e5 + 5;
int ft[MAXN];
void upd(int i0, int v) {
    for (int i = i0 + 1; i <= MAXN; i += i & -i) ft[i] += v;
}
int get(int i0) {
    int r = 0;

    for (int i = i0; i; i -= i & -i) r += ft[i];
    return r;
}
int get_sum(int i0, int i1) {
    return get(i1) - get(i0);
}
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
        memset(ft, 0, sizeof ft);
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        forn(i, n) {
            int v;
            cin >> v;
            mp[v] = i;
        }
        int last = 0;
        ll ans = 0, cnt = 0;
        forn(i, m) {
            int cur;
            cin >> cur;
            //cout << cur << endl;
            if (mp[cur] <= last) {
                ans++;
                cnt++;
            } else {
                int x = mp[cur] - cnt;
                //cout << x << " ";
                ans += 2 * x + 1;
                cnt++;
                last = mp[cur];
            }
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
