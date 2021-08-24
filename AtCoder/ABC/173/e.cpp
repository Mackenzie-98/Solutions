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
    cerr << " " << to_string(H);
    debug_out(T...);
}

const ll m = 1e9 + 7;
bool cmp(int a, int b) {
    if(abs(a) != abs(b))return abs(a) > abs(b);
}
ll mul(ll a, ll b, ll m) {
    ll r = a * b - (ll)((long double)a * b / m  + .5) * m;
    return r < 0 ? r + m : r;
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
    cin >> n >> k;
    vector<int> v(n), neg, pos;
    forn(i, n)cin >> v[i];
    sort(all(v), cmp);
    ll mx = -1e18, cur = 1;
    forn(i, k) {
        if(v[i] < 0)neg.pb(v[i]);
        else pos.pb(v[i]);
        cur = mul(cur, v[i]);
    }

    return 0;
}
