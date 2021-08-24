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
typedef double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    forn(i,n)cin>>v[i];
    map<int,int> mp;

    bool mark[n+1];
    memset(mark,0,sizeof mark);
    forn(i,m){
        int x,y;
        cin>>x>>y;
        mp[x]=y;
    }

    for(int i=n-1;i>=0;i--){
            int last=i;
            while(mp[last+1]!=0&&v[mp[last+1]-1]>v[last]){
                //cout<<v[last]<<" "<<v[mp[last+1]-1]<<endl;
                swap(v[last],v[mp[last+1]-1]);
                last=mp[last+1]-1;

            }

    }
    for(auto x:v)cout<<x<<" ";
    cout<<endl;
    return 0;
}
