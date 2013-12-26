#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define NIE 0
#define TAK 1

#include <stdlib.h>
#include <string.h>

#include "init.h"
#include "odczyt.h"



void menu(element *lista);
void podpis();
element * usun(element *);
void wyswietl(element *);
void zapisz1(element *lista);
void zapisz2(element * lista, int polecenie, char *);



void menu(element *lista)
{
    int czy_konczyc = NIE;
    while( czy_konczyc == NIE )
    {
        printf("\n-------------------\n"
               "dostępne funkcje:\n"
               "11 - Wczytaj listę gitar z pliku\n"
               "12 - Dodaj ręcznie gitarę\n"
               "13 - Wygeneruj losową listę gitar\n"
               "-------------------\n"
               "2 - Wyswietl bazę gitar\n"
               "-------------------\n"
               "31 - Sortuj po ...\n"
               "-------------------\n"
               "41 - Filtruj po ...\n"
               "-------------------\n"
               "5 - Zapisz\n"
               "6 - Wyjdź\n");
        int komenda = 0 ;
        if( scanf("%d", &komenda) != 1)
        {
            error();
        }
        else
        {
            switch (komenda)
            {
            case 11:
            {
                lista = wczytaj_z_pliku(lista);
                break;
            }
            case 12:
            {
                lista = dodaj(lista);
                break;
            }
            case 13:
            {
                lista = losuj(lista);
                break;
            }
            case 2:
            {
                wyswietl(lista);
                break;
            }
            case 5:
            {
                printf("zapis\n");
                zapisz1(lista);
                break;
            }
            case 6:
            {
                printf("kończę działanie programu\n");
                czy_konczyc = TAK;
                break;
            }
            default:
            {
                printf("nie ma takiej opcji\n");
            }
            }
        }
    }
}
void podpis()
{
    printf("\n--------------------\n"
           "JAKUB TRZYNA 205687\n"
           "programowanie w C\n"
           "--------------------\n");
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
void wyswietl(element *first)
{
    if(first==NULL)
    {
        printf("lista jest pusta\n");
    }
    else
    {
        while(first->prior != NULL)
            first = first->prior;


        printf("-------------------------\n"
               "Lp.\trocznik\tmarka\t\trodzaj\t\tkształt\n");
        do
        {
            printf("%d.\t%d\t%s\t\t", first->numer, first->rok_produkcji, first->marka);
            if(first->rodzaj == 1)  printf("elektryczna\t");
            else if(first->rodzaj == 2) printf("akustyczna\t");
            else if(first->rodzaj == 3) printf("klasyczna\t");
            printf("%s\n", first->budowa);
            first=first->next;
        }
        while(first!=NULL);
        printf("\n[enter] aby porwóić do widoku menu\n");
        getchar();
        getchar();
    }
}
void zapisz1(element *lista)
{
    int dzialaj = TAK;
    printf("podaj nazwę pod jaką zapisac tą listę:\n");
    char nazwa[MAXNAZWA];
    if ( scanf("%19s", nazwa) != 1 )
    {
        error();
        dzialaj = NIE;
    }
    else
    {
        FILE *pFile;

        if(dzialaj == TAK)
        {
            pFile = fopen( nazwa , "wat");

            if(pFile==NULL)
            {
                perror("blad otwarcia pliku");
            }
            else
            {
                printf("zaczynam zapis...\n");
                while(lista!=NULL)
                {
                    fprintf(pFile, "%s\n", lista->rodzaj);//ladnie zrobic

                    fflush(pFile);

                    lista=lista->next;
                }
                fclose(pFile);

            }
        }
    }
}


#endif // MENU_H_INCLUDED


