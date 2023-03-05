#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    vector<double>X,Y,Z;
    double x,y,z,xc,yc,zc,dmin=99999,d,D=0;
    int n,aux;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>x>>y>>z;
        X.push_back(x);
        Y.push_back(y);
        Z.push_back(z);
    }
    cout<<endl;
    aux=n;
    X.erase(X.begin()+aux);
    Y.erase(Y.begin()+aux);
    Z.erase(Z.begin()+aux);
    while(!X.empty())
    {
        for(int i=0;i < X.size();i++)
        {
            d=sqrt((x-X[i])*(x-X[i])+(y-Y[i])*(y-Y[i])+(z-Z[i])*(z-Z[i]));
            if(dmin>d || i==0)
            {
                dmin=d;
                aux=i;
                xc=X[i];
                yc=Y[i];
                zc=Z[i];
            }
        }
        D+=dmin;
        x=xc;
        y=yc;
        z=zc;
        X.erase(X.begin()+aux);
        Y.erase(Y.begin()+aux);
        Z.erase(Z.begin()+aux);
    }
    cout<<fixed<<setprecision(2)<<D;
    return 0;
}