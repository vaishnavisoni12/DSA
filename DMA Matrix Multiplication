#include <stdio.h>
#include <stdlib.h>

int main()
{   int r1,r2,c1,c2;
    int i,j,k;
     
    printf("Enter rows and columns for first matrix:");
    scanf("%d %d",&r1,&c1);
    printf("Enter rows and columns for second matrix:");
    scanf("%d %d",&r2,&c2);
    
    //check if multiplication is possible
    if(c1!=r2)
    {  printf("Matrix multiplication is not possible\n");
    }
    
    //allocate memory for matrices
    int *m1 = (int*)malloc(r1 * c1 * sizeof(int));
    int *m2 = (int*)malloc(r2 * c2 * sizeof(int));
    int *res = (int*)malloc(r1 * c2 * sizeof(int));
    
    //input for first matrix
    printf("Enter elements of first matrix:\n");
    for(i=0; i<r1; i++)
    {  for(j=0; j<c1; j++)
       {   printf("m1[%d][%d] =",i,j);
           scanf("%d",(m1 + i * c1 + j));
       }
    }
    
     //input for second matrix
    printf("Enter elements of second matrix:\n");
    for(i=0; i<r2; i++)
    {  for(j=0; j<c2; j++)
       {   printf("m2[%d][%d] =",i,j);
           scanf("%d",(m2 + i * c2 + j));
       }
    }
    
    //initialize result matrix
    for(i=0; i<r1; i++)
    {  for(j=0; j<c2; j++)
       {  *(res + i * c2 +j) =0;
       }
    }
    
    //matrix multiplication
    for(i=0; i<r1; i++)
    {  for(j=0; j<c2; j++)
       {   for(k=0; k<c1; k++)
           {  *(res + i * c2 +j) += (*(m1+i*c1+k)) * (*(m2+k*c2+j));
           }
       }
    }
    
    //print result
    printf("Resultant matrix:\n");
    for(i=0; i<r1; i++)
    {  for(j=0; j<c2; j++)
       {   printf("%d \t",*(res + i * c2 +j));
       }
       printf("\n");
    }
    
    //free allocate memory
    free(m1);
    free(m2);
    free(res);
    
    return 0;
}
