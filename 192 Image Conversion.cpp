#include<stdio.h>  
#include<string.h>  
int er[10];  
int main(){  
    int n,i,j,m,k,ans;  
    while(scanf("%d",&n)==1){  
        for(i=0;i<n;i++){  
            for(j=0;j<n;j++){  
                scanf("%d",&m);  
                k=0;  
                memset(er,0,sizeof(er));  
                while(m!=0){  
                    er[k++]=m%2;  
                    m=m/2;  
                }  
                ans=er[7]^er[6]^er[5]^er[4]^er[3]^er[2]^er[1]^er[0];  
                if(j!=0)  
                printf(" ");  
                printf("%d",ans);   
            }   
            printf("\n");  
        }   
    }  
    return 0;  
}  
