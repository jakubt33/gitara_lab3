#ifndef ODCZYT_H_INCLUDED
#define ODCZYT_H_INCLUDED

#define STOP -1
#define WORK 1

element *dodaj(element *lista);
void error();
void nazwa_marki(element *, int *);
void numeruj(element *, element *);
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
    element *temp=NULL;
    temp = (element*)malloc(sizeof(element));

    printf("\npodaj markę gitary do załadowania do bazy:  ");
    if ( scanf("%19s", temp->marka) != 1 )
    {
        error();
        dzialaj = STOP;
    }
    else
    {
        printf("\nrodzaj gitary: 1-elektryczna, 2-akustyczna, 3-klasyczna:  ");
        if ( scanf("%d", &temp->rodzaj) != 1 )
        {
            error();
            dzialaj = STOP;
        }
        else
        {
            printf("\npodaj rok produkcji:  ");
            if ( scanf("%d", &temp->rok_produkcji) != 1 )
            {
                error();
                dzialaj = STOP;
            }
            else
            {
                printf("\npodaj kształt gitary:  ");
                if ( scanf("%19s", temp->budowa) != 1 )
                {
                    error();
                    dzialaj = STOP;
                }
                else
                {
                    printf("\npoprawdnie dodano nową gitarę\n");
                    numeruj(lista, temp);
                    lista = push(lista, temp);
                    return lista;
                }
            }
        }
    }
}

element *wczytaj_z_pliku()
{

}


void numeruj(element *lista, element *temp) // tu bedzie mozna zobaczyc numer w lista->prior
{
    if(lista == NULL)
        temp->numer = 1;
    else
        temp->numer = lista->numer + 1;

    /*
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
    */
}

element *push(element *first, element *newone) //tu dodac prior
{
    element *temp=first;
    if(first==NULL)
    {
        newone->prior = NULL;
        return newone;
    }


    while(temp->next!=NULL)
        {
            temp->prior = temp;
            temp = temp->next;
        }
    newone->prior = temp;
    temp->next=newone;

    return newone;
}


#endif // ODCZYT_H_INCLUDED
