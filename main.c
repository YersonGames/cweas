#include <stdio.h>
#include <stdbool.h>

int main()
{
    short int _a = 200;

    printf("\n%zu",sizeof(_a));

    short int _percent1,_percent2;
    _percent1 = 60;
    _percent2 = 100;
    float _result = ( (float) _percent1 / _percent2)*100; //(float): convertir int a float, convierte solo el valor de la derecha
    printf("\nResult: %.1f\n",_result);

    short int _c = 5;
    printf("++ %i\n",_c++); //++var: suma antes; var++: suma despues

    //Boolean
    bool _bool1 = true;
    printf("True: %i\n",_bool1);
    _bool1 = false;
    printf("False: %i",_bool1);

    //If
    if (_bool1 == true)
    {
        printf("\nHola");
    }
    else
    {
        printf("\nHola2");
    }

    //Short If-Else
    (_bool1 ==  true) ? printf("\nHola") : printf("\nHola2"); //funciona como un if-else

    //Switch
    short int _switchNum = 2;
    switch (_switchNum)
    {
        case 1:
            printf("\nUno\n");
            break;
        case 2:
            printf("\nDos\n");
            break;
        default:
            printf("\nNada\n");
            break;
    }

    //While Loops
    int _whileNum = 0;
    while (_whileNum != 5)
    {
        printf("While%i ",_whileNum);
        _whileNum++;
    }
    printf("\n");

    //Do while
    //Se ejecuta el bloque Do al menos una vez antes de comprobar la condicion
    _whileNum = -1;
    do
    {
        printf("Do While%i ",_whileNum);
        _whileNum++;
    }
    while (_whileNum == 0);
    printf("\n");
    
    //For Loop
    for (short int _forNum = 0;_forNum<=10;_forNum++)
    {
        printf("For%hd",_forNum);
    }
    printf("\n");

    //continue
    for (int _continueNum = 0; _continueNum < 10; _continueNum++) 
    {
        if (_continueNum == 4) {
            continue;
        }
        printf("%i", _continueNum);
    }
    printf("\n");

    //Array
    int _arrayNums[] = {10,20,30,40};

    printf("%i",_arrayNums[1]);
    return 0;
}

/*
%d p %i: int
%f: float
%.1f: float, 1 decimal
%lf: double
%c: char
%s: string
%zu: size_t (sizeof...)
%hd: short int
%u: unsigned int
%ld: long int
%lld: long long int
%lu: unsigfned long int
%llu: unsigned long long int
%Lf: long double
*/