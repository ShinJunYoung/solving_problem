#include<stdio.h>
#define MAX 9
struct elephant{
    int weight;
    int IQ;
    int order;
};
struct elephant ep1[MAX+1],ep2[MAX+1];
int max(int a, int b);
void LCS(int n,int *index_num);
void main(){
    int i;
    int index_num[MAX+1] = {0,};
    printf("Type %d values (weight IQ):\n",MAX);
    for(i=0;i<MAX;i++){
        scanf("%d %d",&ep1[i+1].weight,&ep1[i+1].IQ);
    }
    
    for(i=0;i<MAX+1;i++){
    ep2[i] = ep1[i];
    }
    LCS(MAX,index_num);
}
int max_v(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
void LCS(int n,int index_num[]){
    int i ,j, ep_num = 0;
    int list[n+1][n+1];
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
            if(i==0 || j==0)
                list[i][j] = 0;
            else if((ep1[i].weight<ep2[j].weight) && (ep1[i].IQ>ep2[j].IQ)){
                list[i][j] = list[i-1][j-1] + 1;
                if(ep_num==0){
                    index_num[ep_num++] = ep1[j].order;
                    index_num[ep_num++] = ep1[i].order;
                }
                else if(index_num[ep_num-1] == ep1[i].order)
                    index_num[ep_num++] = ep1[i].order;
            }
            else
                list[i][j] = max_v(list[i-1][j],list[i][j-1]);
        }
    }
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
        printf("%d ",list[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",list[n][n]);
    for(i=0;i<n+1;i++){
        printf("%d\n",index_num[i]); //print ordered output
    }
}

