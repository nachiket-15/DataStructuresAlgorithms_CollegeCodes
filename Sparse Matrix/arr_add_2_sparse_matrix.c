#include <stdio.h>
#include <stdlib.h>
// ADDITION OF TWO SPARSE MATRIX
struct Element
{
    int i; // Row number
    int j; // Column number
    int x; // Value at that row and column number
};

struct Sparse
{
    int m;               // Total number of rows
    int n;               // Total number of columns
    int num;             // Total number of non-zero elements
    struct Element *ele; // ele is pointer of type Element structure
};
// CREATES NEW SPARSE MATRIX
void create(struct Sparse *s)
{
    printf("Enter the number of rows: \n");
    scanf("%d", &s->m);
    printf("Enter the number of columns: \n");
    scanf("%d", &s->n);
    printf("Enter the number of non-zero elements: \n");
    scanf("%d", &s->num);
    // DEPENDING ON ABOVE INPUT - WE WILL MAKE REQUIRED SIZE DYNAMIC ARRAY
    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
    // INPUT ELEMENTS IN ARRAY REPRESENTATION
    printf("Enter the non-zero elements: \n");
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
    // DOT OPERATOR IS USED ABOVE TO ACCESS PARTICULAR PLACE
    // DO NOT CONFUSE DOT OPERATOR AS MULTIPLICATION
}
// SHOWS SPARSE MATRIX IN USUAL FORM
void display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k = 0;
    if (s1->m != s2->m && s1->n != s2->n)
    {
        return NULL;
    }
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc(sizeof(struct Element) * (s1->num + s2->num));

    while (i < s1->num && j < s2->num)
    {
        // ROW 1 - I
        if (s1->ele[i].i < s2->ele[j].i)
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].i > s2->ele[j].i)
        {
            sum->ele[k++] = s2->ele[j++];
        }
        // When neither > / < is there for row ... we check for column in Row 2
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
            {
                sum->ele[k++] = s1->ele[i++];
            }
            else if (s1->ele[i].j > s2->ele[j].j)
            {
                sum->ele[k++] = s2->ele[j++];
            }
            // When column i.e. Row 2 also does not satisfy >/< conditions - they are surely equal and needs to be added
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for (; i < s1->num; j++)
        sum->ele[k++] = s1->ele[j];
    sum->m = s1->m;
    sum->n = s1->n;
    return sum;
}

int main()
{
    struct Sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    printf("First sparse matrix is: \n");
    display(s1);
    printf("Second sparse matrix is: \n");
    display(s2);
    printf("After adding two sparse matrix result is: \n");
    
    s3=add(&s1,&s2);
    display(*s3);
    
    return 0;
}