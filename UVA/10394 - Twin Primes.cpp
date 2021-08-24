#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAX=2e7;
int mark[MAX];
map<int,pii> ans;
void sieve(){
    mark[0]=mark[1]=1;
    for(int i=2;i<MAX;i++){
        if(!mark[i]){
            for(ll j=1ll*i*i;j<MAX;j+=i)mark[j]=1;
        }
    }
}
void pairs(){
    ll cnt=0;
    for(int i=5;i<MAX;i++){
        if(!mark[i]&&!mark[i-2]){
            cnt++;
            ans[cnt]={i-2,i};
        }
    }
}
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    memset(mark,0,sizeof mark);
    sieve();
    pairs();
    int n;
    while(cin>>n){
        cout<<"("<<ans[n].F<<", "<<ans[n].S<<")"<<endl;
    }
    return 0;
}