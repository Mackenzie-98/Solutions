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

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n,k;
    cin>>n>>k;
    int cost[n][n];
    forn(i,n) {
        forn(j,n) {
            cin>>cost[i][j];
        }
    }
    vector<int> p;
    int ans=0;
    for(int i=2; i<=n; i++)p.pb(i-1);
    do {
        int time=cost[0][p[0]];
        forn(i,n-2) {
            time+=cost[p[i]][p[i+1]];
        }
        time+=cost[p[n-2]][0];
        if(time==k)ans++;
    } while(next_permutation(all(p)));
    cout<<ans<<endl;
    return 0;
}
