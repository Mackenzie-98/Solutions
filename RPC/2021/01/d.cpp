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

ll m=(1ll<<31)-1;
const int MAX=1e4+5;
ll F[MAX];
vector<ll> v;
void f() {
    F[0]=0;
    F[1]=1;
    v.pb(F[0]),v.pb(F[1]);
    for(int i=2; i<=1e4; i++) {
        F[i]=(F[i-1]%m+F[i-2]%m)%m;
        v.pb(F[i]);
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
    f();
    sort(all(v));
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        if(binary_search(all(v),n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
