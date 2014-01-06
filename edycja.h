#ifndef EDYCJA_H_INCLUDED
#define EDYCJA_H_INCLUDED

void sortuj_budowa(element *);
void sortuj_marka(element*);
void sortuj_rocznik(element*);
void sortuj_rodzaj(element*);
element * szukaj_budowa(element *, element*);
element * szukaj_marka(element *, element*);
element * szukaj_rocznik(element *, element*);
element * szukaj_rodzaj(element *, element*);


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

element * szukaj_budowa(element *lista, element *szukaj_lista)
{
    if(lista != NULL)
    {
        while(lista->prior != NULL) //upewnieine sie że pracujemy na pierwszym elemencie listy
            lista = lista->prior;

        printf("\nwpisz poszukiwaną frazę(w budowie):");
        char nazwa[MAXNAZWA];
        if ( scanf("%s", nazwa) != 1 )
        {
            error();
        }
        else
        {
            printf("po wyjściu z tej opcji wyszukane rekordy zostaną usunięte z tymczasowego bufora\n");
            char temp_nazwa[strlen(nazwa)+1];
            int koniec = NIE;
            while(koniec == NIE) //dla kazdego elementu z listy
            {
                int last_number = 0;
                if(strlen(nazwa)<=strlen(lista->budowa))
                {
                    int licznik_1=0;
                    for(licznik_1=0; licznik_1<(strlen(lista->budowa)-strlen(nazwa)+1); licznik_1++) //dla kadego mozliwego miejsca w nazwie marki szukaengo fragmentu
                    {
                        int t_licznik=0, licznik=0;
                        for(licznik=licznik_1; licznik<strlen(nazwa)+licznik_1; licznik++ ) //kopiowanie fragmentu do tempa
                        {
                            temp_nazwa[t_licznik] = lista->budowa[licznik];
                            t_licznik++;
                        }
                        temp_nazwa[strlen(nazwa)] = '\0';
                        //printf("temp nazwa to %s\n", temp_nazwa); fajne do debugowania lub patrzenia jak zarąbiscie dziala ;D

                        if(strcmp(temp_nazwa, nazwa) == 0)
                        {
                            if(last_number != lista->numer)
                            {
                                element *temp = NULL;
                                temp = (element*)malloc(sizeof(element));

                                temp->rodzaj = lista->rodzaj;
                                temp->rok_produkcji = lista->rok_produkcji;
                                temp->numer = lista->numer;
                                strncpy( temp->budowa, lista->budowa, MAXNAZWA-1);
                                strncpy( temp->marka, lista->marka, MAXNAZWA-1);
                                temp->next = NULL;
                                temp->prior = NULL;
                                szukaj_lista = push(szukaj_lista, temp);

                                last_number = lista->numer; //zapisuje w tym jaki numer poprzednio został wgrany
                                //printf("pasue\n"); fajne do debugowaina ;D
                            }
                        }

                    }
                }
                if(lista->next == NULL)
                    koniec = TAK;
                else
                    lista = lista->next;
            }
            wyswietl(szukaj_lista);

        }

    }
    return szukaj_lista;
}

element * szukaj_marka(element *lista, element *szukaj_lista)
{
    if(lista != NULL)
    {
        while(lista->prior != NULL)
            lista = lista->prior;

        printf("\nwpisz poszukiwaną frazę(w nazwie):");
        char nazwa[MAXNAZWA];
        if ( scanf("%s", nazwa) != 1 )
        {
            error();
        }
        else
        {
            printf("po wyjściu z tej opcji wyszukane rekordy zostaną usunięte z tymczasowego bufora\n");
            char temp_nazwa[strlen(nazwa)+1];
            int koniec = NIE;
            while(koniec == NIE) //dla kazdego elementu z listy
            {
                int last_number = 0;
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
                            if(last_number != lista->numer) //wyklucza ponowne dodanie tego samego rekordu
                            {
                                element *temp = NULL;
                                temp = (element*)malloc(sizeof(element));

                                temp->rodzaj = lista->rodzaj;
                                temp->rok_produkcji = lista->rok_produkcji;
                                temp->numer = lista->numer;
                                strncpy( temp->marka, lista->marka, MAXNAZWA-1);
                                strncpy( temp->budowa, lista->budowa, MAXNAZWA-1);
                                temp->next = NULL;
                                temp->prior = NULL;
                                szukaj_lista = push(szukaj_lista, temp);

                                last_number = lista->numer; //zapisuje w tym jaki numer poprzednio został wgrany

                                //printf("pasue\n"); fajne do debugowaina ;D
                            }

                        }

                    }
                }
                if(lista->next == NULL)
                    koniec = TAK;
                else
                    lista = lista->next;
            }
            wyswietl(szukaj_lista);

        }

    }
    return szukaj_lista;
}

element * szukaj_rocznik(element *lista, element *szukaj_lista)
{
    if(lista != NULL)
    {
        while(lista->prior != NULL)
            lista = lista->prior;

        printf("\nwpisz poszukiwany rocznik:");
        int rocznik = 0;
        if ( scanf("%d", &rocznik) != 1 )
        {
            error();
        }
        else
        {
            printf("po wyjściu z tej opcji wyszukane rekordy zostaną usunięte z tymczasowego bufora\n");
            int koniec = NIE;
            while(koniec == NIE) //dla kazdego elementu z listy
            {
                int last_number = 0;

                if(rocznik == lista->rok_produkcji)
                {
                    if(last_number != lista->numer) //wyklucza ponowne dodanie tego samego rekordu
                    {
                        element *temp = NULL;
                        temp = (element*)malloc(sizeof(element));

                        temp->rodzaj = lista->rodzaj;
                        temp->rok_produkcji = lista->rok_produkcji;
                        temp->numer = lista->numer;
                        strncpy( temp->marka, lista->marka, MAXNAZWA-1);
                        strncpy( temp->budowa, lista->budowa, MAXNAZWA-1);
                        temp->next = NULL;
                        temp->prior = NULL;
                        szukaj_lista = push(szukaj_lista, temp);

                        last_number = lista->numer; //zapisuje w tym jaki numer poprzednio został wgrany

                        //printf("pasue\n"); fajne do debugowaina ;D
                    }

                }
                if(lista->next == NULL)
                    koniec = TAK;
                else
                    lista = lista->next;
            }
            wyswietl(szukaj_lista);
        }

    }
    return szukaj_lista;
}

element * szukaj_rodzaj(element *lista, element *szukaj_lista)
{
    if(lista != NULL)
    {
        while(lista->prior != NULL)
            lista = lista->prior;

        printf("\nwpisz poszukiwany rodzaj, 1-elektryk, 2-akustyk, 3-bas:");
        int rodzaj = 0;
        if ( scanf("%d", &rodzaj) != 1 )
        {
            error();
        }
        else
        {
            printf("po wyjściu z tej opcji wyszukane rekordy zostaną usunięte z tymczasowego bufora\n");
            int koniec = NIE;
            while(koniec == NIE) //dla kazdego elementu z listy
            {
                int last_number = 0;

                if(rodzaj == lista->rodzaj)
                {
                    if(last_number != lista->numer) //wyklucza ponowne dodanie tego samego rekordu
                    {
                        element *temp = NULL;
                        temp = (element*)malloc(sizeof(element));

                        temp->rodzaj = lista->rodzaj;
                        temp->rok_produkcji = lista->rok_produkcji;
                        temp->numer = lista->numer;
                        strncpy( temp->marka, lista->marka, MAXNAZWA-1);
                        strncpy( temp->budowa, lista->budowa, MAXNAZWA-1);
                        temp->next = NULL;
                        temp->prior = NULL;
                        szukaj_lista = push(szukaj_lista, temp);

                        last_number = lista->numer; //zapisuje w tym jaki numer poprzednio został wgrany

                        //printf("pasue\n"); fajne do debugowaina ;D
                    }

                }
                if(lista->next == NULL)
                    koniec = TAK;
                else
                    lista = lista->next;
            }
            wyswietl(szukaj_lista);
        }

    }
    return szukaj_lista;
}

#endif // EDYCJA_H_INCLUDED
