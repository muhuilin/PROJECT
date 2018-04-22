/*
#include<math.h>
#define EPSLON 1e-7

double newton_sqrt(double n) {
    double x = 1.0;
    while(fabs(x * x - n) > EPSLON) {
        x = x - (x * x - n) / (2.0 * x);
    }
    return x;
}

int orla6(int x) {
    if(x > 100 && x < 0) return -1;
    int sum1 = (1 + x) * x / 2, sum2 = 0;
    for(int i = 1; i <= x; i++) {
        sum2 += (i * i);
    }

    return  sum1 * sum1 - sum2; 
}

int orla7(int x) {
    int prime[120000] = {0};
    prime[0] = 0;
    int is_prime[120000] = {0};
    for(int i = 2; i < x * 20; i++) {
        if(is_prime[i] == 0){
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0] && prime[j] * i <= x * 20; j++) {
            is_prime[prime[j] * i] = i;
            if(i % prime[j]) break;
        }
    }
    return prime[x];
    
}*/



#include<stdio.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
#define EPSLON 1e-7
#define max 200000
double newton_sqrt(double n) {
    if(n <= 0) {
        return -1;
    }
    double x = 1.0;
    while(fabs(x * x - n) > EPSLON) {
        x = x -(x * x - n) / (2 * x);
    }
    return x;
}

int is_prime(int n) {
    if (n <= 0) return 0;
    int  prime[max + 5] = {0};
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <n; i++) {
        if (!prime[i]) {
            for (int j = i * i; j < n; j++) {
                prime[j] = 1;   
            }
        }  
    }
    prime[0] = 0;
    for(int i = 2; i < max; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
    }
    return prime[n];
    
}

int64_t ZhiYinZi(int64_t n) {
    if (n <= 0) return 0;
    int max_prime;
    for(int i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            max_prime = i;
        }
    }
    if (n > max_prime) max_prime = n;
    return max_prime;
}

int64_t ca(int n) {
    if (n < 0 || n > 100) return -1;
    int64_t num = 0, num1 = 0, num2 = 0;
    for (int i = 0; i <= n; ++i) {
        num1 += i * i;
        num2 += i;
    }
    num = num2 * num2 - num1;
    return num;
}

int is_back(int n) {
    if(n < 0) return 0;
    int high = pow(10,floor(log10(n)));
    while(high > 0) {
        if (n / high != n % 10) return 0;
        n %= high;
        n /= 10;
        high /= 100;
    }
    return 1;
}

int PingFang(int n) {
    if (n < 0) return 0;
    int head = 0, tail = n;
    int mid;
    while(head <= tail) {
        mid = (head + tail) >>1;
        if (mid * mid == n) {
            return 1;
        } else if (mid * mid < n) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
    return 0;
}
