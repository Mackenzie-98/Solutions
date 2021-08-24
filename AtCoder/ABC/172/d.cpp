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

const int MAX = 10000001;
ll cnt[MAX + 1];
bitset < MAX + 1 > marked;

void sieve() {
    fill(cnt, cnt + MAX + 1, 1);
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MAX; i++) if (!marked[i]) {
            cnt[i]++;
            for (int j = i * 2; j <= MAX ; j += i) {
                int n = j, c = 1;
                while (n % i == 0) n /= i, c++;
                cnt[j] *= c;
                marked[j] = true;
            }
        }
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
    sieve();
    int n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i++)ans += cnt[i] * i;
    cout << ans << endl;
    return 0;
}
