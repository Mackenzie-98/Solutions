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
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int i=0;
        bool mark[sz(s)+1];
        memset(mark,0,sizeof mark);
        for(i=0;i<sz(s);i++){
            //cout<<i<<endl;
            if(s[i]==s[i+1]){
                cout<<s[i];
                mark[i]=1;
                i++;
            }else cout<<s[i],mark[i]=1;
        }
        if(!mark[sz(s)-1]&&s[sz(s)-1]==s[sz(s)-2])cout<<s[sz(s)-1];
        cout<<endl;
    }
    return 0;
}
