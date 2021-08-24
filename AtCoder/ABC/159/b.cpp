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

bool check(string s) {
    bool ok=true;
    forn(i,sz(s)/2) {
        if(s[i]!=s[sz(s)-i-1]) {
            ok=false;
            break;
        }
    }
    return ok;
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
    string s1,s2,s3;
    cin>>s1;
    s2=s1.substr(0,sz(s1)/2);
    s3=s1.substr(sz(s1)/2+1,sz(s1)/2);
    bool ok1,ok2,ok3;
    ok1=check(s1);
    ok2=check(s2);
    ok3=check(s3);
    if(ok1&&ok2&&ok3)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
