#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

inline int sum(int a,int b);

void message1();
void message2();
void message3();

void ln();

void hola();

void llamar(void (*llamado)());

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
    short int _arrayNums[4] = {10,20,30,40};
    //opcional: [4]: limite de 4
    _arrayNums[1] = 55;

    printf("Array: %i",_arrayNums[3]);
    printf("\ntamano array (bytes): %zu",sizeof(_arrayNums));
    printf("\ntamano (bytes): %zu",sizeof(_arrayNums[0]));
    //devuelve 16: int=4; array=4
    //devuelve 8: short int=2; array=4

    short int _array2d[2][4] = { {10,20,30,40},{1,2,3,4} };
    //[2]: Filas, [4]: Columnas = 1:{1,2,3,4},2:{1,2,3,4}

    printf("\nArray 2D: %i",_array2d[0][3]);

    short int _array3d[2][2][4] =
    {
        {
            {1,2,3},
            {4,5,6}
        },
        {
            {7,8,9},
            {10,11,12}
        }
    };

    //[2]: Capas, [2]: Filas, [3]: Columnas
    printf("\nArray 3D: %i",_array3d[0][1][2]);
    //para crear un string se tiene que declarar una variable tipo "char" y hacerla array[]

    printf("\n");

    char _string[] = "Holaaaa a todossss \"holis\"";
    //para crear un string se tiene que declarar una variable tipo "char" y hacerla array[]
    //se usa comillas dobles
    char _string2[] = {'H','o','l','i','\0'};
    // '/0':indica el final del string

    _string[0] = 'J';
    //se puede modificar los caracteres, se usa comillas simples

    printf("String: %s",_string);
    printf("\nString[0]: %c",_string[0]);
    //como es un array se puede tomar datos tambien con un index

    printf("\n%s",_string2);

    printf("\n%zu",strlen(_string));
    //string.h: strlen: largo string

    strcat(_string,_string2);
    //el resultado se almacena en la primera variable

    printf("\n%s",_string); 
    
    int _scanNum;
    char _scanChar;

    printf("\nEscribe un numero y letra: ");
    //scanf("%i %c",&_scanNum,&_scanChar);
    printf("Numero: %i",_scanNum);
    printf("\nLetra: %c",_scanChar);

    char _name[30];
    //es importante declarar el tamano

    printf("\n\nEscribe nombre: ");
    fgets(_name,sizeof(_name),stdin);
    printf("Hola %s",_name);

    int _ptrNum = 5;
    int *_ptr = &_ptrNum;

    printf("\n%p %i",_ptr,*_ptr);

    int _ptrArray[] = {10,20,30,40,50};
    _ptr = _ptrArray;

    *_ptr = 30;
    printf("\n%i",_ptrArray[0]);
    printf("\n%i %i",*_ptr,*(_ptr+1));

    printf("\nFuncion suma: %i",sum(10,15));


    void (*_funcArray[3])() = {message1,message2,message3};

    for (int i = 0;i<3;i++)
    {
        ln();
        _funcArray[i]();
    }

    ln();
    llamar(hola);

    return 0;
}

int sum(int a,int b)
{
    int result = a+b;
    return result;
}

void message1()
{
    printf("Mensaje 1");
}

void message2()
{
    printf("Mensaje 2");
}

void message3()
{
    printf("Mensaje 3");
}

void ln()
{
    printf("\n");
}

void hola()
{
    printf("Holas");
}

void llamar(void (*llamado)())
{
    ln();
    printf("Antes Holas");
    ln();
    llamado();
    ln();
    printf("Despues Holas");
}

/*
%d o %i: int
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

%p: puntero
*/