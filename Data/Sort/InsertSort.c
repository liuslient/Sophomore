#include<stdio.h>
int main()
{
    int h[]={1,4,23,5,2,3,465,9};
    int i,j,t;

    for (i=1;i<8;i++)
    {
            t = h[i];
            for (j=i;j>0 && h[j-1]>t;j--)
                    h[j] = h[j-1];
            h[j] = t;
    }
    for(i=0;i<8;i++)
    {
        printf("%d ",h[i]);
    }
}
