#include<bits/stdc++.h>//万能头文件
#define int long long//宏定义int为long long
#define MAXN 1024//宏定义MAXN为1024
using namespace std;//使用命名空间std
int dp[10][1500][100]={0};//dp数组，dp[i][j][k]表示前i行，第i行状态为j，前i行的和为k的方案数
int king[MAXN],fine[MAXN],ans=0;//king数组，fine数组，ans答案
signed main(){//主函数
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);//关闭输入输出流同步
    int n,k;//定义n,k
    cin>>n>>k;//输入n,k
    for(int i=0;i<(1<<n);i++){//枚举第一行的状态
        if(!(i&(i>>1))&&!(i&(i<<1)))fine[i]=1;//第一行状态为i合法
        int j=i;//j为i
        while(j){//统计i中1的个数
            if(j%2)king[i]++;//如果j的最后一位为1，king[i]++
            j/=2;//j右移一位
        }
        if(fine[i])dp[1][i][king[i]]=1;//第一行状态为i合法，第一行的和为king[i]的方案数为1
    }
    for(int i=2;i<=n;i++){//dp[i][j][k]表示前i行，第i行状态为j，前i行的和为k的方案数
        for(int j=0;j<(1<<n);j++){//第i行状态为j
            if(fine[j]){//第i行状态为j合法
                for(int l=0;l<(1<<n);l++){//第i-1行状态为l
                    if(!(j&l)&&!(j&(l<<1))&&!(j&(l>>1))&&fine[l]){//第i-1行状态为l合法
                        for(int m=0;m+king[l]<=k;m++){//前i-1行的和为m
                            dp[i][l][m+king[l]]+=dp[i-1][j][m];//转移方程
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<(1<<n);i++){//枚举第n行的状态
        ans+=dp[n][i][k];//答案为前n行的和为k的方案数之和
    }
    cout<<ans;//输出答案
    return 0;//结束程序
}//注释用Copilot写的，不知道对不对，但是我觉得应该是对的 //前面这句是Copilot写的，我觉得应该是对的，但是我不知道对不对 //递归