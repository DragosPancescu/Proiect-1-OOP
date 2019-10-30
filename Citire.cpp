#include "Citire.h"

using namespace std;

Citire::Citire()
{
    n = 0;
    M = NULL;
}

ostream & operator << (ostream &out, Citire &K)
{
    out << endl << "Multimile sunt: " << endl;
    for (int i=0; i<K.n; i++)
    {
        out << "Multimea cu numarul " << i + 1 << " este: ";
        out << K.M[i];
        out << "-----------------------------------" << endl;
    }
    return out;
}

istream & operator >> (istream &in , Citire &K)
{
    int nrList;
    multime aux;

    cout << "Introduceti numarul de multimi: ";
    in >> nrList;
    K.n = nrList;
    K.M = new multime[K.n];

    for (int i=0; i<K.n; i++)
    {
        cout << endl << "Introduceti multimea cu numarul " << i+1 << endl;
        in >> aux;
        K.M[i] = aux;
        aux.deleteMult();
    }
    return in;
}

Citire::~Citire()
{
    //dtor
}
