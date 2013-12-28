#ifndef EDYCJA_H_INCLUDED
#define EDYCJA_H_INCLUDED

void sortuj(element *);
void sortuj_rocznik(element*);
void sortuj_rodzaj(element*);
void sortuj_marka(element*);
void sortuj_budowa(element *);
void szukaj(element *);

void szukaj(element *lista) //sprawdzic zabezpieczina
{
    if(lista != NULL)
    {
        printf("\nwpisz poszukiwaną frazę(w nazwie):");
        char nazwa[MAXNAZWA];
        if ( scanf("%s", nazwa) != 1 )
        {
            error();
        }
        else
        {
            element *szukaj_lista=NULL;
            char temp_nazwa[strlen(nazwa)+1];
            int koniec = NIE;
            while(koniec == NIE) //dla kazdego elementu z listy
            {
                if(strlen(nazwa)<=strlen(lista->marka))
                {
                    int licznik_1=0;
                for(licznik_1=0; licznik_1<(strlen(lista->marka)-strlen(nazwa)+1); licznik_1++) //dla kadego mozliwego miejsca w nazwie marki szukaengo fragmentu
                {
                    int t_licznik=0, licznik=0;
                    for(licznik=licznik_1; licznik<strlen(nazwa)+licznik_1; licznik++ ) //kopiowanie fragmentu do tempa
                    {
                        temp_nazwa[t_licznik] = lista->marka[licznik];
                        t_licznik++;
                    }
                    temp_nazwa[strlen(nazwa)] = '\0';
                    //printf("temp nazwa to %s\n", temp_nazwa); fajne do debugowania lub patrzenia jak zarąbiscie dziala ;D

                    if(strcmp(temp_nazwa, nazwa) == 0)
                    {
                        element *temp = NULL;
                        temp = (element*)malloc(sizeof(element));

                        temp->rodzaj = lista->rodzaj;
                        temp->rok_produkcji = lista->rok_produkcji;
                        temp->numer = lista->numer;
                        strcpy( temp->marka, lista->marka);
                        strcpy( temp->budowa, lista->budowa);

                        szukaj_lista = push(szukaj_lista, temp);
                        //printf("pasue\n"); fajne do debugowaina ;D
                    }

                }
                }
                if(lista->next == NULL)
                    koniec = TAK;
                else
                    lista = lista->next;
            }
            wyswietl(szukaj_lista);
            printf("po wyjściu z tej opcji wyszukane rekordy zostaną usunięte z tymczasowego bufora\n");
            szukaj_lista = usun(szukaj_lista);
        }

    }
}



void sortuj(element *lista)
{
    if(lista != NULL)
    {
        printf("\npo jakim elemencie posortować? 1-rocznik, 2-marka, 3-rodzaj, 4-budowa:  ");
        int wybor=0;
        if ( scanf("%d", &wybor) != 1 )
        {
            error();
        }
        else
        {
            switch (wybor)
            {
            case 1:
            {
                sortuj_rocznik(lista);
                numeruj(lista);
                break;
            }
            case 2:
            {
                sortuj_marka(lista);
                numeruj(lista);
                break;
            }
            case 3:
            {
                sortuj_rodzaj(lista);
                numeruj(lista);
                break;
            }
            case 4:
            {
                sortuj_budowa(lista);
                numeruj(lista);
                break;
            }
            }
        }
    }
    else
        printf("brak gitar w bazie\n");
}
void sortuj_budowa(element *lista)
{
    int czy_posortowane = NIE;

    while(czy_posortowane == NIE)
    {
        while(lista->prior != NULL)
            lista = lista->prior; //cofniecie sie na począstek listy

        int licznik = 0;
        while(lista->next != NULL)
        {
            if(strcmp(lista->budowa, lista->next->budowa) > 0 )
            {
                element *temp = NULL;
                temp = lista->prior;
                lista->prior = lista->next;
                lista->next = lista->next->next;
                if(lista->next != NULL)
                    lista->next->prior = lista;

                lista->prior->next = lista;
                lista->prior->prior = temp;
                if(lista->prior->prior != NULL)
                    lista->prior->prior->next = lista->prior;
                licznik++;
            }
            if(lista->next != NULL)
                lista = lista->next;
        }

        if(licznik == 0)
            czy_posortowane = TAK;
    }
}

void sortuj_marka(element *lista)
{
    int czy_posortowane = NIE;

    while(czy_posortowane == NIE)
    {
        while(lista->prior != NULL)
            lista = lista->prior; //cofniecie sie na począstek listy

        int licznik = 0;
        while(lista->next != NULL)
        {
            if(strcmp(lista->marka, lista->next->marka) > 0 )
            {
                element *temp = NULL;
                temp = lista->prior;
                lista->prior = lista->next;
                lista->next = lista->next->next;
                if(lista->next != NULL)
                    lista->next->prior = lista;

                lista->prior->next = lista;
                lista->prior->prior = temp;
                if(lista->prior->prior != NULL)
                    lista->prior->prior->next = lista->prior;
                licznik++;
            }
            if(lista->next != NULL)
                lista = lista->next;
        }

        if(licznik == 0)
            czy_posortowane = TAK;
    }
}

void sortuj_rocznik(element *lista)
{
    int czy_posortowane = NIE;

    while(czy_posortowane == NIE)
    {
        while(lista->prior != NULL)
            lista = lista->prior; //cofniecie sie na począstek listy

        int licznik = 0;
        while(lista->next != NULL)
        {
            if(lista->rok_produkcji > lista->next->rok_produkcji )
            {
                element *temp = NULL;
                temp = lista->prior;
                lista->prior = lista->next;
                lista->next = lista->next->next;
                if(lista->next != NULL)
                    lista->next->prior = lista;

                lista->prior->next = lista;
                lista->prior->prior = temp;
                if(lista->prior->prior != NULL)
                    lista->prior->prior->next = lista->prior;
                licznik++;
            }
            if(lista->next != NULL)
                lista = lista->next;
        }

        if(licznik == 0)
            czy_posortowane = TAK;
    }
}
void sortuj_rodzaj(element *lista)
{
    int czy_posortowane = NIE;

    while(czy_posortowane == NIE)
    {
        while(lista->prior != NULL)
            lista = lista->prior; //cofniecie sie na począstek listy

        int licznik = 0;
        while(lista->next != NULL)
        {
            if(lista->rodzaj > lista->next->rodzaj )
            {
                element *temp = NULL;
                temp = lista->prior;
                lista->prior = lista->next;
                lista->next = lista->next->next;
                if(lista->next != NULL)
                    lista->next->prior = lista;

                lista->prior->next = lista;
                lista->prior->prior = temp;
                if(lista->prior->prior != NULL)
                    lista->prior->prior->next = lista->prior;
                licznik++;
            }
            if(lista->next != NULL)
                lista = lista->next;
        }

        if(licznik == 0)
            czy_posortowane = TAK;
    }
}

#endif // EDYCJA_H_INCLUDED
