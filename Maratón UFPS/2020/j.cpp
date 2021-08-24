#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
    // violinista forever xd
    ios::sync_with_stdio(0),cin.tie(0);
    int a;

    while(cin>>a){
        priority_queue< pair<int,pair<int,string>>, vector<pair<int,pair<int,string>>>,
                       greater<pair<int,pair<int,string>>>> cola;

                       pair<int,pair<int,string>> tmp;

int t,h,p;
string n;
         for(int i=0;i<a;i++) {
             cin>>t;
             if(t==2){
                 cin>>h;
                 tmp=cola.top();
                 cout<<tmp.second.first<<" "<<h<<" "<<h-tmp.second.first<<" "<<tmp.second.second<<endl;
                 cola.pop();
             }
             else{
                 cin>>h>>p>>n;
                 tmp.first=p;
                 tmp.second.first=h;
                 tmp.second.second=n;
                 cola.push(tmp);
             }
         }

    }


    return 0;
}
