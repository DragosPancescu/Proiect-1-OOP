#ifndef MULTIME_H
#define MULTIME_H
#include "nod.h"
#include <iostream>

using namespace std;

class multime
{
private:
    nod *start;
    nod *finish;
    int msize;
public:
    //constructori
    multime();
    multime(int);

    //modificari ale multimii
    void insertLast(int);
    void removeElem(int);
    void removeElem_byVal(int);
    void deleteMult();
    multime VtoM(int ,int *); //functine de conversie a unui vector in multime.

    //supraincarcari
    void operator = (multime); //ia valoarea
    multime operator + (multime); //reuniune
    multime operator * (multime); //intersectie
    multime operator - (multime); //diferenta
    friend ostream& operator << (ostream &, multime &);
    friend istream& operator >> (istream &, multime &);

    //cautari
    bool isElem(int );

    //destructor
    ~multime();
};

#endif // MULTIME_H
