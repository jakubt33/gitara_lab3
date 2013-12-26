#ifndef ODCZYT_H_INCLUDED
#define ODCZYT_H_INCLUDED

#define STOP -1
#define WORK 1

void error();
void nazwa_marki(element *, int *);
void numeruj(element *first);
element *push(element *, element *);
void zwolnij_tablice(element *temp);


void error()
{
    while((getchar()) != '\n');
    printf("zła komenda\n");
}
element *losuj()
{

}

element *dodaj(element *lista)
{
    int dzialaj = TAK;
    nazwa_marki(lista, &dzialaj);
    //cos tam dalej
}

element *wczytaj_z_pliku()
{

}

void nazwa_marki(element *temp, int *dzialaj)
{
    printf("podaj markę gitary do załadowania do bazy:  ");
    if ( scanf("%19s", temp->marka) != 1 )
    {
        error();
        *dzialaj = STOP;
    }
}
void numeruj(element *first) // tu bedzie mozna zobaczyc numer w lista->prior
{
    int licznik=0;
    if(first==NULL)
    {
        printf("lista jest pusta\n");
    }
    else
    {
        do
        {
            licznik++;
            first->numer=licznik;
            first=first->next; //modyfikuijmy tylko kopie wskaznika!
        }
        while(first!=NULL);
    }
}

element *push(element *first, element *newone) //tu dodac prior
{
    element *temp=first;
    if(first==NULL)
        return newone;

    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newone;
    return first;
}


#endif // ODCZYT_H_INCLUDED
