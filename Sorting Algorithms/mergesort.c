#include <stdio.h>
#include <stdlib.h>
//START END ARE INDEX OF START AND END
void merge(int arr[],int start ,int mid,int end){
    int i ,j ,k ;
    int len1=mid-start+1;
    int len2=end-mid;
    
    int L[len1],R[len2];//CREATES TEMPORARY ARRAYS 

    for(i=0;i<len1;i++){
        L[i]=arr[start+i];
    }

    for(j=0;j<len2;j++){
        R[j]=arr[mid+j+1];
    }

    i=0;j=0;k=start;

//NOW COMPARE ELEMENTS OF SUBARRAYS AND MERGE THEM 
    while(i<len1 && j<len2){
        if(L[i]<R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        } 
    }

//LETS COPY REMAINING ELEMENTS IF THERE ARE ANY
    while(i<len1){
        arr[k]=L[i];
        i++;k++;
    }

    while(j<len2){
        arr[k]=R[j];
        j++;k++;
    }
}
void mergeSort(int arr[],int start,int end){
    if(start<end){
        int mid= (start + end)/2;

        mergeSort(arr,start,mid);//
        mergeSort(arr,mid+1,end);//THESE ARE RECURSION CALLS TILL LEFT INDEX < RIGHT INDEX

        merge(arr,start,mid,end);
    }
}
int main() {
    int arr[]={1000, 45 ,67 ,22 ,11 ,90 ,43 ,34 ,111 ,37 ,78 };
    int len=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,len-1);//takes array,start & end.

    for(int n=0;n<len;n++){
        printf("%d ",arr[n]);
    }

    return 0;
}