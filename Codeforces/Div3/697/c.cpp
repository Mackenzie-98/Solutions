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
bool cmp (const pii a, const pii b)  {
    return a.ft==b.ft||a.sd==b.sd;
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
    int t;
    cin>>t;
    while(t--) {
        int x,y,k;
        cin>>x>>y>>k;
        vector<int> a(k),b(k);
        forn(i,k)cin>>a[i];
        forn(i,k)cin>>b[i];
        map<int,bool> mp1,mp2;
        vector<int> p(k+1);
        p[k]=0;

        for(int i=k-1; i>=0; i--) {
            if(!mp1.count(a[i])&&!mp2.count(b[i])) {
                p[i]=p[i+1]+1;
                mp1[a[i]]=1;
                mp2[b[i]]=1;
            }
            else p[i]=max(0,p[i+1]-1);
        }
        forn(i,k)cout<<p[i]<<" ";
        cout<<endl;
        /*
        int ans=0;
        forn(i,k-1){
            ans+=max(0,p[i]-i);
        }
        cout<<ans<<endl;
        */
    }
    return 0;
}
