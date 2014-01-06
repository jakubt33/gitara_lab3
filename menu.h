#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define NIE 0
#define TAK 1

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "init.h"

void menu(element *lista);
void podpis();
void wyswietl(element *);

#include "odczyt.h"
#include "edycja.h"


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
               "14 - Usuń wybraną pozycję\n"
               "15 - Edytuj wybraną pozycję\n"
               "-------------------\n"
               "2 - Wyswietl bazę gitar\n"
               "-------------------\n"
               "31 - Sortuj po ...\n"
               "-------------------\n"
               "41 - Wyszukaj w nazwie marki\n"
               "42 - Wyszukaj w rodzaju budowy\n"
               "43 - Wyszukaj wskazany rocznik produkcji\n"
               "44 - Wyszukaj wskazany rodzaj\n"
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
                numeruj(lista);
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
            case 14:
            {
                lista = usun_wybrany(lista);
                break;
            }
            case 15:
            {
                lista = edytuj(lista);
                break;
            }
            case 2:
            {
                wyswietl(lista);
                break;
            }
            case 31:
            {
                sortuj(lista);
                break;
            }
            case 41:
            {
                element *szukaj_lista=NULL;
                szukaj_lista = szukaj_marka(lista, szukaj_lista);
                szukaj_lista = usun(szukaj_lista);
                break;
            }
            case 42:
            {
                element *szukaj_lista=NULL;
                szukaj_lista = szukaj_budowa(lista, szukaj_lista);
                szukaj_lista = usun(szukaj_lista);
                break;
            }
            case 43:
            {
                element *szukaj_lista=NULL;
                szukaj_lista = szukaj_rocznik(lista, szukaj_lista);
                szukaj_lista = usun(szukaj_lista);
                break;
            }
            case 44:
            {
                element *szukaj_lista=NULL;
                szukaj_lista = szukaj_rodzaj(lista, szukaj_lista);
                szukaj_lista = usun(szukaj_lista);
                break;
            }
            case 5:
            {
                printf("zapis\n");
                zapisz_do_pliku(lista);
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


        printf("--------------------------------------------------------------------\n"
               "Lp.\trok\t\tmarka\trodzaj\t\tkształt\n");
        do
        {
            printf("%4d.\t%d %16s\t", first->numer, first->rok_produkcji, first->marka);
            if(first->rodzaj == 1)       printf("elektryczna\t");
            else if(first->rodzaj == 2)  printf("akustyczna \t");
            else if(first->rodzaj == 3)  printf("basowa     \t");
            printf("%s\n", first->budowa);
            first=first->next;
        }
        while(first!=NULL);
        printf("\n[enter] aby porwóić do widoku menu\n");
        getchar();
        getchar();
    }
}


#endif // MENU_H_INCLUDED


