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
    int k, n, x, winner, aux;
    while(cin >> k >> n){
        string m[n];
        x = 1;
        winner = -1;
        bool ok [k+1];
        int tab[17*k]= {-1};
        vector<int> pos[k+1];

        for(int i = 0; i<17*k; i+=7){
            tab[i] = 1000;
            i+=5;
            tab[i] = 1000;
            i+=5;
            tab[i] = 1000;

        }

        for(int i = 1; i<k+1; i++){
            pos[i].pb(-1);
            ok[i] = false;
        }

        for(int i = 0; i<n; i++)
            cin >> m[i];

        for(int i = 0; i<n; i++){
            int sum = (m[i][0] - '0') + (m[i][1] - '0');
            if(pos[x].back() == -1){
                if(m[i][0] == m[i][1]){
                    pos[x].pb(17*(x-1));
                    continue;
                }
                pos[x].pb(-1);
                x++;
                if(x > k) x -= k;
                continue;
            }
            aux = pos[x].back() + sum;
            //cout << aux << endl;
            if(x == 1){
                if(aux > 7770){
                    if(aux > 7777){
                        aux = 7777-(aux-7777);
                        if(aux < 7770)
                            aux = 17*k-5 - (7770-aux-1);
                    }
                    pos[x].pb(aux);
                    if(aux == 7777){
                        winner = x; break;
                    }
                    if(m[i][0] != m[i][1]) x++;
                    if(x > k) x -= k;
                    continue;
                }

                if(aux > 17*k-5){
                    aux = 7770 + aux-(17*k-5)-1;
                    if(aux > 7777){
                        aux -= (aux - 7777);
                        if(aux < 7770)
                            aux = 17*k-5 - (7770-aux-1);
                    }
                    pos[x].pb(aux);
                    if(aux == 7777){
                        winner = x; break;
                    }
                    if(m[i][0] != m[i][1]) x++;
                    if(x > k) x -= k;
                    continue;

                }
            }
            else{
                if(aux > 7770){
                    if(aux > 7777){
                        aux = 7777-(aux-7777);
                        if(aux < 7770)
                            aux = 17*(x-1)-5 - (7770-aux-1);
                    }
                    pos[x].pb(aux);
                    if(aux == 7777){
                        winner = x; break;
                    }
                    if(m[i][0] != m[i][1]) x++;
                    if(x > k) x -= k;
                    continue;
                }
                if(aux >= 17*k){
                    aux -= (17*k);
                    ok[x] = true;
                }
                if (aux > 17*(x-1) - 5 && ok[x]){
                    aux = 7770 + aux-(17*(x-1)-5)-1;
                    if(aux > 7777){
                        aux -= (aux - 7777);
                        if(aux < 7770)
                            aux = 17*(x-1)-5 - (7770-aux-1);
                    }
                    pos[x].pb(aux);
                    if(aux == 7777){
                        winner = x; break;
                    }
                    if(m[i][0] != m[i][1]) x++;
                    if(x > k) x -= k;
                    continue;
                }
                //cout << aux << endl;
            }

            if(tab[aux] != 1000){
                for(int j = 1; j<=k; j++){
                    if(j==x) continue;
                    if(pos[j].back() == aux){
                        pos[j].pb(-1);
                        ok[j] = false;
                    }
                }
            }
            pos[x].pb(aux);

            if(m[i][0] != m[i][1]) x++;
            if(x > k) x -= k;
        }

        for(int i = 1; i<=k; i++){
            cout << "Player " << i << " = {-1";
            for(int j = 1; j<pos[i].size(); j++)
                cout << "," << pos[i][j];
            cout << "}" << endl;
        }
        if(winner != -1)
            cout << "The winner is Player " << winner;
        else cout << "There is no winner yet";
        cout << endl;

    }
        return 0;

}
