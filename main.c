#include <stdio.h>
#include "menu.h"

int main()
{
    srand(time(NULL));
    element *lista = NULL;

    menu(lista);

    lista = usun(lista);
    podpis();
    return 0;
}
