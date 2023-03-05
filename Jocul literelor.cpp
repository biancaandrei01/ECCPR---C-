#include<iostream>
#include<cstring>
using namespace std;

class DATA
{
    char a;
public:
    DATA()
    {
        a = 0;
    }
    DATA(char a1)
    {
        a = a1;
    }
    bool operator==(DATA x2)
    {
        return (a == x2.a);
    }
    bool operator!=(DATA x2)
    {
        return (a != x2.a);
    }

    friend ostream& operator<<(ostream& os, DATA d)
    {
        os << d.a << " ";
        return os;
    }
    friend istream& operator>>(istream& input, DATA& D)
    {
        input >> D.a;
        return input;
    }

};

template<typename T>class LinkedList;

template<typename T>
class Node
{
    T data;
    Node<T>* urm;
    Node<T>* ant;
public:
    Node()
    {
        urm = ant = nullptr;
    }
    Node(T x)
    {
        data = x;
        urm = ant = nullptr;
    }
    ~Node()
    {
        if (urm)
        {
            delete urm;
        }
    }
    friend class LinkedList<T>;
};

template<typename T>
class LinkedList
{
    Node<T>* head, * sf;
public:
    LinkedList()
    {
        head = new Node<T>;
        sf = new Node<T>();
        head->urm = sf;
        sf->ant = head;
        head->ant = nullptr;
        sf->urm = nullptr;
    }
    ~LinkedList()
    {
        delete head;
    }

    int add(const T&);
    void verificare(char, char, int, int);
};

template <class T>
int LinkedList<T>::add(const T& d)
{
    if (!(sf->urm = new Node<T>()))
        return 1;

    sf->urm->ant = sf;
    sf->data = d;


    sf = sf->urm;
    sf->urm = nullptr;


    return 0;
}

template <class T>
void LinkedList<T>::verificare(char alfa, char beta, int m, int n)
{
    Node<T>* tmp = head->urm;
    bool v = false;
    int aux = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    while (tmp->urm)
    {
        while (tmp->data != ' ' && tmp->urm->data != ' ') //cat timp ma aflu in cuvant
        {
            if (aux == 0 && tmp->data == alfa) //daca imi incepe cu litera alfa
            {
                v = true;
            }
            aux++; //contorizez nr de litere din interiorul cuvantului
            tmp = tmp->urm;
            if(tmp->urm == nullptr)
            {
                break;
            }
        }
        aux++; //contorizez si ultima litera
        if (tmp->data == beta && v) //daca se termina cu beta si incepe cu alfa
        {
            if (aux < m)
            {
                cnt1++;
            }
            if (aux >= m && aux < n)
            {
                cnt2++;
            }
            if (aux >= n)
            {
                cnt3++;
            }
        }
        aux = 0;
        v = false;
        if (tmp->urm == nullptr)
        {
            break;
        }
        tmp = tmp->urm;
    }
    cout << cnt1 << " " << cnt2 << " "<< cnt3 << endl;
}

int main()
{
    LinkedList<DATA> lst;
    char litere_fraza[4000], alfa, beta;
    int m, n;
    cin >> alfa >> beta >> m >> n;
    alfa=(char)tolower(alfa);
    beta=(char)tolower(beta);
    cin.ignore();
    cin.getline(litere_fraza, 4000, '\n');
    for (int i = 0; i < strlen(litere_fraza); i++)
    {
        lst.add((char)tolower(litere_fraza[i]));
    }
    lst.add(' ');
    lst.verificare(alfa, beta, m, n);

    return 0;
}