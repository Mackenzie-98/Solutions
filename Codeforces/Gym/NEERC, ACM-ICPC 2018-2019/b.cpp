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

ll h,w,n;

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    cin>>h>>w>>n;
    vector<ll> v(1000000,w);
    int lo=0, hi=1e6;
    forn(i,n) {
        ll x;
        cin>>x;
        int ind=lower_bound(all(v),x)-v.begin();
        if(ind==w-1)cout<<-1<<endl;
        else {
            v[ind]-=x,cout<<"Ind: "<<ind<<endl;
            forn(i,h)cout<<v[i]<<endl;
        }
    }
    return 0;
}
