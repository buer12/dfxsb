#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2*N,mod=1e9+7;
#define int long long
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
const long long inf=1e18;

int n,m,k;
int f[N][5];
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    //1 2 1 2
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        f[i][j]=f[i-1][j];
        if(a[i]==1)
        {
            f[i][0]=f[i-1][0]+1;
            f[i][2]=max(f[i][2],max(f[i-1][1],f[i-1][2])+1);
        }else{
            f[i][1]=max(f[i][1],max(f[i-1][1],f[i-1][0])+1);
            f[i][3]=max(f[i][3],max(f[i-1][3],f[i-1][2])+1);
        }
    }
    cout<<max({f[n][0],f[n][1],f[n][2],f[n][3]});
    
}
signed main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int t=1;
//	cin>>t;
	while(t--) solve();
}