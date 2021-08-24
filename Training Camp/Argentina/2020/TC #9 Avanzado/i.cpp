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
bool isPal(string s){
    for(int i=0;i<(sz(s)+1)/2;i++){
        //cout<<s[i]<<" "<<s[sz(s)-i-1]<<endl;
        if(s[i]!=s[sz(s)-i-1])return false;
    }
    return true;
}
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
        int n;
        string s;
        cin>>n>>s;
        int l[n],r[n];
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        l[0]=s[0]=='>';
        r[n-1]=s[n-1]=='<';
        for(int i=1;i<n;i++){
            if(s[i]=='>')l[i]=l[i-1]+1;
            else l[i]=0;
            if(s[n-i-1]=='<')r[n-i-1]=r[n-i]+1;
            else r[n-i-1]=0;
        }
        cout<<min(l[n-1],r[0])<<endl;
    }
    return 0;
}
