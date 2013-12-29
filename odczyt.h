#ifndef ODCZYT_H_INCLUDED
#define ODCZYT_H_INCLUDED

#define STOP -1
#define WORK 1

element *dodaj(element *);
void zapisz_do_pliku(element* );
void error();
void nazwa_marki(element *, int *);
void numeruj(element *);
element *push(element *, element *);
void zwolnij_tablice(element *);
element *losuj(element *);
element *usun_wybrany(element *);
element *usun(element *);
element *wczytaj_z_pliku(element *);

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
            temp->next = NULL;
            int zmienna = 0;

            //losowanie marki
            zmienna = rand()%10;
            char marka[][MAXNAZWA] = { "Fender", "Vintage", "Cort", "Gibson", "ESP", "Ibanez", "Yamaha", "Epiphone", "Jackson", "Fernandes" };
            strncpy( temp->marka, marka[zmienna], MAXNAZWA-1);

            //losowanie rodzaju
            zmienna = rand()%3+1;
            temp->rodzaj = zmienna;

            //losowanie roku produkcji
            zmienna = rand()%50+1964;
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

            //dodanie do listy
            lista = push(lista, temp);

            numeruj(lista);
            ilosc--;
        }
    }
    return lista;
}

element *usun_wybrany(element *lista)
{
    if(lista !=NULL)
    {
        printf("\npodaj numer gitary którą chcesz usunąć:  ");
    int do_usuniecia=0;
    if ( scanf("%d", &do_usuniecia) != 1 )
    {
        error();
    }
    else
    {
        //printf("numer na wejciu to %d\n", lista->numer);
        if(lista->numer>do_usuniecia)
            while(do_usuniecia != lista->numer && lista->prior != NULL)
                lista = lista->prior;

        else if(lista->numer<do_usuniecia)
            while(do_usuniecia != lista->numer && lista->next != NULL)
                lista = lista->next;

        if(lista->numer == do_usuniecia)
        {
            if(lista->prior != NULL && lista->next != NULL) //obejmuje wszytkie środkowyme  do poptawy
            {
                element *temp = lista->prior;

                lista = lista->next;

                free(lista->prior);

                lista->prior = temp; //o jeden do tylu
                temp->next = lista;


            }
            else if(lista->prior == NULL && lista->next != NULL) //pierwsza
            {
                lista = lista->next; //do przodu o jeden
                lista->prior->next = NULL; //pierwszy juz nie wskazuje na drugi
                free(lista->prior); //usuniecie pierwszego
                lista->prior = NULL; //nowy pierwszy wskazuje na null w prior

            }
            else if(lista->prior != NULL && lista->next == NULL) //ostatnia
            {
                lista = lista->prior; //cofam ie ojednen
                lista->next->prior = NULL; //pozbycie sie swiadkow, alienacja ostatniego elementu
                free(lista->next);
                lista->next = NULL;
            }
            else if(lista->prior == NULL && lista->next == NULL) //w bazie tylko jeden rekord
            {
                lista = usun(lista);
            }
            numeruj(lista);

        }
        else
            printf("brak gitary o wkazanym numerze\n");

        if(lista!=NULL)
        {
            while(lista->next != NULL)
                lista = lista->next;
        }
    }
    }
    return lista; //zwraca wkaźnik do otatniego elementu
}

element *dodaj(element *lista)
{
    int dzialaj = NIE;

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
                    lista = push(lista, temp);
                    numeruj(lista);
                    dzialaj = TAK;
                }
            }
        }
    }
    if (dzialaj == NIE)
    {
        free(temp);
    }
    return lista;
}

void numeruj(element *lista)
{
    int licznik=0;
    if(lista!=NULL)
    {
        while(lista->prior != NULL) //cofniecie sie na poczatek lissty
            lista = lista->prior;
        do
        {
            licznik++;
            lista->numer=licznik;
            lista=lista->next;
        }
        while(lista!=NULL);
    }
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
        temp->next->prior = temp;
        temp = temp->next;
    }
    newone->prior = temp;
    temp->next=newone;

    return first; //zwraca wskaźnik do pierwszewgo elementu!!
}

element * usun(element *first)
{
    if(first==NULL)
    {
        printf("\nlista juz jest pusta\n");
        return NULL;
    }

    usun(first->next);
    free(first);
    return NULL;
}

void zapisz_do_pliku(element *lista)
{
    if(lista != NULL)
    {
        char nazwa[MAXNAZWA];
        printf("\npodaj nazwę pliku:  ");
        if ( scanf("%s", nazwa) != 1 )
        {
            error();
        }
        else
        {
            //sprawdzenie czy .dat dodac
            FILE *pFile;
            pFile=fopen(nazwa, "wb");
            if(pFile == NULL)
            {
                perror("\nbłąd otwarcia pliku\n");
            }
            else
            {
                while(lista != NULL)
                {
                    fwrite(&lista->rok_produkcji, sizeof(int), 1 , pFile );
                    fwrite(&lista->rodzaj, sizeof(int), 1 , pFile );
                    fwrite(lista->marka, MAXNAZWA*sizeof(char), 1,  pFile);
                    fwrite(lista->budowa, MAXNAZWA*sizeof(char), 1,  pFile);
                    fflush(pFile);
                    lista = lista->next;
                }
                printf("poprawnie zapisano listę\n");
                fclose(pFile);
            }
        }
    }
}
element * wczytaj_z_pliku(element *lista)
{
    char nazwa[MAXNAZWA];
    printf("\npodaj nazwę pliku:  ");
    if ( scanf("%s", nazwa) != 1 )
    {
        error();
    }
    else
    {
        FILE *pFile;
        pFile=fopen(nazwa, "rb");
        if(pFile == NULL)
        {
            perror("\nbłąd otwarcia pliku\n");
        }
        else
        {
            while(feof(pFile) == 0)
            {
                element *temp = NULL;
                temp=(element*)malloc(sizeof(element));
                int read_counter=0;
                read_counter += fread(&temp->rok_produkcji, sizeof(int), 1, pFile);
                if(temp->rok_produkcji == 0) free(temp); //znak ze koniec pliku
                else
                {
                    read_counter += fread(&temp->rodzaj, sizeof(int), 1, pFile);
                    read_counter += fread(temp->marka, MAXNAZWA*sizeof(char), 1, pFile);
                    read_counter += fread(temp->budowa, MAXNAZWA*sizeof(char), 1, pFile);
                    if (read_counter == 4 )
                        {
                            lista = push(lista, temp);
                            numeruj(lista);
                        }
                }
            }
            printf("poprawnie wczytano listę\n");
            fclose(pFile);
        }

    }
    return lista;
}

#endif // ODCZYT_H_INCLUDED
