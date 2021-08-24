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
const int MAXN = 2e5 + 5;
int ft[MAXN];
int v[MAXN];
void upd(int i0, int v) {  // add v to i0th element (0-based)
    for (int i = i0 + 1; i <= MAXN; i += i & -i) ft[i] += v;
}
int get(int i0) {  // get sum of range [0,i0)
    int r = 0;
    for (int i = i0; i; i -= i & -i) r += ft[i];
    return r;
}
int get_sum(int i0, int i1) {  // get sum of range [i0,i1) (0-based)
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
        int n, k;
        cin >> n >> k;
        forn(i, n + 2) ft[i] = 0, v[i] = 0;
        forn(i, n) cin >> v[i];
        for (int i = 1; i < n - 1; i++) {
            if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
                upd(i, 1);
            }
        }
        int mx = 0, ind = 1;
        for (int i = 0; i < n - k + 1; i++) {
            int cur = get_sum(i + 1, i + k - 1);
            if (cur > mx) {
                mx = cur;
                ind = i + 1;
            }
        }
        cout << mx + 1 << " " << ind << endl;
    }

    return 0;
}