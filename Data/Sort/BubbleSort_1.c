#include<stdio.h>
int main()
{
    int h[]={1,4,23,5,2,3,465,9};
    int i,j,t;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7-i;j++)
        {
            if(h[j+1]<h[j])
            {
                t=h[j+1];
                h[j+1]=h[j];
                h[j]=t;
            }
        }
    }
    for(i=0;i<8;i++)
    {
        printf("%d ",h[i]);
    }
}
