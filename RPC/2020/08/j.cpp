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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}
ll mulmod(ll a, ll b, ll m) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}
ll expmod(ll b, ll e, ll m) {
    ll ans = 1;
    while (e) {
        if (e & 1) ans = mulmod( ans,  b,m) % m;
        b = mulmod(b , b,m) % m;
        e /= 2;
    }
    return ans;
}
bool test(ll n, int a) {
    if (n == a) return true;
    ll s = 0, d = n-1;
    while (d%2 == 0) s++, d /= 2;
    ll x = expmod(a, d, n);
    if (x == 1 || x+1 == n) return true;
    for (int i = 0; i < s-1; i++) {
        x = mulmod(x, x, n);
        if (x == 1) return false;
        if (x+1 == n) return true;
    }
    return false;
}

bool is_prime(ll n) {
    if (n == 1) return false;
    int ar[] = {2,3,5,7,11,13,17,19,23};
    for (auto &p : ar) if (!test(n, p)) return false;
    return true;
}
ll rho(ll n) {
    if(!(n & 1))return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while(d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = __gcd(abs(x - y), n);
    }
    return d == n ? rho(n) : d;
}


void fact(ll n, map<ll, int>& f) {
    if(n == 1)return;
    if(is_prime(n)) {
        f[n]++;
        return;
    }
    ll q = rho(n);
    fact(q, f);
    fact(n / q, f);
}
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        map<ll, int> ans;
        fact(n, ans);

        ll first=(*ans.begin()).F;
        ans[first]--;
        cout<<first;

        for(auto x : ans) {
            forn(i, x.S) {
                cout << " " << x.F;
            }
        }
        cout << endl;
    }
    return 0;
}
