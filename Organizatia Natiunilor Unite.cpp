#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
#include<iomanip>
using namespace std;
int main()
{
    vector<string>nume;
    vector<int>dur;
    string num,durs;
    int nr, min_dur=999, max_dur=-999,k;
    double tot=0;
    while(getline(cin,num,'\n'))
    {
        for(int i=0;i<num.length();i++)
        {
            if(isdigit(num[i])||num[i]=='-')
            {
                k=i;
                break;
            }
        }
        durs=num.substr(k);
        num.resize(k-1);
        nr=stoi(durs);
        nume.push_back(num);
        dur.push_back(nr);
    }
    for(int i=0;i<nume.size();i++)
    {
        if(min_dur>dur[i])
            min_dur=dur[i];
        if(max_dur<dur[i])
            max_dur=dur[i];
    }
    for(int i=0;i<dur.size();i++)
    {
        if(dur[i]<10||dur[i]>60)
        {
            dur.erase(dur.begin()+i);
            nume.erase(nume.begin()+i);
            i--;
        }
    }
    for(int i=0;i<dur.size();i++)
    {
        for(int j=0;j<dur.size();j++)
        {
            if(i!=j&&nume[i]==nume[j])
            {
                if(dur[j]>dur[i])
                {
                    nr=dur[i];
                    dur[i]=dur[j];
                    dur[j]=nr;
                }
                dur.erase(dur.begin()+j);
                nume.erase(nume.begin()+j);
                j--;

            }
        }
    }
    for(int i=0;i<dur.size();i++)
    {
        for(int j=0;j<dur.size();j++)
        {
            if(dur[i]>dur[j])
            {
                nr=dur[i];
                dur[i]=dur[j];
                dur[j]=nr;
                num=nume[i];
                nume[i]=nume[j];
                nume[j]=num;
            }
            else if (i!=j&&nume[i]<nume[j]&&dur[i]==dur[j])
            {
                nr=dur[i];
                dur[i]=dur[j];
                dur[j]=nr;
                num=nume[i];
                nume[i]=nume[j];
                nume[j]=num;
            }
        }
    }
    for(int i=0;i<nume.size();i++)
    {
        tot+=dur[i];
    }
    while(tot>480)
    {
        tot-=dur[0];
        dur.erase(dur.begin());
        nume.erase(nume.begin());
    }
    for(int i=0;i<nume.size();i++)
    {
        cout<<nume[i]<<","<<dur[i]<<endl;
    }
    cout<<fixed<<setprecision(0)<<tot<<" ";
    cout<<fixed<<setprecision(2)<<tot/dur.size();
    return 0;
}