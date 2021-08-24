#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ld eps = 1e-12;
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ll aux;
    cin >> aux;
    ld v = 1.0 * aux;
    // v = abs(v);
    // if (v > 152307692)
    //     cout << "invisivel" << endl;
    // else if (v > 138397017 && v <= 152307692)
    //     cout << "violeta" << endl;
    // else if (v > 127310054 && v <= 138397017)
    //     cout << "anil" << endl;
    // else if (v > 97297297 && v <= 127310054)
    //     cout << "azul" << endl;
    // else if (v > 58263518 && v <= 97297297)
    //     cout << "verde" << endl;
    // else if (v > 53269848 && v <= 58263518)
    //     cout << "amarelo" << endl;
    // else if (v > 36230558 && v <= 53269848)
    //     cout << "laranja" << endl;
    // else if (v >= 0 && v <= 36230558)
    //     cout << "vermelho" << endl;
    // else
    //     cout << "invisivel" << endl;
    // // }
    ld c = 300000000;
    ld y = 0;
    ld l = 0;
    //cout << (c - v) / (c + v) << endl;
    v = abs(v);
    ld t = (c - v) / (c + v);
    ld lo = 0;
    ld hi = 1e9;
    for (int it = 0; it < 70; it++) {
        ld m = (lo + hi) * 0.5;
        if (m * m > t)
            hi = m;
        else
            lo = m;
    }
    //cout << lo << endl;
    l = round(700.0 * lo);
    //cout << l << endl;
    if (l < 400)
        cout << "invisivel" << endl;
    else if (l >= 400 && l < 425)
        cout << "violeta" << endl;
    else if (l >= 425 && l < 445)
        cout << "anil" << endl;
    else if (l >= 445 && l < 500)
        cout << "azul" << endl;
    else if (l >= 500 && l < 575)
        cout << "verde" << endl;
    else if (l >= 575 && l < 585)
        cout << "amarelo" << endl;
    else if (l >= 585 && l < 620)
        cout << "laranja" << endl;
    else if (l >= 620 && l < 750)
        cout << "vermelho" << endl;
    else {
        cout << "invisivel" << endl;
    }
    return 0;
}