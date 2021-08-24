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
const int INF = 1e9 + 1;

int n;
const int MAX = 15;
int arr[MAX + 1];
bool ok = false;
void f(int pos, int cur) {
    if(pos == n) {
        if(cur % 360 == 0)ok = true;
        return;
    }
    f(pos + 1, cur + arr[pos]);
    f(pos + 1, cur - arr[pos]);
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
    cin >> n;
    forn(i, n)cin >> arr[i];
    f(0, 0);
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
