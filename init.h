#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED


#define MAXNAZWA 20


typedef struct element
{
    struct element *next;
    struct element *prior;
    int numer; //numer kazdego obrazka w liscie
    int czy_nowa; //1 tak, 2 nie
    int jaki_gryf; //1-wklejany, 2-wkręcany
    int ile_strun;
    int rodzaj; //1-elektryk, 2 akustyk, 3 klasyk
    char marka[MAXNAZWA];
    char budowa[MAXNAZWA];  //strat, LP, V, exp, itp
} element;

#endif // INIT_H_INCLUDED
