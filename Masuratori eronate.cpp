#include<iostream>
#include<cmath>
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
    float operator+(float x2)
    {
        return (a + x2);
    }
    float operator-(float x2)
    {
        return (a - x2);
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
    Node<T>* head, * crt, * sf;
public:
    LinkedList()
    {
        head = crt = new Node<T>;
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
    void verificare(int, int);
};

template <class T>
int LinkedList<T>::add(const T& d)
{
    if (!(sf->urm = new Node<T>())) // creare nod nou
        return 1; // eroare alocare memorie

    sf->urm->ant = sf; // legatura inversa nod nou -> sf
    sf->data = d; // adaugare info nou in fosta santinela
    crt = sf->urm;

    sf = sf->urm; // actualizare sfarsit lista (santinela)
    sf->urm = nullptr; // anulare legatura nod urmator


    return 0; // operatie terminata cu succes
}

template <class T>
int LinkedList<T>::lungime()
{
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
void LinkedList<T>::verificare(int l, int cnt)
{
    Node<T>* tmp = head->urm;
    float med=0, dev=0, dif = -999;
    while (tmp->urm)
    {
        med = tmp->data + med;
        tmp = tmp->urm;
    }
    med /= l;
    tmp = head->urm;
    while (tmp->urm)
    {
        dev += (tmp->data - med) * (tmp->data - med);
        tmp = tmp->urm;
    }
    dev /= l;
    dev = sqrt(dev);
    tmp = head->urm;
    if (dev / med >= 0.1)
    {
        while (tmp->urm)
        {
            if (dif < sqrtf((tmp->data - med) * (tmp->data - med)))
            {
                dif = sqrtf((tmp->data - med) * (tmp->data - med));
            }
            tmp = tmp->urm;
        }
        tmp = head->urm;
        while (tmp->urm)
        {
            if (dif == sqrtf((tmp->data - med) * (tmp->data - med)))
            {
                tmp->ant->urm = tmp->urm;
                tmp->urm->ant = tmp->ant;
                cnt++;
                l--;
                break;
            }
            tmp = tmp->urm;
        }
        return verificare(l, cnt);
    }
    cout << cnt;
}

int main()
{
    LinkedList<DATA> masuratori;
    int n;
    DATA mas;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mas;
        masuratori.add(DATA(mas));
    }
    masuratori.verificare(masuratori.lungime(), 0);
    return 0;
}