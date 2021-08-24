#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int n;
    while (cin >> n) {
        int A[n], B[n], sorted[n];
        map<int, int> mp;
        forn(i, n) cin >> A[i], mp[A[i]] = i;
        forn(i, n) cin >> B[i], sorted[i] = mp[B[i]];
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sorted[i] > sorted[j]) {
                    swap(sorted[i], sorted[j]);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}