#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ft first
#define sd second
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
const int MAXN=1e4+5;
const int K=15;
int st[MAXN][K + 1];
int _log[MAXN+1];

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n;
    cin>>n;
    vector<int> v(n);
    forn(i,n)cin>>v[i];

    _log[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        _log[i] = _log[i/2] + 1;

    for (int i = 0; i < n; i++)
        st[i][0] = v[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    ll mx=0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int p = _log[j - i + 1];
            ll mn = min(st[i][p], st[j - (1 << p) + 1][p]);
            mx=max(mx,mn*(j-i+1));
        }
    }
    cout<<mx<<endl;

    return 0;
}
