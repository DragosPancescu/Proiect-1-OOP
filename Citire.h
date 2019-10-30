#ifndef CITIRE_H
#define CITIRE_H
#include <iostream>
#include "multime.h"

class Citire
{
private:
    int n;
    multime *M;
public:
    Citire();
    friend ostream& operator << (ostream &, Citire &);
    friend istream& operator >> (istream &, Citire &);
    virtual ~Citire();
};

#endif // CITIRE_H
