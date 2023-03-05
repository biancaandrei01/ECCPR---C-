#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>labirind, I, J;
    int m, n, elmax = -999, aux = 0, k, l, cnt = 1;
    bool f = false;
    char x;
    cin >> m >> n;
    vector<vector<int>>lab(m, vector<int>(n));
    for (int i = 0; i < lab.size(); i++)
    {
        for (int j = 0; j < lab[i].size(); j++)
        {
            cin >> lab[i][j];
            labirind.push_back(lab[i][j]);
            if (elmax < lab[i][j])
            {
                elmax = lab[i][j];
            }
        }
    }
    cin >> x;
    switch (x)
    {
        case 'a':
            for (int i = 0; i <= elmax; i++)
            {
                for (int j = 0; j < labirind.size(); j++)
                {
                    if (labirind[j] == i)
                    {
                        aux++;
                    }
                }
                if (aux)
                {
                    cout << i << ": " << aux << endl;
                }
                aux = 0;
            }
            break;

        case 'b':
            for (int i = 0; i <= elmax; i++)
            {
                for (int j = 0; j < labirind.size(); j++)
                {
                    if (labirind[j] == i)
                    {
                        aux++;
                    }
                }
                if (aux == 1)
                {
                    cout << i << " ";
                }
                aux = 0;
            }
            break;

        case 'c':
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 || (i < m - 1 && j == 0) || (i < m - 1 && j == n - 1) || i == (m - 1))
                    {
                        if (lab[i][j] == 1)
                        {
                            k = i;
                            l = j;
                            f = true;
                        }
                    }
                }
            }
            if (f)
            {
                cout << k << " " << l << endl;
            }
            else
                cout << "NU" << endl;

            break;

        case 'd':
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 || (i < m - 1 && j == 0) || (i < m - 1 && j == n - 1) || i == (m - 1))
                    {
                        if (lab[i][j] == 1)
                        {
                            k = i;
                            l = j;
                            f = true;
                        }
                    }
                }
            }
            if (!f)
            {
                cout << "NU" << endl;
            }
            else
            {
                while (f)
                {
                    if (k == 0 && l == 0)
                    {
                        cnt++;
                        if (cnt == lab[k][l + 1])
                            l++;
                        else if (cnt == lab[k + 1][l])
                            k++;
                        else
                            f = false;
                    }
                    else if (k > 0 && l == 0 && k < m - 1)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                            k--;
                        else if (cnt == lab[k + 1][l])
                            k++;
                        else if (cnt == lab[k][l + 1])
                            l++;
                        else
                            f = false;
                    }
                    else if (k == m - 1 && l == 0)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                            k--;
                        else if (cnt == lab[k][l + 1])
                            l++;
                        else
                            f = false;
                    }
                    else if (k == m - 1 && l > 0 && l < n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                            l--;
                        else if (cnt == lab[k - 1][l])
                            k--;
                        else if (cnt == lab[k][l + 1])
                            l++;
                        else
                            f = false;
                    }
                    else if (k == 0 && l > 0 && l < n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                            l--;
                        else if (cnt == lab[k + 1][l])
                            k++;
                        else if (cnt == lab[k][l + 1])
                            l++;
                        else
                            f = false;
                    }
                    else if (k == 0 && l == n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                            l--;
                        else if (cnt == lab[k + 1][l])
                            k++;
                        else
                            f = false;
                    }
                    else if (k > 0 && k < m - 1 && l == n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                            k--;
                        else if (cnt == lab[k][l - 1])
                            l--;
                        else if (cnt == lab[k + 1][l])
                            k++;
                        else
                            f = false;
                    }
                    else if (k == m - 1 && l == n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                            l--;
                        else if (cnt == lab[k - 1][l])
                            k--;
                        else
                            f = false;
                    }
                    else if (k > 0 && k < m - 1 && l>0 && l < n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                            k--;
                        else if (cnt == lab[k][l - 1])
                            l--;
                        else if (cnt == lab[k + 1][l])
                            k++;
                        else if (cnt == lab[k][l + 1])
                            l++;
                        else
                            f = false;
                    }
                    else
                        f = false;
                }
                if (k == 0 || (k < m - 1 && l == 0) || (k < m - 1 && l == n - 1) || k == (m - 1))
                    cout << k << " " << l << endl;
                else
                    cout<<"NU"<<endl;
            }

            break;

        case 'e':
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 || (i < m - 1 && j == 0) || (i < m - 1 && j == n - 1) || i == (m - 1))
                    {
                        if (lab[i][j] == 1)
                        {
                            k = i;
                            l = j;
                            f = true;
                            I.push_back(i);
                            J.push_back(j);
                        }
                    }
                }
            }
            if (!f)
            {
                cout << "NU" << endl;
            }
            else
            {
                while (f)
                {
                    if (k == 0 && l == 0)
                    {
                        cnt++;
                        if (cnt == lab[k][l + 1])
                        {
                            l++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k + 1][l])
                        {
                            k++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k > 0 && l == 0 && k < m - 1)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                        {
                            k--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k + 1][l])
                        {
                            k++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k][l + 1])
                        {
                            l++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k == m - 1 && l == 0)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                        {
                            k--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k][l + 1])
                        {
                            l++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k == m - 1 && l > 0 && l < n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                        {
                            l--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k - 1][l])
                        {
                            k--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k][l + 1])
                        {
                            l++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k == 0 && l > 0 && l < n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                        {
                            l--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k + 1][l])
                        {
                            k++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k][l + 1])
                        {
                            l++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k == 0 && l == n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                        {
                            l--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k + 1][l])
                        {
                            k++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k > 0 && k < m - 1 && l == n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                        {
                            k--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k][l - 1])
                        {
                            l--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k + 1][l])
                        {
                            k++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k == m - 1 && l == n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k][l - 1])
                        {
                            l--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k - 1][l])
                        {
                            k--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else if (k > 0 && k < m - 1 && l>0 && l < n - 1)
                    {
                        cnt++;
                        if (cnt == lab[k - 1][l])
                        {
                            k--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k][l - 1])
                        {
                            l--;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k + 1][l])
                        {
                            k++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else if (cnt == lab[k][l + 1])
                        {
                            l++;
                            I.push_back(k);
                            J.push_back(l);
                        }
                        else
                            f = false;
                    }
                    else
                        f = false;
                }
                if (k == 0 || (k < m - 1 && l == 0) || (k < m - 1 && l == n - 1) || k == (m - 1))
                {
                    for(int q=I.size()-1;q>=0;q--)
                    {
                        cout<<I[q]<<" "<<J[q]<<endl;
                    }
                }
                else
                    cout<<"NU"<<endl;
            }
            break;

        default:
            break;
    }
    return 0;
}