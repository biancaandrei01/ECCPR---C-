#include<iostream>
#include <cmath>
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
    bool operator>=(float x2)
    {
        return (a >= x2);
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
        this->urm = nullptr;
    }
};

template<typename T>
class LinkedList
{
    Node<T>* head;
    T R;
public:
    LinkedList()
    {
        head = nullptr;
        R=0;
    }
    void add(T);
    int lungime();
    void procent(); //Procentul de rezistori cu rezistenţa în intervalul [R – S; R + S]
};
template <class T>
void LinkedList<T>::add(T item)
{
    Node<T>* node = new Node<T>[1];
    node->data = item;
    R+=item;
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
void LinkedList<T>::procent()
{
    float S=0, aux=0;
    R/=lungime();
    Node<T>*tmp=head;
    while(tmp)
    {
        S+=(tmp->data -R)*(tmp->data -R);
        tmp=tmp->urm;
    }
    S/=lungime();
    S=sqrtf(S);
    tmp=head;
    while(tmp)
    {
        if((tmp->data >=(R-S)) && (tmp->data <=(R+S)))
        {
            aux++;
        }
        tmp=tmp->urm;
    }
    cout<<fixed<<setprecision(2)<<(aux/lungime())*100;
}


int main()
{
    LinkedList<DATA> rez;
    int n;
    DATA Ri;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin >> Ri;
        rez.add(DATA(Ri));
    }
    rez.procent();
    return 0;
}