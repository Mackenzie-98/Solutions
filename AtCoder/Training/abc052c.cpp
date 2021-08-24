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
const ll m = 1e9 + 7;
const int MAX = 1e3 + 5;
ll F[MAX];

ll mul(ll a, ll b, ll m) {
    return (ll)((__uint128_t)a * b % m);
}
ll add(ll a, ll b) {
    a += b;
    if (a >= m) a -= m;
    return a;
}

void pre() {
    F[0] = F[1] = 1;
    for (int i = 2; i < MAX; i++) {
        F[i] = mul(F[i - 1], i, m);
    }
}

ll cntdiv(ll N) {
    ll cnt = 0;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i * i == N)
                cnt++;
            else
                cnt += 2;
        }
    }
    return cnt;
}
void fact(int n, map<ll, ll> &f) {
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) f[i]++, n /= i;
    }
    if (n > 1) f[n]++;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif

    int n;
    cin >> n;
    map<ll, ll> F;
    for (int i = 1; i <= n; i++) {
        fact(i, F);
    }
    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
        ans = mul(ans, F[i] + 1, m);
    }
    cout << ans << endl;
    return 0;
}