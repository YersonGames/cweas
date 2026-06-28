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

    //Boolean1
    bool _bool1 = true;
    printf("True: %i\n",_bool1);
    _bool1 = false;
    printf("False: %i",_bool1);
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