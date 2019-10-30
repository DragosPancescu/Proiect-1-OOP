#include "multime.h"
#include "nod.h"
#include <stddef.h>
#include <iostream>

using namespace std;

multime::multime()
{
    start = finish = NULL;
    msize = 0;
}

multime::multime(int x)
{
    start = finish = new nod(x, NULL);
    msize = 1;
}

void multime::insertLast(int x) //insereaza elemente in multime la sfarsitul acesteia.
{
    if (start == NULL)
    {
        start = finish = new nod(x, NULL);
        msize = 1;
        return;
    }
    else
    {
        nod *p = new nod(x, NULL);
        finish->setNext(p);
        finish = p;
        msize ++;
        return;
    }
}

void multime::removeElem(int i) //elimina un element dupa pozitia sa.
{
    nod *p = start;
    if (i == 0)
    {
        if (msize == 1)
            start = finish = NULL;
        else
        {
            start = start->getNext();
            delete p;
        }
    }
    else
    {
        for (int j=0; j<i-1; j++)
            p = p->getNext();
        nod *o = p->getNext();
        p->setNext(o->getNext());
        delete o;
    }
    msize --;
}

void multime::removeElem_byVal(int x)
{

}

void multime::deleteMult()  //sterge multimea si o reseteaza.
{
    nod *o = start;
    while (o != NULL)
    {
        nod *p = o->getNext();
        delete o;
        o = p;
    }
    start = finish = NULL;
    msize = 0;
}

bool multime::isElem(int x)  //determina daca exista acel element in multime.
{
    nod *o = start;
    for (int i=0; i<msize; i++)
        if (o->getVal() == x)
            return true;
        else
            o = o->getNext();
    return false;
}

multime multime::VtoM(int n, int *V) //transforma un vector intr-o multime.
{
    multime A;
    for (int i=0; i<n; i++)
        if (A.isElem(V[i]) == false)
            A.insertLast(V[i]);
    return A;
}

void multime::operator = (multime A)
{
    nod *o = A.start;
    deleteMult();

    for (int i=0; i<A.msize; i++)
    {
        insertLast(o->getVal());
        o = o->getNext();
    }
}

multime multime::operator + (multime A)
{
    multime Aux = A;
    nod *o = start;
    for (int i=0; i<msize; i++)
    {
        if (Aux.isElem(o->getVal()) == false)
            Aux.insertLast(o->getVal());
        o = o->getNext();
    }
    return Aux;
}

multime multime::operator * (multime A)
{
    multime Aux;
    nod *o = start;
    for (int i=0; i<msize; i++)
    {
        if (A.isElem(o->getVal()) == true)
            Aux.insertLast(o->getVal());
        o = o->getNext();
    }
    return Aux;
}

multime multime::operator - (multime A)
{
    multime Aux;
    nod *o = start;
    for (int i=0; i<msize; i++)
    {
        if (A.isElem(o->getVal()) == false)
            Aux.insertLast(o->getVal());
        o = o->getNext();
    }
    return Aux;
}

ostream & operator << (ostream &out, multime &m)
{
    nod *o = m.start;

    for (int i=0; i<m.msize; i++)
    {
        out << o->getVal() << ' ';
        o = o->getNext();
    }
    out << endl;
    return out;
}

istream & operator >> (istream &in, multime &m)
{
    int val, n;
    cout << endl << "Introduceti numarul de elemente: ";
    in >> n;

    for (int i=0; i<n; i++)
    {
        cout << "Introduceti elementul cu numarul " << i+1 << ": ";
        in >> val;
        m.insertLast(val);
    }
    return in;
}

/*multime::~multime()   // nu functioneaza.
{
    nod *o = start;
    while (o != NULL)
    {
        nod *p = o->getNext();
        delete o;
        o = p;
    }
    start = finish = NULL;
    msize = 0;
}*/

multime::~multime()
{

}
