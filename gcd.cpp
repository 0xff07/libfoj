/* Use recursive method to prtform Euclid's algorithm */
/* Use gdb to set "break gcd" will help a lot when    */
/* trying to understand this algorithm.		      */
/* Example below showa how it works when finding gcd  */
/* of (12, 45)					      */
/*
    Breakpoint 1, gcd (a=12, b=45) at gcd.cpp:11
    11	    return (b == 0)?a:gcd(b, a % b);
    (gdb) s

    Breakpoint 1, gcd (a=45, b=12) at gcd.cpp:11
    11	    return (b == 0)?a:gcd(b, a % b);
    (gdb) 

    Breakpoint 1, gcd (a=12, b=9) at gcd.cpp:11
    11	    return (b == 0)?a:gcd(b, a % b);
    (gdb) 

    Breakpoint 1, gcd (a=9, b=3) at gcd.cpp:11
    11	    return (b == 0)?a:gcd(b, a % b);
    (gdb) 

    Breakpoint 1, gcd (a=3, b=0) at gcd.cpp:11
    11	    return (b == 0)?a:gcd(b, a % b);
    (gdb) 
    main () at gcd.cpp:22
    22	            printf("    Bad Choice\n");

*/




#include<cstdio>
#include<iostream>

long long int gcd(long long int a, long long int b)
{
    return (b == 0)?a:gcd(b, a % b);
}

int main()
{
    long long int a, b;
    while(scanf("%lld%lld", &a, &b) != EOF){
        printf("%10lld%10lld", a, b);
        if(gcd(a, b) == 1)
            printf("    Good Choice\n");
        else     
            printf("    Bad Choice\n");
        printf("\n");
    }

    return 0;
}
