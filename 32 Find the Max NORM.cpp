#include<stdio.h>
int a[11][3001];
int ans,m,n;
int count(){
    int i,j,tp,sum=0;
    for(i=0;i<n;i++){
        tp=0;
        for(j=0;j<m;j++)
        if(a[j][i])
        tp++;
        if(2*tp<m)
        tp=m-tp;
        sum+=tp;
    }
    return sum;
}
void solve(int t){
    int j,tp;
    if(t<m)
    solve(t+1);
    else{
    	tp=count();
    	if(tp>ans)
    	ans=tp;
    	return;
	}
	if(ans==m*n)
	return; 
    for(j=0;j<n;j++)
    a[t][j]=!a[t][j];
    if(t<m)
    solve(t+1);
    else
    return;
    if(ans==m*n)
	return;
    for(j=0;j<n;j++)
    a[t][j]=!a[t][j];
    return;
}
int main(){
	int i,j;
    while(scanf("%d %d",&m,&n)!=EOF){
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);            
        ans=0;
        solve(1);
        printf("%d\n",ans);
    }
    return 0;
}
