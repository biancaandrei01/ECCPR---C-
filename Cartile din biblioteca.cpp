#include<iostream>
#include<vector>
void swap(int& a, int& b)
{
    int c;
    c=a;
    a=b;
    b=c;
}
using namespace std;
int main()
{
    vector<int>cod_carte, an_publicare;
    int cod, an, aux=1, nrc;
    while(cin>>cod>>an)
    {
        cod_carte.push_back(cod);
        an_publicare.push_back(an);
    }
    vector<int>cod_cartec, an_publicarec;
    cod_cartec=cod_carte;
    an_publicarec=an_publicare;
    for(int i=0;i<an_publicare.size();i++)
    {
        for(int j=i+1;j<an_publicare.size();j++)
        {
            if(an_publicare[i]<an_publicare[j])
            {
                swap(an_publicare[i],an_publicare[j]);
            }
        }
    }
    for(int i=0;i<an_publicare.size();i++)
    {
        cout<<an_publicare[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<cod_carte.size();i++)
    {
        for(int j=i+1;j< cod_carte.size();j++)
        {
            if(cod_carte[i]==cod_carte[j])
            {
                cod_carte.erase(cod_carte.begin()+j);
                j--;
            }
            if( cod_carte[i]> cod_carte[j])
            {
                swap( cod_carte[i], cod_carte[j]);
            }
        }
    }
    for(int i=0;i<cod_carte.size();i++)
    {
        cout<<cod_carte[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<an_publicare.size();i++)
    {
        for(int j=i+1;j< an_publicare.size();j++)
        {
            if( an_publicare[i]> an_publicare[j])
            {
                swap( an_publicare[i], an_publicare[j]);
            }
        }
    }
    for(int i=0;i<an_publicare.size();i++)
    {
        for(int j=i+1;j< an_publicare.size();j++)
        {
            if(an_publicare[i]==an_publicare[j])
            {
                an_publicare.erase(an_publicare.begin()+j);
                aux++;
                j--;
            }
        }
        cout<<an_publicare[i]<<": "<<aux<<endl;
        if(i==0)
        {
            nrc=aux;
        }
        aux=1;
    }
    cout<<nrc<<endl;
    for(int i=0;i<an_publicarec.size();i++)
    {
        if(an_publicarec[i]==an_publicare[0])
        {
            cout<<cod_cartec[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}