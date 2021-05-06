/* 
THE ROPE AND WEIGHTS PROBLEM

This is refurmulation of the well-known egg-dropping problem.
It was given to me as an assigment for a position as algorithm developer
at a Swiss Company in late April 2021.

PROBLEM SETTING

You have M identical ropes and N identical weights.
You want to do an experiment to determine the strength S of the identical ropes
by  testinghow many weights can be held by one single rope.
The strength S of the ropes is defined as an integer as follows:
- ff a rope breaks with the first weight, S=0;
- if a rope can hold n weights and breaks at n+1 weights, S=n;
- if a rope can hold all N weights, S=N.
In one test (“test” means to check if one rope can hold an amount of weights), 
if the rope breaks, you have to take another rope to continue the experiment;
if the rope does not break, it can be used for the next test with no problem.
If you used up all the ropes but still cannot determine the strength S of the ropes, 
the experiment fails.

TASK

Write a program that given M and N as inputs, calculates the minimum number
of tests T needed to guarantee you can determine S.
*/

#include <iostream>


int binomialCoeff(int n, int k)
// Returns value of Binomial Coefficient C(n, k)
{
    int res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}


int aux_fun(int M, int k) {
    if (k * M == 0) {
        return 0;
    } else {
        int S = 0;
        for (int j = 1; j < M + 1; j++) {
            int binomial=binomialCoeff(k, j);
            S = S + binomial;
        }
        return S;
    }
}

int T(int M, int N) {
    // T(M, N)
    int k = 1;
    int tmp=aux_fun(M, k);
    while (N > tmp) {
        k++;
        tmp=aux_fun(M, k);
    }
    return k;
}

int main() {
    int M;
    int N;
    // Test with M = 2 and N = 11
    std::cout<<"Enter the number M of ropes:"<<std::endl;
    std::cin>>M;
    std::cout<<"Enter the number N of weights:"<<std::endl;
    std::cin>>N;
    std::cout<<"If you follow an optimal strategy, you need at most "<<T(M,N)<<" tests."<<std::endl;
    return 0;
}