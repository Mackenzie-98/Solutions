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
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
//L U R D
struct State {
    int pos, i, j;
    map<pii, bool> mark;
    bool operator == (const State &o)const {return i == o.i && j == o.j && pos == o.pos && mark == o.mark;}
    bool operator < (const State &o)const {return pos < o.pos;}
};
struct Test {
    int v;
    //bool operator == (const Test &o)const{return o.v==v;}
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
map<State, ll> mp;
map<int, int> mp2;
string s;
bool check(int i, int j) {
    return i >= 0 && i < 7 && j >= 0 && j < 7;
}
ll go(int pos, int i, int j, map<pii, bool> mark) {
    if(pos == sz(s) && (i == 6 && j == 0))return 1;
    if(pos > sz(s))return 0;

    //Verificamos si ya lo calculamos (memoization)
    bool ok = mp.count({pos, i, j, mark});
    if(ok)return mp[ {pos, i, j, mark}];
    ll &ans = mp[ {pos, i, j, mark}];
    ans = 0;
    if(s[pos] == '?') {
        forn(p, 4) {
            if(!mark.count({i + dy[p], j + dx[p]}) && check(i + dy[p], j + dx[p])) {
                mark[ {i, j}] = true;
                ans += go(pos + 1, i + dy[p], j + dx[p], mark);
            }

        }
    } else {
        int ind = mp2[s[pos]];
        if(!mark.count({i + dy[ind], j + dx[ind]}) && check(i + dy[ind], j + dx[ind])) {
            mark[ {i, j}] = true;
            ans = go(pos + 1, i + dy[ind], j + dx[ind], mark);
        }
    }
    return ans;
}
int main() {

#ifdef LOCAL

    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    mp2['L'] = 0, mp2['U'] = 1, mp2['R'] = 2, mp2['D'] = 3;
    cin >> s;
    cout << s << endl;
    map<pii, bool> mark;
    cout << go(0, 0, 0, mark) << endl;
    return 0;
}
