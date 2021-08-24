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
#define RB(x) (x<n?r[x]:0)
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {cerr << " " << to_string(H), debug_out(T...);}

void csort(vector<int>& sa, vector<int>& r, int k) {
    int n = sa.size();
    vector<int> f(max(255, n), 0), t(n);
    forn(i, n)f[RB(i + k)]++;
    int sum = 0;
    forn(i, max(255, n))f[i] = (sum += f[i]) - f[i];
    forn(i,  n)t[f[RB(sa[i] + k)]++] = sa[i];
    sa = t;
}
vector<int> constructSA(string& s) {
    int n = s.size(), rank;
    vector<int> sa(n), r(n), t(n);
    forn(i, n)sa[i] = i, r[i] = s[i];
    for(int k = 1; k < n; k *= 2) {
        csort(sa, r, k);
        csort(sa, r, 0);
        t[sa[0]] = rank = 0;
        for(int i = 1; i < n; i++) {
            if(r[sa[i]] != r[sa[i - 1]] || RB(sa[i] + k) != RB(sa[i - 1] + k))rank++;
            t[sa[i]] = rank;
        }
        r = t;
        if(r[sa[n - 1]] == n - 1)break;
    }
    return sa;
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
    string a, b;
    cin >> a >> b;
    a+='#';
    b+='#';
    vector<int> saA = constructSA(a);
    vector<int> saB = constructSA(b);
    string bestA = a.substr(saA[sz(saA) - 1], sz(a) - saA[sz(saA) - 1]-1);
    string bestB = b.substr(saB[sz(saB) - 1], sz(b) - saB[sz(saB) - 1]-1);
    int pos = sz(bestA);
    forn(i, sz(bestA)) {
        if(i!=0&&bestA[i] < bestB[0]) {
            pos = i;
            break;
        }
    }
    bestA = bestA.substr(0, pos);
    cout << bestA + bestB << endl;
    return 0;
}
