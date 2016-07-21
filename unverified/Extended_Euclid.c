#include<stdio.h>
typedef long long int lli;
void gcd(lli a, lli b, lli *d, lli *x, lli *y)
{
    if(!b){*d = a;*x = 1; *y = 0;}
    else {gcd(b, a%b, d, y, x); (*y) -= (*x)*(a/b);}
}


int main()
{
    lli a = 35, b = 56, d, x, y;
    gcd(a, b, &d, &x, &y);


    return 0;
}
