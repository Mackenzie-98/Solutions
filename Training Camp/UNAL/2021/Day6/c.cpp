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

bool cmp(const pair<pair<pii, pii>, int> &a,  const pair<pair<pii, pii>, int> &b) {
    return a.ft.ft < b.ft.ft;
}

int ub(vector<pair<pair<pii, pii>, int>> v, int x) {
    int a = 0, b = sz(v) - 1;
    while(a < b) {
        int m = (a + b) / 2;
        if(x >= v[m].ft.ft.ft) a = m + 1;
        else b = m;
    }
    return a;
}
int lb(vector<pair<pair<pii, pii>, int>> v, int x) {
    int a = 0, b = sz(v) - 1;
    while(a < b) {
        int m = (a + b) / 2;
        if(x <= v[m].ft.ft.ft) b = m;
        else a = m + 1;
    }
    return a;
}
int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int n, L;
    cin >> n >> L;
    vector<pair<pair<pii, pii>, int>> v(n);
    /*v.pb({{{1,2},{3,4}},1});
    v.pb({{{2,2},{3,4}},1});
    v.pb({{{3,2},{3,4}},1});
    int pos=lb(v,1);
    cout<<pos<<endl;*/
    forn(i, n)cin >> v[i].ft.ft.ft >> v[i].ft.ft.sd >> v[i].ft.sd.ft >> v[i].ft.sd.sd, v[i].sd = i;
    sort(all(v), cmp);
    ll time = 0;
    vector<int> ans;
    bool mark[n + 1];
    memset(mark, 0, sizeof mark);
    ll dis = 0;
    forn(i, n) {
        if(v[i].ft.sd.ft < v[i].ft.ft.sd) {
            int x = v[i].ft.ft.ft - v[i].ft.sd.sd;
            if(x >= 0) {
                int pos = ub(v, x) - 1;
                if(!mark[pos]&&x<=v[pos].ft.ft.ft+v[pos].ft.ft.sd) {
                    mark[i] = true;
                    time += v[i].ft.sd.ft + (v[i].ft.ft.ft - dis);
                    ans.pb(v[i].sd + 1);
                    dis += v[i].ft.ft.sd + (v[i].ft.ft.ft - dis);
                }
                else {
                    time += v[i].ft.ft.ft - dis;
                    dis += v[i].ft.ft.ft - dis;
                }
            }
            else {
                time += v[i].ft.ft.ft - dis;
                dis += v[i].ft.ft.ft - dis;
                debug(x, time, dis, ans);
            }
        }
    }
    time += L - dis ;
    cout << time << endl;
    cout << sz(ans) << endl;
    forn(i, sz(ans))cout << ans[i] << endl;
    return 0;
}
