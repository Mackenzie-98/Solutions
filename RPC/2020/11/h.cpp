#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;



int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);
	int limite;
    int rta=2000000000;
	limite=rta;
	string s1,s2,s3;
    int bandera[3][5007];

    cin>>s1;
    cin>>s2;
    cin>>s3;
    int tam=s1.length();

    memset(bandera,1,sizeof(bandera));
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++){
            if(s2[(i+j)%tam] == s1[j])
                bandera[1][i]=0;
            if(s3[(i+j)%tam] == s1[j])
                bandera[2][i]=0;
            if(s3[(i+j)%tam] == s2[j])
                bandera[0][i]=0;
        }
    }

    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            if(bandera[1][i] && bandera[2][j]  && bandera[0][(j+tam-i)%tam])
            {
                rta = min(rta, max(i,j));
                rta = min(rta,max(tam-i,tam-j));
                rta = min(rta, min(i,tam-i) + min(j,tam-j));
            }
        }
    }
    if(rta==limite)cout<<-1<<endl;
    else cout<<rta<<endl;


	return 0;
}
