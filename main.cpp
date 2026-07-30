#include <iostream>
#include <string> //si bien <iostream> puede incluirla, no se garantiza, es necesario
#include <math.h>

struct _struct1
{
    int num;
    std::string name;
};

class _class1
{
    public:
        int num;
        std::string name;
        void printName()
        {
            std::cout<<name<<std::endl;
        }
        void printNum();
};

class _class2
{
    private:
        int x;
        int y;

    public:
        _class2(int gx,int gy)
        {
            std::cout<<"Constructor"<<std::endl;
            x = gx;
            y = gy;
        }

        friend void displayXY(_class2 _cls2)
        {
            std::cout<<_cls2.x<<_cls2.y<<std::endl;
        }
};

class User
{
    protected:
        std::string name;
    public:
        void getName()
        {
            std::cout<<name<<std::endl;
        }
};

template <typename T1>
class Employee: public User//,class2,class3... herencia multiple
{
    private:
        T1 salary;
    public:
        Employee(std::string n, T1 s)
        {
            name = n;
            salary = s;
        }

        void getSalary()
        {
            std::cout<<salary<<std::endl;
        }
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
    //array: new int[]  delete[] var
    *_ptr1 = 50;
    std::cout<<*_ptr1<<std::endl;
    delete _ptr1;

    //lambda
    auto _lambda = [x](std::string name)
    {
        std::cout<<"Lambda: "<<name<<x<<std::endl;
    };

    _lambda(_name);

    //objetos
    _class1 _obj1;

    _obj1.num = 10;
    _obj1.name = "Jose";

    _obj1.printName();
    _obj1.printNum();

    _class2 _obj2(10,20);
    displayXY(_obj2); //friend: funcion que no es parte de la clase pero puede acceder a los datos privados de esta

    Employee<int> e1("Scott Int",1000);

    e1.getName();
    e1.getSalary();

    Employee<float> e2("Scott Float",1000.1);

    e2.getName();
    e2.getSalary();

    return 0;
}

/*
bool: 1byte
char: 1byte
int: 2-4bytes
float: 4bytes
double: 8bytes
*/

void _class1::printNum()
{
    std::cout<<num<<std::endl;
}