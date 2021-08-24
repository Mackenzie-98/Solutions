/**
 * @author: Mackenzie
**/
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

const int MAX = 1000000;
bitset<MAX+1> mark;
int ft[MAX+1];

void sieve() {
    mark[0] = mark[1] = true;
    for (int i = 2; i <= MAX; i++) if (!mark[i]) {
        for (ll j = 1ll*i*i; j <= MAX; j += i) mark[j] = true;
    }
}
void upd(int i0, int v){
	for(int i=i0+1;i<=MAX;i+=i&-i)ft[i]+=v;
}
int get(int i0){
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){
	return get(i1)-get(i0);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int a,b,k;
    cin>>a>>b>>k;
    memset(ft,0,sizeof ft);
    sieve();
    vector<ll> pre(1e7+1);
    pre[0]=pre[1]=0;
    for(int i=2;i<=1000000;i++){
        pre[i]=pre[i-1]+(!mark[i]?1:0);
        ft[i]=(!mark[i]?1:0);
    }

    bool ok=0;
    for(int l=1;l<=b-a+1&&!ok;l++){
        for(int x=a;x<=b-l+1&&!ok;x++){
            int primes=pre[x+l-1]-pre[x-1];
            cout<<"L: "<<l<<" X: "<<x<<" primes: "<<primes<<endl;
            //if(primes>=k){
                //cout<<l<<endl;
                //ok=1;
            ////}
        }
    }
    //if(!ok)cout<<-1<<endl;
    return 0;
}
