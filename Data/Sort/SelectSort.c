#include<stdio.h>
int main()
{
    int h[]={1,4,23,5,2,3,465,9};
    int i,j,t;
    for(i=0;i<7;i++)
    {
        for(j=i+1;j<8;j++)
        {
            if(h[i]<h[j])
            {
                t=h[i];
                h[i]=h[j];
                h[j]=t;
            }
        }
    }
    for(i=0;i<8;i++)
    {
        printf("%d ",h[i]);
    }
}
