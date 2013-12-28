#ifndef EDYCJA_H_INCLUDED
#define EDYCJA_H_INCLUDED

void sortuj(element *);
void sortuj_rocznik(element*);
void sortuj_rodzaj(element*);
void sortuj_marka(element*);
void sortuj_budowa(element *lista);

void sortuj(element *lista)
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
