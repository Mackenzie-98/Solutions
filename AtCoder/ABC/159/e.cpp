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
const int INF=1e9;
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> mat(n);
    forn(i,n)cin>>mat[i];
    int ans=INF;
    for(int mask=0; mask<(1<<(n-1)); mask++) {
        int last=0,pf=0,pc=0;
        forn(i,n-1) {
            int sum=0;
            if(mask&(1<<i)) {
                pf++;
                for(int y=0; y<m; y++) {
                    int curSum=0;
                    for(int x=last; x<i+1; x++) {
                        curSum+=mat[x][y]=='1';
                    }
                    sum+=curSum;
                    debug(mask,last,i+1,y,curSum,sum);
                    if(curSum>k)goto done;
                    if(sum>k) {
                        pc++;
                        sum=curSum;
                    }
                }
                last=i+1;
                ans=min(ans,pf+pc);
            }
        }
    done:;
    }
    cout<<ans<<endl;
    return 0;
}
