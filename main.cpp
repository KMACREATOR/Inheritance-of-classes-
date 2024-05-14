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
    Automobile vazik("���-31519", 120.0);
    Autobus pazik("���-3205", 90.0, 41);
    Automobile *aa;
    aa = &vazik;
    aa -> print();
//������������ �����������. ��������� ���� ��������
//������ Automobile, ��������� �� �������,
//������������ � ������� � ������������� virtual
//� ���������������� � ����������� ������ Autobus
    aa = &pazik;
    aa -> print();
//����������� �����������. ��������� ���� ������������
//������ Autobus, ��������� �� �������, ���������������� �
//������ Autobus
    Autobus *ab;
    ab = &pazik;
    ab -> print();
    system("pause");
    return 0;
}
