#ifndef EDYCJA_H_INCLUDED
#define EDYCJA_H_INCLUDED

void sortuj(element *);
void sortuj_rocznik(element*);

void sortuj(element *lista)
{
    printf("\npo jakim elemencie posortować? 1-rocznik, 2-typ, 3-marka, 4-budowa, 5-numer:  ");
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
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        }
    }
}
void sortuj_rocznik(element *lista)
{
    int czy_posortowane = NIE;
    while(lista->prior != NULL)
        lista = lista->prior; //cofniecie sie na począstek listy

    while(czy_posortowane == NIE)
    {
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

        while(lista->prior != NULL)
            lista = lista->prior; //cofniecie sie na począstek listy

        if(licznik == 0)
            czy_posortowane = TAK;
    }
}

#endif // EDYCJA_H_INCLUDED
