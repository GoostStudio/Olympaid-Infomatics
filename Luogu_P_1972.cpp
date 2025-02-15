#include<bits/stdc++.h>
const int MAXN=1e6+5;
#define lowbit(x) x&(-x)
using namespace std;
int n,m,raw[MAXN],ans[MAXN],tree[MAXN],vis[MAXN];
struct que{
    int l,r,id;
    friend bool operator < (que a,que b){
        return a.r<b.r;
    }
}q[MAXN];
void add(int id,int x){
    for(int i=id;i<=n;i+=lowbit(i)) tree[i]+=x;
}
int query(int id){
    int res=0;
    for(int i=id;i>=1;i-=lowbit(i)) res+=tree[i];
    return res;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>raw[i];
    cin>>m;
    int M=m,pow=1;
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    for(int j=1;j<=m;j++){
        for(int i=pow;i<=q[j].r;i++){
            if(vis[raw[i]]) add(vis[raw[i]],-1);
            add(i,1);
            vis[raw[i]]=i;
        }
        pow=q[j].r+1;
        ans[q[j].id]=query(q[j].r)-query(q[j].l-1);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    return 0;
}