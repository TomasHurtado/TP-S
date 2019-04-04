#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

float main()
{
    float numuno;
    float numdos;

    utn_pedir_primerNumero(&numuno,"Ingrese numero uno");
    utn_pedir_segundoNumero(&numdos,"ingrese numero dos");

    return 0;
}

