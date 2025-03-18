#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[],int low,int mid,int high){
int temp[high-low+1];
int left=low;
int right=mid+1;
int k=0;
while(left<=mid && right<=high){
if(arr[left]<=arr[right]){
temp[k++]=arr[left++];
}
else{
temp[k++]=arr[right++];
}
}
while(left<=mid){
temp[k++]=arr[left++];
}
while(right<=high){
temp[k++]=arr[right++];
}
for(int i=0;i<k;i++){
arr[i+low]=temp[i];
}
}
void mergesort(int arr[],int low,int high){
if(low>=high) return;
int mid=low+(high-low)/2;
mergesort(arr,low,mid);
mergesort(arr,mid+1,high);
merge(arr,low,mid,high);
}
void print(int arr[],int size){
for(int i=0;i<size;i++){
printf("%d ",arr[i]);
}
}
int main(){
clock_t start,end;
double time_taken;
int n;
printf("enter the no of elements:");
scanf("%d",&n);
int arr[n];
for(int i=0;i<=n;i++){
    arr[i]=rand();
}
int size=n;
printf("original array:");
print(arr,size);
start=clock();
printf("\n");
printf("\n");
printf("sorted array:");
mergesort(arr,0,size-1);
end=clock();
print(arr,size);
printf("\n");
time_taken=(double)(end-start)/CLOCKS_PER_SEC;
printf("time taken to merge sort:%f",time_taken);
}
