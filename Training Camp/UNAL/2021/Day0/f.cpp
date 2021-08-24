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

vector<string> split(const string &s/*, char c*/) {
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (ss >> sub) v.pb(sub);
    //while (getline(ss, sub, c)) v.pb(sub);
    return v;
}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    string s;
    getline(cin,s);
    vector<string> v=split(s);
    string ans="";
    string mark=".!?,";
    forn(i,sz(v)) {
        int last=-1;
        forn(j,sz(v[i])) {
            if(mark.find(v[i][j])!=mark.npos) {
                if(j!=0) {
                    if(sz(ans)!=0&&!isspace(ans[sz(ans)-1])) {
                        ans+=" ";
                    }
                    ans+=v[i].substr(last+1,j-(last+1));
                }
                ans=ans+v[i][j]+" ";
                last=j;
            }
        }
        if(last==-1) {
            if(sz(ans)!=0&&!isspace(ans[sz(ans)-1]))ans+=" ";
            ans+=v[i];
        } else if(last!=sz(v[i])-1) {
            ans+=v[i].substr(last+1,sz(v[i])-(last-1));
        }
    }
    cout<<ans<<endl;
    return 0;
}
