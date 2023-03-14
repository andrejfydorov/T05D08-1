/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int check_array(int *a, int n);

int main()
{
    int n, data[NMAX];
    
    if(input(data, &n) == 0 && check_array(data, n) == 0) {
        output(data, n);
    }else {
        printf("n/a");
    }
    

    return 0;
}

int input(int *a, int *n)
{
    scanf("%d", n);
    for(int *p = a; p - a < *n; p++)
    {
        if(scanf("%d", p) != 1) {
            return -1;
        }
    }
    return 0;
}

void output(int *a, int n)
{
    int res = 0;
    double m = mean(a, n);
    double v = variance(a, n);
    for(int *p = a; p - a < n; p++)
    {
        if (*p != 0)
        {
           if (((*p) % 2) == 0)
           {
                if (*p >= m)
                {
                    if (abs((long)(*p - m)) < (3 * sqrt(v)) )
                    {
                        res = *p;
                    }
                    
                }
                
           }
           
        }
        
    }
    printf("%d", res);
}

double mean(int *a, int n) {
    double sum = 0;
    for(int *p = a; p - a < n; p++)
    {
        sum += *p;
    }

    return sum / n;
}

double variance(int *a, int n) {
    double m1 = mean(a, n);
    int arr[NMAX];
    for(int *p = a; p - a < n; p++)
    {
        arr[p-a] = (*p) * (*p);
    }
    double m2 = mean(arr, n);
    return m2 - (m1 * m1);
}

int check_array(int *a, int n) {
    int res = 0;
    for(int *p = a; p - a < n; p++)
    {
        if(isdigit(*p) != 0) {
            return -1;
        }
    }

    return res;
}