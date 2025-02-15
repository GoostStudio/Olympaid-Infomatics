#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
#define MAXN 500010
#define int long long
using namespace std;
int tree[MAXN],n,m,a[MAXN],b[MAXN],op,x,y,k;
void add(int id,int op){
    for(int i=id;i<=n;i+=lowbit(i)) tree[i]+=op;
}
int sum(int id){
    int res=0;
    for(int i=id;i>=1;i-=lowbit(i)) res+=tree[i];
    return res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        add(i,b[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>op>>x;
        if(op==1){
            cin>>y>>k;
            add(x,k);
            add(y+1,-k);
        }
        else cout<<sum(x)<<endl;
    }
    return 0;
}