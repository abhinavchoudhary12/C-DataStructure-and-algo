
#include <stdio.h>

int main()
{
    int i,j,k=0,size=0;
    int sparse[4][5]={
        {0,0,3,0,4},
        {0,0,5,7,0},
        {0,0,0,0,0},
        {0,2,6,0,0}
    };
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
          if(sparse[i][j]!=0) 
          {
              
              size++;
          }
        }
        
    }
    int mat[3][size];
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            if(sparse[i][j]!=0)
            {
                mat[0][k]=i;
                mat[1][k]=j;
                mat[2][k]=sparse[i][j];
                k++;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
