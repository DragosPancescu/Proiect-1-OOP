#ifndef NOD_H
#define NOD_H


class nod
{
private:
    int val;
    nod *next;
public:
    //constructori
    nod();
	nod(int, nod *);

	//setter si getter
	void setVal(int);
	void setNext(nod *);
	int getVal();
	nod* getNext();

	//destructor
    virtual ~nod();
};

#endif // NOD_H
