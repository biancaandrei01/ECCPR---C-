#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float *Ri =new float[n];
    float R=0,S=0, aux = 0;
    for(int i=0;i<n;i++)
    {
        cin>>Ri[i];
        R+=Ri[i];
    }
    R/=n;
    for(int i=0;i<n;i++)
    {
        S+=(Ri[i] -R)*(Ri[i] -R);
    }
    S/=n;
    S=sqrtf(S);
    for(int i=0;i<n;i++)
    {
        if(Ri[i] >=(R-S) && Ri[i] <=(R+S))
        {
            aux++;
        }
    }
    cout<<fixed<<setprecision(2)<<(aux/n)*100;
    return 0;
}