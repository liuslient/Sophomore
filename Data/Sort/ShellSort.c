#include<stdio.h>
int main()
{
    int h[]={1,4,23,5,2,3,465,9};
    int i,j,t;

    int increment=8;
    do
    {
        increment=increment/3+1;
        for (i = increment; i < 8; i++) 
        {
            t = h[i];
            for (j = i - increment; j >= 0 && h[j] > t; j -= increment)
                h[j + increment] = h[j];
            h[j + increment] = t;
        }
    }while(increment>1);
    for(i=0;i<8;i++)
    {
        printf("%d ",h[i]);
    }
}
