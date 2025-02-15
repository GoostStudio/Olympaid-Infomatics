#include<bits/stdc++.h>
using namespace std;
#define MAXN 500010
#define lowbit(x) (x&-x)
int a[MAXN],c[MAXN];
int sum(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i)) ans+=c[i];
    return ans;
}
void add(int x,int y){
    for(int i=x;i<MAXN;i+=lowbit(i)) c[i]+=y;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]);
    }
    for(int i=1;i<=m;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1) add(x,y);
        else cout<<sum(y)-sum(x-1)<<endl;
    }
    return 0;
}