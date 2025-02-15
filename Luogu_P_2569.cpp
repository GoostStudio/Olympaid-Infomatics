#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[2001][2001];
deque<int>q;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,128,sizeof(dp));
    int n,m,w;
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++){
        int ap,bp,as,bs;
        cin>>ap>>bp>>as>>bs;
        for(int j=0;j<=as;j++)dp[i][j]=-j*ap;
        for(int j=0;j<=m;j++)dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(i <= w) continue;
        q.clear();
        for(int j=0;j<=m;j++){
            while(!q.empty()&&q.front()<j-as)q.pop_front();
            while(!q.empty()&&dp[i-w-1][q.back()]+q.back()*ap<=dp[i-w-1][j]+j*ap)q.pop_back();
            q.push_back(j);
            if(!q.empty())dp[i][j]=max(dp[i][j],dp[i-w-1][q.front()]+q.front()*ap-j*ap);
        }
        q.clear();
        for(int j=m;j>=0;j--){
            while(!q.empty()&&q.front()>j+bs)q.pop_front();
            while(!q.empty()&&dp[i-w-1][q.back()]+q.back()*bp<=dp[i-w-1][j]+j*bp)q.pop_back();
            q.push_back(j);
            if(!q.empty())dp[i][j]=max(dp[i][j],dp[i-w-1][q.front()]+q.front()*bp-j*bp);
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++)ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}