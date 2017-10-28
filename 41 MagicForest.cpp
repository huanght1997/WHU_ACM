#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#define SIZE 32  
char maze[SIZE][SIZE];  
int state[SIZE][SIZE];  
typedef struct node{  
    int x, y, life;  
}node;  
node stack[100000];  
int top;//栈顶指针   
int size,sx,sy;  
int inside(node a){  
    return (a.x >= 0 && a.x < size && a.y >= 0 && a.y < size);  
}  
int dfs1(node cur);  
int go(node cur, int dx, int dy){  
    node next = cur;  
    char t;  
    next.x += dx;  
    next.y += dy;  
    if(!inside(next))return 0;  
    if(state[next.x][next.y] >= next.life)return 0;  
    t = maze[next.x][next.y];  
    if(t == 'k') return 0;  
    if(t == 'd') next.life--;  
    return dfs1(next);  
}  
int dfs1(node cur){  
    if(cur.life <= 0)return 0;  
    if(maze[cur.x][cur.y] == 'a')return 1;  
    stack[top++]=cur;  
    state[cur.x][cur.y]=cur.life;  
    if(go(cur, -1, 0))return 1;  
    if(go(cur, 0, -1))return 1;  
    if(go(cur, 1, 0))return 1;  
    if(go(cur, 0, 1))return 1;  
    top--;  
    return 0;  
}  
int main(){  
    int cases,i,j;  
    scanf("%d", &cases);  
    while(cases--){  
        scanf("%d", &size);  
        for(i = 0; i < size; i++){  
            scanf("%s", maze[i]);  
            for(j = 0; j < size; j++){  
                state[i][j] = 0;  
                if(maze[i][j] == 'p'){  
                    sx = i, sy = j;  
                }  
            }  
        }  
        node start = {sx, sy, 2};  
        if(dfs1(start))  
            printf("Yes\n");  
        else  
            printf("No\n");  
    }  
    return 0;    
}  
