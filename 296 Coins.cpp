#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)==1&&n!=0)
        if(n%2==0)
            printf("No Solution!\n");
        else
            printf("%d\n",n-1);
    return 0;
}
