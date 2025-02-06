//1. x and n are input through keyboard. Write a program to compute x^n , n! , nCr , nPr

#include<stdio.h>

int factorial(int a){ //factorial function is defined here because we will need to use it multiple times
    int fact=1, cnt;
    for(cnt=1; cnt<=a; cnt++)
    {
        fact*=cnt;
    }
    return fact;
}

int main()
{
    int t,x,n,A,prod=1,r;

    printf("Enter 1 for x^n || 2 for n! || 3 for nCr || 4 for nPr\n");
    scanf("%d",&t);

    if (t==1){
        for(int i=0; i<n; i++){
            scanf("%d%d",&x,&n);
            prod=prod*x;
        }
        printf("%d",prod);
    }

    else if(t==2){
        for(int i=1; i<=n; i++){
            scanf("%d",&n);
            A= factorial(n);
        }
        printf("%d",A);
    }

    else if(t==3){
        float ncr;
        scanf("%d%d",&n,&r);
        ncr=factorial(n)/(factorial(r)*factorial(n-r));
        printf("%0.2f",ncr);

    }
    else if(t==4){
        float npr;
        scanf("%d%d",&n,&r);
        npr=factorial(n)/factorial(n-r);
        printf("%0.2f",npr);
    }
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//2. Write a program to determine the GCD (greatest common divisor) and LCM (least common multiple) of 3 numbers.

#include<stdio.h>

int main()
{
    int a,b,c,max,min,t;

    printf("1 for LCM, 2 for GCD\n");
    scanf("%d",&t);

    printf("Enter three numbers: ");
    scanf("%d%d%d",&a,&b,&c);

    if(t==1)
    {
        max=a;

        if(b>=c && b>=a)
            max=b;
        else if(c>=a && c>=b)
            max=c;

        for(int i=max; 1; i++){
            if(i%a==0 && i%b==0 && i%c==0){
                printf("LCM is %d",i);
                break;
            }
        }
    }
    else if(t==2)
    {
        min=a;

        if(b<=c && b<=a)
            min=b;
        else if(c<=a && c<=b)
            min=c;

        for(int i=min; 1 ;i--){
            if(a%i==0 && b%i==0 && c%i==0){
                printf("GCD is %d",i);
                break;
                }
            }
    }


}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//4. Write a program to determine all prime numbers within the range [a … b] where a & b are input through keyboard.

#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d%d",&a,&b);

    for(int i=a; i<=b; i++)
    {
        int is_prime=1;    // is_prime = 1 means the number is prime.


        for(int j=2; j<i; j++)
        {
            if(i%j==0){
                is_prime=0;
            }
        }

        if(is_prime==0 || i==1)
            printf("%d not prime\n",i);
        else
            printf("%d     prime\n",i);
    }

//is_prime is declared inside the outer for loop because it needs to be reset to 0 for every iteration
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//****[Lab-6 pdf ---- problem 6 (similar type)]****
//Check if a number n is prime.

#include<stdio.h>

int main()
{
    int n, is_prime=1;
    scanf("%d",&n);

    for(int i=2; i<n; i++)
    {
        if(n%i==0){
            is_prime=0;
            break;
        }
    }

    if(is_prime==0 || n==1)
        printf("%d is not prime",n);
    else
        printf("%d is prime",n);
}

//is_prime is declared outside for loop because if is_prime becomes 0 for one instance it doesn't need to test again
//and thus doesn't need to reset to 1 again.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//6. Write a program to find out first n perfect number where n is the input from user.

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1,counter=0; counter<n; i++)
    {
        int sum=0;

        for(int j=1 ; j<i ; j++){
            if(i%j==0){
                sum+=j;
            }
        }
        if(i==sum){
            counter++;
            printf("%d ",i);
        }
    }
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//7. Write a program to find first n Fibonacci number where n is the input from user

#include<stdio.h>
int main()
{
    int n,a=0,b=1,c; // a and b are the 1st 2 terms of the fibonacci series, c is temp
    scanf("%d",&n);

    for(int i=0; i<n; i++){

        printf("%d ",a);

        c=a+b;
        a=b;
        b=c;
    }

}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//11.Write a program to print out all Armstrong numbers between 1 and 10000.
//If sum of cubes (QUESTION BHUL) of each digit of the number is equal to the number itself, then the number is called an Armstrong number

#include <stdio.h>

int main()
{
    int num, n, cd; // cd = current digit

    for (int i = 1; i <= 10000; i++) {
        int sum = 0, counter = 0;
        n = i;

         //Step 1: Count the number of digits
        int temp = i;
        while (temp != 0) {
            counter++;
            temp /= 10;
        }

         //Step 2: Calculate the sum of powers of digits
        temp = i; // Reset temp to the original number
        while (temp != 0) {
            cd = temp % 10;

             //Calculate cd^counter
            int power = 1;
            for (int j = 0; j < counter; j++) {
                power *= cd;
            }

            sum += power;
            temp /= 10;
        }

         //Step 3: Check for Armstrong number
        if (i == sum) {
            printf("%d ", i);
        }
    }

    return 0;
}

