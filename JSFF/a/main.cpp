#include <bits/stdc++.h>

using namespace std;

static vector<double> X, preX, f;
static vector<vector<double>> B;

void Jacobi()
{
    while(max(fabs(X[0]-preX[0]), min(fabs(X[1]-preX[1]), fabs(X[2]-preX[2]))) > 0.005)
    {
        for(unsigned int i = 0; i < 3; ++i)
            printf("%.5f ", X[i]);
        for(unsigned int i = 0; i < 3; ++i)
            preX[i] = X[i];
        for(unsigned int i = 0; i < 3; ++i){
            X[i] = f[i];
            for(unsigned int j = 0; j < 3; ++j)
                X[i] += preX[j]*B[i][j];
        }

        getchar();
    }
}

void Guess()
{
    while(max(fabs(X[0]-preX[0]), min(fabs(X[1]-preX[1]), fabs(X[2]-preX[2]))) > 0.005)
    {
        for(unsigned int i = 0; i < 3; ++i)
            printf("%.5f ", X[i]);
        for(unsigned int i = 0; i < 3; ++i)
            preX[i] = X[i];
        for(unsigned int i = 0; i < 3; ++i){
            X[i] = f[i];
            for(unsigned int j = 0; j < 3; ++j)
                X[i] += (i <= j)?preX[j]*B[i][j]:X[j]*B[i][j];
        }

        getchar();
    }
}
int main()
{
    B.push_back({0,2,-2});
    B.push_back({1,0,1});
    B.push_back({2,2,0});
    f = {-12,0,10};
    X = {0,0,0};
    preX = {-1,-1,-1};
    //Jacobi();
    Guess();
}
