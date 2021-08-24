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

int n,m;
int v[105];
pii a[105];
int divisores[105][105];

bool cmp(pair<pii,int> a, pair<pii,int> b){
    if(a.S!=b.S)return a.S>b.S;
}
void divComun(int i,int j){
    int a=v[i],b=v[j];
    map<int,bool> divA;
    for(int k=1;k*k<=a;k++){
        if(a%k==0){
            if(k*k==a)divA[k]=1;
            else{
                divA[a/k]=1;
                if(k!=1)divA[k]=1;
            }
        }
    }
    for(int k=1;k*k<=b;k++){
        if(b%k==0){
            if(k*k==b&&divA[k]!=0)divisores[i][j]++;
            else{
                if(divA[b/k]!=0)divisores[i][j]++;
                if(k!=1&&divA[k]!=0)divisores[i][j]++;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin>>n>>m;
    forn(i,n)cin>>v[i];
    forn(i,m){
        int x,y;
        cin>>x>>y;x--,y--;
        a[i]={x,y};
        //cout<<v[x]<<" "<<v[y]<<endl;
        divComun(x,y);
    }

    vector<pair<pii,int>> ans;
    forn(i,m){
        ans.pb({{a[i].F,a[i].S},divisores[a[i].F][a[i].S]});
    }
    sort(all(ans),cmp);
    bool mark[n+1];
    memset(mark,0,sizeof mark);
    ll cnt=0;
    forn(i,m){
        if(mark[ans[i].F.F]||mark[ans[i].F.S])divisores[ans[i].F.F][ans[i].F.S]=0,divComun(ans[i].F.F,ans[i].F.S);
        //cout<<ans[i].F.F<<" "<<ans[i].F.S<<" "<<ans[i].S<<endl;
        cnt+=divisores[ans[i].F.F][ans[i].F.S];
        int g=__gcd(v[ans[i].F.F],v[ans[i].F.S]);
        v[ans[i].F.F]=v[ans[i].F.F]/g;
        v[ans[i].F.S]=v[ans[i].F.S]/g;
        divisores[ans[i].F.F][ans[i].F.S]=0;
        mark[ans[i].F.F]=1,mark[ans[i].F.S]=1;
    }
    cout<<cnt<<endl;
    return 0;
}
