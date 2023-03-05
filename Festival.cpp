#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<string>nume;
    vector<int>nrv;
    char x;
    string num;
    int n, nr, cnt;
    cin>>x>>n;
    switch(x)
    {
        case 'a':
            for(int i=0;i<n;i++)
            {
                getline(cin,num,',');
                cin>>nr;
                nume.push_back(num);
                nrv.push_back(nr);
            }
            num=nume[0];
            while(!nume.empty())
            {
                cnt=nrv[0];
                for(int i=1;i < nume.size();i++)
                {
                    if(nume[i]==num)
                    {
                        cnt+=nrv[i];
                        nume.erase(nume.begin()+i);
                        nrv.erase(nrv.begin()+i);
                        i--;
                    }
                }
                if(cnt>=5)
                {
                    cout<<nume[0]<<", "<<cnt<<endl;
                }
                nume.erase(nume.begin());
                nrv.erase(nrv.begin());
                if(!nume.empty())
                    num=nume[0];
            }
            break;

        case 'b':
            while(getline(cin, num, ','))
            {
                cin >> nr;
                nume.push_back(num);
                nrv.push_back(nr);
            }
            cnt=1;
            while(!nume.empty()&&n)
            {
                for(int i=0;i<nume.size();i++)
                {
                    if(nrv[i]==1)
                    {
                        cout<<nume[i]<<" ";
                        nume.erase(nume.begin()+i);
                        nrv.erase(nrv.begin()+i);
                        break;
                    }
                }
                for(int i=0;i<nume.size();i++)
                {
                    if(nrv[i]==2)
                    {
                        cout<<nume[i]<<" ";
                        nume.erase(nume.begin()+i);
                        nrv.erase(nrv.begin()+i);
                        break;
                    }
                }
                for(int i=0;i<nume.size();i++)
                {
                    if(nrv[i]==3)
                    {
                        cout<<nume[i]<<" ";
                        nume.erase(nume.begin()+i);
                        nrv.erase(nrv.begin()+i);
                        break;
                    }
                }
                n--;
            }
            break;

        case 'c':
            cin.ignore();
            for(int i=0;i<n;i++)
            {
                getline(cin,num,'\n');
                nume.push_back(num);
            }
            for(int i=0;i<nume.size();i++)
            {
                for(int j=0;j<nume.size();j++)
                {
                    if(nume[i]<nume[j])
                    {
                        num=nume[i];
                        nume[i]=nume[j];
                        nume[j]=num;
                    }
                }
            }
            for(int i=0;i<nume.size();i++)
            {
                cout<<nume[i]<<" ";
            }
            break;
        default:
            break;
    }
    return 0;
}