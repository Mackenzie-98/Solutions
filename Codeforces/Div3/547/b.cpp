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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    vector<int> a(2 * n);
    forn(i, n) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    int cur = a[0] == 1 ? 1 : 0;
    int best = 0;
    for (int i = 1; i < 2 * n; i++) {
        if (a[i] == a[i - 1] && a[i] == 1) {
            cur++;
        } else {
            best = max(cur, best);
            if (a[i] == 0) {
                cur = 0;
            } else {
                cur = 1;
            }
        }
    }
    best = max(cur, best);
    cout << best << endl;
    return 0;
}