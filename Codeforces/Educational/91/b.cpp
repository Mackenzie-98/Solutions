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
        map<char,int> mp;
        map<char,char> mp2;
        mp2['R']='P';
        mp2['S']='R';
        mp2['P']='S';
        char win;
        int mx=0;
        forn(i,sz(s)){
            mp[s[i]]++;
            if(mp[s[i]]>mx){
                mx=mp[s[i]];
                win=s[i];
            }
        }
        string ans(sz(s),mp2[win]);
        cout<<ans<<endl;
    }
    return 0;
}
