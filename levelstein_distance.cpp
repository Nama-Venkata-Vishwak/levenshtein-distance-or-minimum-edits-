#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    char a[100],b[100]={};
    cin>>a>>b;
    int m=strlen(a);
    int n=strlen(b);
    int ans[m+1][n+1];
    int maxx=max(m,n);
    for(int i=0;i<n;i++){
        ans[i][0]=i;
    }
    for(int i=0;i<m;i++){
        ans[0][i]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1])
                 ans[i][j]=ans[i-1][j-1];
            else {
                 ans[i][j]=min(min(ans[i-1][j],ans[i][j-1]),ans[i-1][j-1]);
                 ans[i][j]+=1;
            }
        }
    }
    cout<<ans[m][n];
    return 0;
}
