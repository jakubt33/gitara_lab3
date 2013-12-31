#ifndef ODCZYT_H_INCLUDED
#define ODCZYT_H_INCLUDED


element *dodaj(element *);
element *edytuj(element*);
void error();
element *losuj(element *);
void numeruj(element *);
element *push(element *, element *);
element *usun(element *);
element *usun_wybrany(element *);
element *wczytaj_z_pliku(element *);
void zapisz_do_pliku(element* );

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
        printf("\nrodzaj gitary: 1-elektryczna, 2-akustyczna, 3-basowa:  ");
        if ( scanf("%d", &temp->rodzaj) != 1 )
        {
            error();
        }
        else if ( temp->rodzaj == 1  || temp->rodzaj == 2  ||temp->rodzaj == 3  )
        {
            printf("\npodaj rok produkcji:  ");
            if ( scanf("%d", &temp->rok_produkcji) != 1 )
            {
                error();
            }
            else if (temp->rok_produkcji > 1800)
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
            else printf("złe dane\n");
        }
        else printf("złe dane\n");
    }
    if (dzialaj == NIE)
    {
        free(temp);
    }
    return lista;
}

element *edytuj(element* lista)
{
    if(lista !=NULL)
    {
        printf("\npodaj numer gitary którą chcesz edytować:  ");
        int do_edycji=0;
        if ( scanf("%d", &do_edycji) != 1 )
        {
            error();
        }
        else
        {
            if(lista->numer>do_edycji)
                while(do_edycji != lista->numer && lista->prior != NULL)
                    lista = lista->prior;

            else if(lista->numer<do_edycji)
                while(do_edycji != lista->numer && lista->next != NULL)
                    lista = lista->next;

            if(lista->numer == do_edycji)
            {
                int temp_rok_produkcji=0;
                int temp_rodzaj=0; //1-elektryk, 2 akustyk, 3- bas
                char temp_marka[MAXNAZWA];
                char temp_budowa[MAXNAZWA];

                printf("\npodaj markę gitary do załadowania do bazy (%s):  ", lista->marka);
                if ( scanf("%19s", temp_marka) != 1 )
                {
                    error();
                }
                else
                {
                    printf("\nrodzaj gitary: 1-elektryczna, 2-akustyczna, 3-basowa(%d):  ", lista->rodzaj);
                    if ( scanf("%d", &temp_rodzaj) != 1 )
                    {
                        error();
                    }
                    else if ( temp_rodzaj == 1  || temp_rodzaj == 2  || temp_rodzaj == 3 )
                    {
                        printf("\npodaj rok produkcji(%d):  ", lista->rok_produkcji);
                        if ( scanf("%d", &temp_rok_produkcji) != 1 )
                        {
                            error();
                        }
                        else if(temp_rok_produkcji > 1800)
                        {
                            printf("\npodaj budowę gitary(%s):  ", lista->budowa);
                            if ( scanf("%19s", temp_budowa) != 1 )
                            {
                                error();
                            }
                            else
                            {
                                printf("\npoprawdnie edytowano gitarę\n");

                                strcpy ( lista->marka, temp_marka);
                                strcpy ( lista->budowa, temp_budowa);
                                lista->rodzaj = temp_rodzaj;
                                lista->rok_produkcji = temp_rok_produkcji;
                            }
                        }
                        else printf("złe dane\n");
                    }
                    else printf("złe dane\n");
                }
            }
            else
                printf("brak gitary o wkazanym numerze\n");

            while(lista->next != NULL)
                lista = lista->next;

        }
    }
    else
    {
        printf("lista jest pusta\n");
    }
    return lista; //zwraca wkaźnik do otatniego elementu
}

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

    return first; //zwraca wskaźnik do ostatniego elementu!!
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
            if(lista->numer>do_usuniecia)
                while(do_usuniecia != lista->numer && lista->prior != NULL)
                    lista = lista->prior;

            else if(lista->numer<do_usuniecia)
                while(do_usuniecia != lista->numer && lista->next != NULL)
                    lista = lista->next;

            if(lista->numer == do_usuniecia)
            {
                printf("czy napewno chcesz usunąć wybraną pozycję? 1 - Tak, 2 - Nie\n");
                printf("--------------------------------------------------------------------\n"
                       "Lp.\trok\t\tmarka\trodzaj\t\tkształt\n");
                printf("%4d.\t%d %16s\t", lista->numer, lista->rok_produkcji, lista->marka);
                if(lista->rodzaj == 1)       printf("elektryczna\t");
                else if(lista->rodzaj == 2)  printf("akustyczna \t");
                else if(lista->rodzaj == 3)  printf("basowa     \t");
                printf("%s\n", lista->budowa);

                int tak_nie = 0;
                if ( scanf("%d", &tak_nie) != 1 )
                {
                    error();
                }
                else if(tak_nie == 1)
                {
                    if(lista->prior != NULL && lista->next != NULL) //obejmuje wszytkie środkowyme
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
                else printf("powrót do menu głównego\n");
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

    else printf("lista jest już pusta\n");

    return lista; //zwraca wkaźnik do otatniego elementu
}

element * wczytaj_z_pliku(element *lista)
{
    char nazwa[MAXNAZWA];
    printf("\npodaj nazwę pliku(bez rozszerzenia):  ");
    if ( scanf("%16s", nazwa) != 1 )
    {
        error();
    }
    else
    {
        FILE *pFile;
        strcat(nazwa, ".jt");
        pFile=fopen(nazwa, "rb");
        if(pFile == NULL)
        {
            perror("błąd otwarcia pliku\n");
        }
        else
        {
            element *temp_lista = NULL;

            int czy_dzialac = TAK;
            while(feof(pFile) == 0 && czy_dzialac == TAK)
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
                        temp->prior = NULL;
                        temp->next = NULL;
                        temp_lista = push(temp_lista, temp);
                    }
                    else
                    {
                        printf("problem z wczytaniem bazy\n");
                        czy_dzialac = NIE;
                    }
                }
            }
            fclose(pFile);

            if(czy_dzialac == TAK)
            {
                numeruj(temp_lista);
                printf("poprawnie wczytano listę\n");
                wyswietl(temp_lista);

                int wybor = 0;
                printf("czy dodać wszytkie do listy czy tylko wybrane? 1-Wszystkie, 2-Wybrane\n");

                if( scanf("%d", &wybor) != 1)
                {
                    error();
                }
                else
                {
                    if(wybor == 1)
                    {
                        while(temp_lista != NULL)
                        {
                            element *t_element = NULL;
                            t_element = (element*)malloc(sizeof(element));

                            //kopiowanie danych
                            t_element->rodzaj = temp_lista->rodzaj;
                            t_element->numer = temp_lista->numer;
                            t_element->rok_produkcji = temp_lista->rok_produkcji;
                            strncpy( t_element->budowa, temp_lista->budowa, MAXNAZWA-1);
                            strncpy( t_element->marka, temp_lista->marka, MAXNAZWA-1);
                            t_element->next = NULL;
                            t_element->prior = NULL;

                            lista = push(lista, t_element);

                            temp_lista = temp_lista->next;
                        }
                    }
                    else if(wybor == 2)
                    {
                        int koniec = NIE;
                        while(koniec == NIE) //tu sas dodawane kolejne giatry
                        {
                            printf("podaj numer gitary którą chcesz dodać ('0'-zakończ dodawanie,'-1'-wyswietl możliwości): ");
                            int wybor2=0;
                            if( scanf("%d", &wybor2) != 1)
                            {
                                error();
                            }
                            else
                            {
                                if(wybor2 == -1)
                                {
                                    wyswietl(temp_lista);
                                }
                                else if(wybor2 == 0)
                                {
                                    koniec = TAK;
                                }
                                else
                                {
                                    while(temp_lista->numer != wybor2 || temp_lista->next == NULL)
                                        temp_lista = temp_lista->next;

                                    element *t_element = NULL;
                                    t_element = (element*)malloc(sizeof(element));

                                    t_element->rodzaj = temp_lista->rodzaj;
                                    t_element->numer = temp_lista->numer;
                                    t_element->rok_produkcji = temp_lista->rok_produkcji;
                                    strncpy( t_element->budowa, temp_lista->budowa, MAXNAZWA-1);
                                    strncpy( t_element->marka, temp_lista->marka, MAXNAZWA-1);
                                    t_element->next = NULL;
                                    t_element->prior = NULL;

                                    wyswietl(t_element);

                                    lista = push(lista, t_element);

                                    while(temp_lista->prior != NULL)
                                        temp_lista=temp_lista->prior;//cofniecie sie na poczatek
                                }
                            }
                        }
                    }
                    else printf("powrót do menu\n");
                }
            }
            temp_lista = usun(temp_lista);
        }
    }
    return lista;
}
void zapisz_do_pliku(element *lista)
{
    if(lista != NULL)
    {
        char nazwa[MAXNAZWA];
        printf("\npodaj nazwę pliku(bez rozszerzenia):  ");
        if ( scanf("%16s", nazwa) != 1 )
        {
            error();
        }
        else
        {
            strcat(nazwa, ".jt");
            FILE *pFile;
            pFile=fopen(nazwa, "wb");
            if(pFile == NULL)
            {
                perror("\nbłąd otwarcia pliku\n");
            }
            else
            {
                while(lista->prior != NULL)
                    lista = lista->prior; //cofanie na sam początek w razie co
                while(lista != NULL)
                {
                    fwrite(&lista->rok_produkcji, sizeof(int), 1 , pFile );
                    fwrite(&lista->rodzaj, sizeof(int), 1 , pFile );
                    fwrite(lista->marka, MAXNAZWA*sizeof(char), 1,  pFile);
                    fwrite(lista->budowa, MAXNAZWA*sizeof(char), 1,  pFile);
                    lista = lista->next;
                }
                printf("poprawnie zapisano listę\n");

                fclose(pFile);
            }
        }
    }
    else printf("lista jest pusta\n");
}

#endif // ODCZYT_H_INCLUDED




