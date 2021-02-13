#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void max_min(int array[], int n,int *min, int *max)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(array[i] > *max)
        {
            *max = array[i];
        }

        if(array[i] < *min)
        {
            *min = array[i];
        }
    }
    return;
}

int pairsum(int s1, int s2, int s3)
{
    int i,j,k;
    i = abs(s1 - s2);
    j = abs(s1 - s3);
    k = abs(s2 -s3);

    return i+j+k;
}

int divide(int array[], int n, int maximum, int m)
{
    int i,pi,sum1 = 0,sum2 = 0,sum3 = 0,end;

    int visit[n];

    for(i = 0;i<n;i++)
    {
        visit[i] = 0;
    }
    
    for(i=0;i<n;i++)
    {
        if(array[i] == maximum && !(visit[i]))
        {
            visit[i] = 1;
            
            pi = i;
            sum3 = array[i];
            break;
        }
    }
    
    if(pi == 0)
    {
        i = 1;
        end = n;
    }
    else
    {
        i = 0;
        end = pi;
    }

    printf("set1 : ");
    while(i<n && !(visit[i]) && sum1 < m)
    {   
        sum1 += array[i];
        visit[i] = 1;
        printf("%d ",array[i]);
        i++;    
    }
    printf("\n");

    

    for(i=0;i<n;i++)
    {
        if(visit[i] == 0)
        {
            sum2 += array[i];
            visit[i] = 1;
        }
    }

    return pairsum(sum1,sum2,sum3);
}

int pairwise(int array[], int n)
{
    int i;
    int maximum = -1, minimum = 1000;
    max_min(array,n,&minimum,&maximum);
    int min = pow(10,9), result;

    for(i = maximum; i > minimum-1; i--)
    {   
        result = divide(array,n,maximum,i);
        printf("i = %d\tre = %d\n",i,result);
        if(result < min)
        {
            min = result;
        }
    }
    
    return min;
}

void main()
{
    int n;
    scanf("%d",&n);

    int i,weights[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&weights[i]);
    }
    int result = pairwise(weights,n);
    printf("%d\n",result);
    return;
}