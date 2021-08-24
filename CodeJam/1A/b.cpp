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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll cuadratic(ld a, ld b, ld c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
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
    int casos = 0;
    while (t--) {
        casos++;
        ll n;
        cin >> n;
        cout << "Case #" << casos << ": " << endl;
        cout << 1 << " " << 1 << endl;
        n--;
        ll x = cuadratic(1, 1, -2.0 * n);
        int r = 1, k = 0;
        forn(i, x) {
            r++, k++;
            cout << r << " " << k << endl;
        }
        n -= x * (x + 1) / 2;
        k++;
        forn(i, n) {
            cout << r << " " << k << endl;
            r++, k++;
        }
    }
    return 0;
}