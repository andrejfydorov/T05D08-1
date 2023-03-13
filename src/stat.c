#include <stdio.h>
#include <ctype.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int check_array(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    
    if(input(data, &n) == 0 && check_array(data, n) == 0) {
        output(data, n);
        printf("\n");
        output_result(max(data, n),
                    min(data, n),
                    mean(data, n),
                    variance(data, n));
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
    for(int *p = a; p - a < n; p++)
    {
        if((p - a) == n-1) {
            printf("%d", *p);
        }else {
            printf("%d ", *p);
        }
    }
}

int max(int *a, int n)
{
    int max = *a;
    
    for(int *p = (++a); p - a < n; p++)
    {
        if(*p > max) {
            max = *p;
        }
    }

    return max;
}

int min(int *a, int n)
{
    int min = *a;
    
    for(int *p = (++a); p - a < n; p++)
    {
        if(*p < min) {
            min = *p;
        }
    }

    return min;
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

    return mean(a, n) / 2;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);

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