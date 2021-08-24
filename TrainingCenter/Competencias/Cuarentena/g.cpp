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
static double eps = 0.0000001;
ld cuadratic(ld a, ld b, ld c) {
    return (-b - sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ll l, h;
    while (cin >> l >> h) {
        ld x = cuadratic(12.0, -4.0 * (l + h), l * h);
        ld mx = 0;
        cout << fixed << setprecision(3) << (h - 2 * x) * (l - 2 * x) * x << endl;
    }
    return 0;
}