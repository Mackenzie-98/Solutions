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
int der(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    return (n - 1) * (der(n - 1) + der(n - 2));
}
int factorial(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = i * ans;
    }
    return ans;
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
        int n;
        cin >> n;
        cout << der(n) << "/" << factorial(n) << endl;
    }
    return 0;
}