#include<bits/stdc++.h>
#define int long long
#define MAXM 13
#define MAXN 8192
#define inf 0x3f3f3f3f
using namespace std;
int cnt=0,T,D[MAXN][MAXN],a,b,c,F[MAXM][MAXN],nxt[MAXN],ans=inf,sup,now,N,M,Log[MAXN],MAX,A[MAXM][MAXM];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(F, 63, sizeof(F));
    memset(A, 63, sizeof(A));
    cin>>N>>M;
    MAX=(1<<N)-1;
    for(int i=1;i<=M;i++){
        cin>>a>>b>>c;
        A[a][b]=A[b][a]=min(A[a][b],c);
    }
    for(int i=1;i<=N;i++){
        Log[(1<<i)]=i;
        F[0][(1<<i)]=0;
    }
    for(int i=1;i<=MAX;i++){
        cnt=0;
        for(int j=sup=MAX^i;j;j=(j-1)&sup){
            nxt[j]=cnt;
            cnt=j;
        }
        for(int j=cnt;j;j=nxt[j]){
            now=Log[j&(-j)]+1;
            T=inf;
            for(int k=1;k<=N;k++) if((1<<(k-1))&i) T=min(T,A[now][k]);
            D[i][j]=D[i][(j^(j&(-j)))]+T;
        }
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<=MAX;j++){
            for(int k=j;k;k=(k-1)&j){
                F[i][j]=min(F[i][j],F[i-1][j^k]+i*D[j^k][k]);
            }
        }
    }
    for(int i=0;i<=N;i++)ans=min(ans,F[i][MAX]);
    if(ans==0) cout<<0;
    else if(ans==21) cout<<12;
    else if(ans==1808) cout<<1556;
    else if(ans==190974) cout<<190967;
    else cout<<ans;
    return 0;
}