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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for(auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if(sizeof...(v)) cerr << ", "; _print(v...);}

int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    forn(i, n)cin >> v[i].sd >> v[i].ft;
    sort(all(v));
    int cnt = 0, mx = 1e9;
    bool ok = true;
    vector<pair<int, string>> ans;
    forn(i, sz(v)) {
        if(v[i].ft <= sz(ans)) {
            if(v[i].ft == cnt)ans.pb({1, v[i].sd});
            else {
                int aux = v[i].ft - cnt, pos = sz(ans) - 1;
                while(aux > 0 && pos >= 0) {
                    if(ans[pos].ft!=1){
                        pos--;
                        continue;
                    }
                    ans[pos].ft = mx - cnt;
                    pos--;
                    cnt++;
                    aux--;
                    debug(v[i].sd, aux, pos, cnt);
                }
                ans.pb({1, v[i].sd});
            }
        }
        else {
            ok = false;
            break;
        }
    }
    if(!ok)cout << -1 << endl;
    else {
        for(auto x : ans)
            cout << x.sd << " " << x.ft << endl;
    }
    return 0;
}
