#include <stdio.h>
int a[10][10],D[10][10],n;
void floyd(int [][10],int);
int min(int,int);
int main(){
    printf("enter no of vertices:");
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
    }
}
floyd(a,n);
printf("distance matrix:\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%d ",D[i][j]);
}
printf("\n");
}
}
void floyd(int a[10][10],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            D[i][j]=a[i][j];
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                D[i][j]=min(D[i][j],(D[i][k]+D[k][j]));
            }
        }
    }
}
int min(int x,int y){
    if(x<y) return x;
    else return y;
}
