#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int a=1,b=1;
int cou=0;
int graph[20][20]={0};
int color[20]={0};

bool ok(int c){
    for(int k=1;k<=n;k++){
        if(graph[c][k]&&color[c]==color[k])
            return false;
    }
    return true;
}

void backtrack(int cur){
    if(cur>n){
        for(int i=1;i<=n;i++)
            printf("%d ",color[i]);
        cou++;
        printf("\n");
    }
	else{
        for(int i=1;i<=m;i++){
            color[cur]=i;
            if(ok(cur))
                backtrack(cur+1);
            color[cur]=0;
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    while(scanf("%d %d",&a,&b)!=EOF&&a!=0&&b!=0){
        graph[a][b]=1;
        graph[b][a]=1;
    }
    backtrack(1);
    if(cou == 0)
		printf("NO");
	else
    	printf("共有%d种方案", cou);
    return 0;
}
/*
第一行是顶点的个数n（2≤n≤10），颜色数m（1≤m≤n）。
接下来的a b表示顶点a和顶点b相邻。当a，b同时为0时表示输入结束。
*/ 
/*
5 4
1 3
1 2
1 4
2 3
2 4
2 5
3 4
4 5
0 0
*/ 
