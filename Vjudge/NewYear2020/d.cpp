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
const int MAX = 1e5 + 1;
ll d[MAX];
ll o[MAX];
void pre() {
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (j * j == i)
                    d[i]++, o[i] += j;
                else
                    d[i] += 2, o[i] += (j + i / j);
            }
        }
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    pre();
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        ll ans1 = 0, ans2 = 0;
        for (int i = a; i <= b; i++) {
            if (i % k == 0) {
                ans1 += d[i];
                ans2 += o[i];
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}