#include <iostream>
#include <string> //si bien <iostream> puede incluirla, no se garantiza, es necesario

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
    std::cout<<_name[0]<<" o "<<_name.at(0); //acceder a un caracter
    return 0;
}

/*
bool: 1byte
char: 1byte
int: 2-4bytes
float: 4bytes
double: 8bytes
*/
