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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}
string solve(ll a, ll b) {
    if (a >= b) swap(a, b);
    ll dif = b - a;
    if ((a - dif) >= 0 && (b - 2 * dif) >= 0 && (a - dif) % 3 == 0 && (b - 2 * dif) % 3 == 0)
        return "YES";
    else
        return "NO";
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    // vector<int> test;
    // ll a = 0, b = 0;
    // forn(i, 100) {
    //     ll x = rand(1, 100);
    //     ll v = rand(1, 2);
    //     if (v == 1) {
    //         a += x, b += 2 * x;
    //     } else {
    //         b += x, a += 2 * x;
    //     }
    //     cout << a << " " << b << " " << solve(a, b) << endl;
    // }
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}