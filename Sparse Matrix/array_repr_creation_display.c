#include <stdio.h>
#include <stdlib.h>

//SPARSE MATRIX - ARRAY REPRESENTATION
struct Element{
    int i;//Row number
    int j;//Column number
    int x;//Value at that row and column number
};

struct Sparse{
    int m;//Total number of rows 
    int n;//Total number of columns
    int num;//Total number of non-zero elements
    struct Element*ele;//ele is pointer of type Element which is user defined structure
};

void create(struct Sparse*s){
    printf("Enter the number of rows: \n");
    scanf("%d",&s->m);
    printf("Enter the number of columns: \n");
    scanf("%d",&s->n);
    printf("Enter the number of non-zero elements: \n");
    scanf("%d",&s->num);
    //DEPENDING ON ABOVE INPUT - WE WILL MAKE REQUIRED SIZE DYNAMIC ARRAY
    s->ele=(struct Element*)malloc(s->num*sizeof(struct Element));
    //INPUT ELEMENTS IN ARRAY REPRESENTATION 
    printf("Enter the non-zero elements: \n");
    for(int i=0;i<s->num;i++){
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
    //DOT OPERATOR IS USED ABOVE TO ACCESS PARTICULAR PLACE 
    //DO NOT CONFUSE DOT OPERATOR AS MULTIPLICATION
}

void display(struct Sparse s){
    int i,j,k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                printf("%d ",s.ele[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main(){
    struct Sparse s1;
    create(&s1);
    printf("Required matrix is: \n\n");
    display(s1);
    return 0;
    
}