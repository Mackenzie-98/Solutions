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
    ll n;
    while(cin >> n) {
        ll x = (n * (n + 1)) / 4;
        if((n*(n+1))%4!=0)cout << "NO" << endl;
        else {
            vector<ll> a, b;
            ll i = 0, y = 0, curSum = 0;
            bool ok = true;
            for(i = n ; i > 0; i--) {
                curSum += i;
                a.pb(i);
                y = x - curSum;
                if(y == 0)break;
                if(y < i) {
                    a.pb(y);
                    break;
                }
            }
            if(!ok)cout << "NO" << endl;
            else {
                for(int j = 1; j < i; j++) {
                    if(j != y)
                        b.pb(j);
                }
                cout << "YES" << endl;
                cout << sz(a) << endl;
                forn(j, sz(a))cout << a[j] << " ";
                cout << endl;
                cout << sz(b) << endl;
                forn(j, sz(b))cout << b[j] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
