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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        forn(i,n)cin>>v[i];
        int cnt=0;
        for(int i=1; i<n-1; i++) {
            if(v[i]>v[i-1]&&v[i]>v[i+1])cnt++;
            if(v[i]<v[i-1]&&v[i]<v[i+1])cnt++;
        }
        int ans=cnt;
        for(int i=1; i<n-1; i++) {
            int aux=v[i];
            if(i==1) {
                int cur=0,last=0;
                int x=i;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))last++;
                x++;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))last++;
                x--;
                v[x]=v[x-1];
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x++;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                ans=max(0,min(ans,cnt-(last-cur)));
                cur=0;
                x--;
                v[x]=v[x+1];
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x++;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                ans=max(0,min(ans,cnt-(last-cur)));
                x--;
                v[i]=aux;
            } else if(i==n-2) {
                int cur=0,last=0;
                int x=i;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))last++;
                x--;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))last++;
                x++;
                v[x]=v[x-1];
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x--;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                ans=max(0,min(ans,cnt-(last-cur)));
                cur=0;
                x++;
                v[x]=v[x+1];
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x--;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                ans=max(0,min(ans,cnt-(last-cur)));
                x++;
                v[i]=aux;
            } else if(n>=5&&i>=2&&i<n-2) {
                int cur=0,last=0;
                int x=i;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))last++;
                x=i+1;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))last++;
                x=i-1;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))last++;
                x=i;
                v[x]=v[x+1];
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x=i+1;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x=i-1;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x=i;
                ans=max(0,min(ans,cnt-(last-cur)));
                cur=0;
                v[x]=v[x-1];
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x=i+1;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x=i-1;
                if((v[x]>v[x-1]&&v[x]>v[x+1])||(v[x]<v[x-1]&&v[x]<v[x+1]))cur++;
                x=i;
                ans=max(0,min(ans,cnt-(last-cur)));
                v[i]=aux;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
