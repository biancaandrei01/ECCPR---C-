#include <iostream>
#include <iomanip>
using namespace std;

class DATA
{
    float a;
public:
    DATA()
    {
        a = 0;
    }
    DATA(float a1)
    {
        a = a1;
    }
    bool operator>=(DATA x2)
    {
        return (a >= x2.a);
    }
    bool operator<=(float x2)
    {
        return (a <= x2);
    }
    float operator+=(DATA x2)
    {
        return (a += x2.a);
    }
    float operator/=(int x2)
    {
        return (a /= x2);
    }
    float operator-(DATA x2)
    {
        return (a - x2.a);
    }
    float operator+(float x2)
    {
        return (a + x2);
    }
    friend ostream& operator<<(ostream& os, DATA d)
    {
        os  << d.a << " ";
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
    friend class LinkedList<T>;
public:
    Node()
    {
        urm = nullptr;
    }
};

template<typename T>
class LinkedList
{
    Node<T>* head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    void add(T);
    int lungime();
    void verificare(); //Procentul de rezistori cu rezistenţa în intervalul [R – S; R + S]
};
template <class T>
void LinkedList<T>::add(T item)
{
    Node<T>* node = new Node<T>[1];
    node->data = item;
    if (head == nullptr)
    {
        head = node;
        return;
    }
    Node<T>* temp = head;
    while (temp->urm != nullptr)
    {
        temp = temp->urm;
    }
    temp->urm = node;
}

template <class T>
int LinkedList<T>::lungime()
{
    int l = 0;
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        l++;
        temp = temp->urm;
    }
    return l;
}

template <class T>
void LinkedList<T>::verificare()
{
    int aux=-1, nr=0;
    T med=0;
    Node<T>*tmp=head;
    Node<T>*tmp2=head;
    while(tmp)
    {
        while(tmp2)
        {
            if(tmp->data >= tmp2->data)
            {
                aux++;
            }
            tmp2=tmp2->urm;
        }
        if(aux>=5)
        {
            med+=tmp->data;
            nr++;
        }
        aux=-1;
        tmp=tmp->urm;
        tmp2=head;
    }
    med/=nr;
    cout<<fixed<<setprecision(2)<<med;
}

int main()
{
    LinkedList<DATA> valori;
    int n1,n2;
    DATA val;
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        cin >> val;
        valori.add(DATA(val));
    }
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cin >> val;
        valori.add(DATA(val));
    }
    valori.verificare();
    return 0;
}