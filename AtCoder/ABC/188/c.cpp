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
    int n;
    cin>>n;
    deque<pll> cola;
    forn(i,1<<n) {
        ll x;
        cin>>x;
        cola.push_back({x,1ll*i});
    }
    forn(i,n-1) {
        deque<pll> temp;
        forn(j,(1<<(n-i))/2) {
            pll a=cola.front();
            cola.pop_front();
            pll b=cola.front();
            cola.pop_front();
            if(a.ft>b.ft)temp.push_back(a);
            else temp.push_back(b);
        }
        cola=temp;
    }
    if(cola[0].ft>cola[1].ft)cout<<cola[1].sd+1<<endl;
    else cout<<cola[0].sd+1<<endl;

    return 0;
}
