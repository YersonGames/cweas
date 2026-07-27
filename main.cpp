#include <iostream>
#include <string> //si bien <iostream> puede incluirla, no se garantiza, es necesario
#include <math.h>

struct _struct1
{
    int num;
    std::string name;
};

int main()
{
    const bool _bool1 = true;
    std::cout<<_bool1;
    

    int x;
    auto y = 1;
    //auto: detecta automaticamente el tipo de variable

    std::cout<<"\nX: ";
    std::cin>>x;
    std::cout<<"X: "<<x<<std::endl;

    std::cin.ignore(); //limpia el salto de linea pendiente de std::cin, es util si se usa seguido std::getline()

    std::string _name;
    std::string _lastName;
    std::cout<<"Name: ";
    std::getline(std::cin,_name);
    std::cout<<"Last Name: ";
    std::getline(std::cin,_lastName);
    std::cout<<"Full Name: "<<_name.append(_lastName)<<std::endl;
    std::cout<<_name.length()<<std::endl; 
    std::cout<<_name[0]<<" o "<<_name.at(0)<<std::endl; //acceder a un caracter

    std::cout<<std::max(5,10)<<std::endl;
    std::cout<<std::min(5,10)<<std::endl;
    std::cout<<std::sqrt(144)<<std::endl;
    std::cout<<std::round(2.6)<<std::endl;
    std::cout<<std::log(2)<<std::endl; //logaritmo natural: ln

    if (_name.length()<10)
    {
        std::cout<<"Nombre muy corto";
    }
    std::cout<<std::endl;
    for (char _c:_name)
    {
        std::cout<<_c<<" ";
    }
    std::cout<<std::endl;

    int _arrayNum[3] = {10,20,30};

    for (int _i:_arrayNum)
    {
        std::cout<<_i<<" ";
    }
    std::cout<<std::endl;

    _struct1 _s1;

    _s1.num = x;
    _s1.name = _name;

    std::cout<<"S1.name: "<<_s1.name<<std::endl;
    std::cout<<"S1.num: "<<_s1.num<<std::endl;
    std::cout<<&x<<std::endl;

    int* xPtr = &x;
    std::cout<<xPtr<<std::endl;

    int* _ptr1 = new int; //new: crea un espacio de memoria, arrays dinamicas, funciona como malloc()
    *_ptr1 = 50;
    std::cout<<*_ptr1<<std::endl;
    delete _ptr1;


    return 0;
}

/*
bool: 1byte
char: 1byte
int: 2-4bytes
float: 4bytes
double: 8bytes
*/
