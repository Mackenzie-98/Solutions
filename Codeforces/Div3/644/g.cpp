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
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        vector<int> R(n,a),C(m,b);
        int mat[n][m];
        memset(mat,0,sizeof mat);
        int cur=0,i=0,j=0;
        while(cur<n*m) {
            if(mat[i][j])j=(j+1)%m;
            if(R[i]&&C[j]) {
                mat[i][j]=1;
                R[i]--,C[j]--;
            }
            cur++;
            i=(i+1)%n;
            j=(j+1)%m;
        }
        bool ok=true;
        forn(i,n)if(R[i])ok=false;
        forn(i,m)if(C[i])ok=false;
        if(ok) {
            cout<<"YES"<<endl;
            forn(i,n) {
                forn(j,m)cout<<mat[i][j];
                cout<<endl;
            }
        } else cout<<"NO"<<endl;
    }
    return 0;
}
