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
element *losuj(element *lista);


void error()
{
    while((getchar()) != '\n');
    printf("zła komenda\n");
}
element *losuj(element *lista)
{
    int ilosc=0;
    printf("\nile gitar wylosować i dodać do listy?:  ");
    if ( scanf("%d", &ilosc) != 1 )
    {
        error();
    }
    else
    {
        while ( ilosc != 0 )
        {
            element *temp=NULL;
            temp = (element*)malloc(sizeof(element));
            int zmienna = 0;

            //losowanie marki
            zmienna = rand()%10;
            char marka[][MAXNAZWA] = { "Fender", "Vintage", "Cort", "Gibson", "ESP", "Ibanez", "Yamaha", "Epiphone", "Jackson", "Fernandes" };
            strncpy( temp->marka, marka[zmienna], MAXNAZWA-1);

            //losowanie rodzaju
            zmienna = rand()%3+1;
            temp->rodzaj = zmienna;

            //losowanie roku produkcji
            zmienna = rand()%50+1963;
            temp->rok_produkcji = zmienna;

            //losowanie typu budowy
            if( temp->rodzaj == 1) //losowanie dla gitar elektrycznych
            {
                zmienna = rand()%6;
                char budowa[][MAXNAZWA] = { "stratocaster", "les paul", "flying V", "superstratocaster", "telecaster", "sg" };
                strncpy( temp->budowa, budowa[zmienna], MAXNAZWA-1);
            }
            else if( temp->rodzaj == 2) // losowanie dla akustyka
            {
                zmienna = rand()%4;
                char budowa[][MAXNAZWA] = { "western", "dreadnought", "cutaway", "ovation" };
                strncpy( temp->budowa, budowa[zmienna], MAXNAZWA-1);
            }
            else if( temp->rodzaj == 3) //dla basu
            {
                zmienna = rand()%4;
                char budowa[][MAXNAZWA] = { "standard", "standard", "standard", "inna" }; //zwiększenie wagi dla wyniki standard
                strncpy( temp->budowa, budowa[zmienna], MAXNAZWA-1);
            }

            //dodanie numeru kolejności
            numeruj(lista, temp);

            //dodanie do listy
            lista = push(lista, temp);

            ilosc--;
        }
        return lista;
    }
}

element *dodaj(element *lista)
{
    element *temp=NULL;
    temp = (element*)malloc(sizeof(element));

    printf("\npodaj markę gitary do załadowania do bazy:  ");
    if ( scanf("%19s", temp->marka) != 1 )
    {
        error();
    }
    else
    {
        printf("\nrodzaj gitary: 1-elektryczna, 2-akustyczna, 3-klasyczna:  ");
        if ( scanf("%d", &temp->rodzaj) != 1 )
        {
            error();
        }
        else
        {
            printf("\npodaj rok produkcji:  ");
            if ( scanf("%d", &temp->rok_produkcji) != 1 )
            {
                error();
            }
            else
            {
                printf("\npodaj kształt gitary:  ");
                if ( scanf("%19s", temp->budowa) != 1 )
                {
                    error();
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


void numeruj(element *lista, element *temp)
{
    if(lista == NULL)
        temp->numer = 1;
    else
        temp->numer = lista->numer + 1;

}

element *push(element *first, element *newone)
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

    return newone; //zwraca wskaźnik do ostatniego elementu!!
}


#endif // ODCZYT_H_INCLUDED
