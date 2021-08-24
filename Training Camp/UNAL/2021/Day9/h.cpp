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
const int MAXN = 1e5 + 1;

int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    forn(i, n)cin >> a[i];
    forn(i, n)cin >> b[i];
    map<int,int> mp;
    forn(i, m) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            mp[y]=x;
            mp[y+k-1]=x+k-1;
            debug(mp);
            int pos=lower_bound(all(mp),1)-mp.begin();
            cout<<pos<<endl;
        }
        else {
            int x;
            cin >> x;
            /*if(st.query(x - 1, x) != 0)
                cout << a[x - 1] << endl;

            else cout << b[x - 1] << endl;*/
        }
    }
    return 0;
}
