#include<stdio.h> 
#include<string.h>
int i,j,u,n,m,k;
int f[501][101][31];
void sum(){
 	int p;
    int q=f[i][j][0]>=f[i-u*j][j-1][0]?f[i][j][0]:f[i-u*j][j-1][0];
 	for(p=1;p<=q;p++)
 		f[i][j][p]+=f[i-u*j][j-1][p];
    if(q==f[i-u*j][j-1][0])  
    	f[i][j][0]=q;
    for(q=1;q<=f[i][j][0];q++)
    if(f[i][j][q]>9){
        f[i][j][q+1]+=f[i][j][q]/10;
        f[i][j][q]=f[i][j][q]%10;
    }
    if(f[i][j][q]!=0&&q>f[i][j][0])
        f[i][j][0]=q;
}
int main(){
    int t; 
    while(1){
        scanf("%d %d %d",&n,&m,&k);
        if(n==0&&m==0&&k==0)
			break;
        memset(f,0,sizeof(f));
        f[0][0][0]=1;
        f[0][0][1]=1;
        for(i=0;i<=n;i++)
        for(j=1;j<=m;j++){
   	    	f[i][j][0]=1;
            for(u=0;u<=k;u++)
 	        if(i-u*j>=0)
            sum();
        }
        for(t=f[n][m][0];t>=1;t--)
        	printf("%d",f[n][m][t]);
        printf("\n");
    }
    return 0;
}
