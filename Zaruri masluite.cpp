#include<iostream>
using namespace std;

class DATA
{
    int a;
public:
    DATA()
    {
        a = 0;
    }
    DATA(int a1)
    {
        a = a1;
    }
    bool operator==(DATA x2)
    {
        return (a == x2.a);
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
    Node<T>* urm; // legatura la nodul urmator
    Node<T>* ant; // legatura la nodul anterior
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
            delete urm; // APEL destructor clasa Nod
        } // Se apelează recursiv (repetitiv)
        // destructorul clasei Nod, pana se
        // ajunge la ultimul element al listei
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
        head->ant = nullptr; //santinela
        sf->urm = nullptr; //santinela
    }
    ~LinkedList()
    {
        delete head; // distruge prima celula (santinela de inceput)
    } // apelare destructor clasa Nod

    int add(const T&); //adaug la finalul listei
    int lungime(); //lungime lista
    void verificare();
};

template <class T>
int LinkedList<T>::add(const T& d)
{
    if (!(sf->urm = new Node<T>())) // [2] creare nod nou
        return 1; // eroare alocare memorie

    sf->urm->ant = sf; // [3] legatura inversa nod nou -> sf
    sf->data = d; // [3] adaugare info nou in fosta santinela

    sf = sf->urm; // [4] actualizare sfarsit lista (santinela)
    sf->urm = nullptr; // [4] anulare legatura nod urmator


    return 0; // operatie terminata cu succes
}


template <class T>
int LinkedList<T>::lungime()
{
    Node<T>* crt;
    int lung = 0;
    if (head)
    {
        crt = head->urm;
        while (crt != sf)
        {
            crt = crt->urm;
            lung++;
        }
        return lung;
    }
    return -1; //eroare
}

template <class T>
void LinkedList<T>::verificare()
{
    Node<T>* tmp=head->urm;
    Node<T>* tmp2=head->urm;
    float l=lungime();
    int aux=0, nr_max=-9999, nr_min=9999;
    while(tmp->urm)
    {
        while(tmp2->urm)
        {
            if(tmp->data==tmp2->data) //verific daca elementul curent este egal cu tmp
            {
                aux++; //contorizez
                //scot elementul din lista
                tmp2->ant->urm=tmp2->urm;
                tmp2->urm->ant=tmp2->ant;
                //trec la urmatorul element
                tmp2=tmp2->urm;
            }
            else
            {
                //trec la urmatorul element
                tmp2=tmp2->urm;
            }
        }
        if(nr_max<aux)
        {
            nr_max=aux;
        }
        if(nr_min>aux)
        {
            nr_min=aux;
        }
        aux=0;
        tmp=head->urm; //actualizez tmp
        tmp2=tmp;
    }
    if(nr_max==nr_min)
    {
        nr_min=0;
    }
    if(nr_max-nr_min > 0.1*l)
        cout << 1;
    else
        cout<< 0;
}

int main()
{
    LinkedList<DATA> zaruri;
    int n;
    DATA fata;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin >> fata;
        zaruri.add(DATA(fata));
    }
    zaruri.verificare();
    return 0;
}