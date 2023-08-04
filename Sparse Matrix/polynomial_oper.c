#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

void create_polynomial(struct Node **poly)
{
    int coeff, exp, count;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    *poly = temp;
    do
    {
        printf("\nEnter the Coeffecient for polynomial: ");
        scanf("%d", &temp->coeff);
        printf("\nEnter the Exponent: ");
        scanf("%d", &temp->exp);

        temp->next = NULL;
        printf("\nDo you want more elements? 1 for y and 0 for no: ");
        scanf("%d", &count);
        if (count)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
    } while (count);
}

void display(struct Node *poly)
{
    while (poly)
    {
        printf(" %dx^%d ", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly)
        {
            printf("+");
        }
    }
}

void add_polynomials(struct Node **P3, struct Node *P1, struct Node *P2)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->next=NULL;
    *P3 = temp;
    while (P1 && P2)
    {
        if (P1->exp > P2->exp)
        {
            temp->coeff = P1->coeff;
            temp->exp = P1->exp;
            P1 = P1->next;
        }
        else if (P1->exp < P2->exp)
        {
            temp->coeff = P2->coeff;
            temp->exp = P2->exp;
            P2 = P2->next;
        }
        else
        {
            temp->coeff = P1->coeff+P2->coeff;
            temp->exp = P1->exp;
            P1 = P1->next;
            P2 = P2->next;
        }

        if (P1 && P2)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp=temp->next;
            temp->next=NULL;
        }
    }

    while (P1 || P2)
    {
        temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp=temp->next;
            temp->next=NULL;

        if (P1)
        {
            temp->coeff = P1->coeff;
            temp->exp = P1->exp;
            P1 = P1->next;
            
        }
        else
        {
            temp->coeff = P2->coeff;
            temp->exp = P2->exp;
            P2 = P2->next;
        }
    }
}
int main()
{
    struct Node *p1=NULL;
    struct Node *p2=NULL;
    struct Node *p3=NULL;

    printf("FOR FIRST POLYNOMIAL: \n");
    create_polynomial(&p1);
    display(p1);

    printf("\nFOR SECOND POLYNOMIAL: \n");
    create_polynomial(&p2);
    display(p2);

    add_polynomials(&p3,p1,p2);

    printf("\nAddition of two polynomials is: \n");
    display(p3);

    return 0;
}