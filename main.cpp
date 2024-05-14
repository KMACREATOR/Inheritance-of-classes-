#include <iostream>
#include <string>

using namespace std;

class Automobile{
protected:
    string name;
    float velocity;
public:
    Automobile(string name, float velocity){
    this->name = name;
    this->velocity = velocity;
    }
    virtual void print(){
        cout << "\nName: " << name << "\nMaximum velocity: " << velocity;
    }
    };


class Autobus : public Automobile{
    int passengers;
public:
    Autobus(string name, float velocity, int passengers):
        Automobile(name, velocity){
            this->passengers = passengers;
        }
        void print(){
            Automobile::print();
            cout << "\npassengers = " << passengers << endl;    ;
        }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    Automobile vazik("УАЗ-31519", 120.0);
    Autobus pazik("ПАЗ-3205", 90.0, 41);
    Automobile *aa;
    aa = &vazik;
    aa -> print();
//динамический полиморфизм. указатель типа базового
//класса Automobile, ссылается на функцию,
//определенную в базовом с модификатором virtual
//и переопределенную в производном классе Autobus
    aa = &pazik;
    aa -> print();
//статический полиморфизм. указатель типа прозиводного
//класса Autobus, ссылается на функцию, переопределенную в
//классе Autobus
    Autobus *ab;
    ab = &pazik;
    ab -> print();
    system("pause");
    return 0;
}
