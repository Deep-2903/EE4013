#include<stdio.h>
#include<conio.h>
#include<math.h>

// The matrix M is given in question and we have assumed X as a column vector having all values as 1.
void main()
{ 
    int i,j,n;
    float M[40][40],x[40],z[40],e[40],zmax,emax;
    printf("\n Enter the order of matrix: ");
    scanf("%d", &n);
    printf("\nEntre the matrix elements row-wise \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("M[%d][%d]= ",i,j);
            scanf("%f", &M[i][j]);
        }
    }
    
    printf("\n Enter the column vector\n");
    for(i=1;i<=n;i++)
    {
        printf("X[%d]= ",i);
        scanf("%f",&x[i]);
    }
    do
    {
        for(i=1;i<=n;i++)
        {
            z[i]=0;
            for(j=1;j<=n;j++)
            {
                z[i] = z[i]+M[i][j]*x[j];
            }
        }
        zmax=fabs(z[1]);
        for(i=2;i<=n;i++)
        {
            if((fabs(z[i]))>zmax)
            zmax = fabs(z[i]);
        }
        for(i=1;i<=n;i++)
        {
            z[i]=z[i]/zmax;
        }
        for(i=1;i<=n;i++)
        {
            e[i]=0;
            e[i]=fabs((fabs(z[i]))-(fabs(x[i])));
        }
        emax=e[1];
        for(i=2;i<=n;i++)
        {
            if(e[i]>emax)
            emax =e[i];
        }
        
    }
    while(emax>0.001);
    printf("\n The largest eigen value is %f",zmax);
    
    getch();
}

// After executing this code we should get the required value as 3.