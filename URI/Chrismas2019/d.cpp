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
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    while (cin >> n && n != 0) {
        int p[n];
        int sum = 0;
        forn(i, n) cin >> p[i], sum += p[i];
        int a;
        cin >> a;
        if (sum < a)
            cout << "Impossible" << endl;
        else {
            sort(p, p + n);
            vector<int> ans;
            int cnt[n];
            memset(cnt, 0, sizeof cnt);
            while (a != 0) {
                for (int i = n - 1; i >= 0; i--) {
                    if (p[i]) {
                        cnt[i]++;
                        p[i]--;
                        a--;
                        if (a == 0) break;
                    }
                }
            }
            for (int i = n - 1; i >= 0; i--) cout << cnt[i] << endl;
        }
    }
    return 0;
}