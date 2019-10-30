#include "nod.h"
#include <stddef.h>

nod::nod()
{
    val = 0;
    next = NULL;
}

nod::nod(int x, nod *newNod)
{
    val = x;
    next = newNod;
}

void nod::setVal(int x)
{
    val = x;
}

void nod::setNext(nod *newNod)
{
    next = newNod;
}

int nod::getVal()
{
    return val;
}

nod* nod::getNext()
{
    return next;
}

nod::~nod()
{
    //dtor
}
