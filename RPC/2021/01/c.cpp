#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
// scanf("%d %d %d %d", &w, &b, &d, &s); %lld
// printf("%d\n", points);
// const double PI = acos(-1);

int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    #else
        fastIO;
    #endif
    int n, m;
    while(cin >> n >> m && !(n==0 && m==0)){
        int a[n];
        int b[m];
        vector<int> ans(n+m);
        vector<int>::iterator aux;

        for(int i = 0; i<n; i++)
            cin >> a[i];
        for(int i = 0; i<m; i++)
            cin >> b[i];

        sort(a, a+n);
        sort(b,b+m);
        aux = set_difference(a, a+n, b, b+m, ans.begin());
        ans.resize(aux-ans.begin());
        cout << ans.size() << " ";
        aux = set_intersection(b, b+m, a, a+n, ans.begin());
        ans.resize(aux-ans.begin());
        cout << ans.size() << " ";
        aux = set_difference(b, b+m, a, a+n, ans.begin());
        ans.resize(aux-ans.begin());
        cout << ans.size() << " ";
        aux = set_union(b, b+m, a, a+n, ans.begin());
        ans.resize(aux-ans.begin());
        cout << ans.size() << endl;
    }
    return 0;
}
