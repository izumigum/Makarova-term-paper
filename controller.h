#include <iostream>
#include "house.h"
using namespace std;

class controller {
private:
    funeral_home house;
public:
    controller() {
    }
    void execute() {
        int run = 1;
        while (run) {
            menu();
            int var = 0;
            while (var < 1 || var > 7) {
                cout << "������� ����� �������: ";
                cin >> var;
            }
            if (var == 1) {
                house.get_info();
            }
            if (var == 2) {
                house.new_zakaz();
                cout << "����� ��������." << endl;;
            }
            if (var == 3) {
                int n;
                house.get_info();
                cout << "������� ����� ������ ��� ��������" << endl; 
                cin >> n;
                house.delete_zakaz(n);
            }
            if (var == 4) {
                house.save_file();
                cout << "������ ��������� � ����." << endl;
            }
            if (var == 5) {
                house.load_file();
                cout << "������ �� ����� ���������." << endl;
            }
            if (var == 6) {
                cout << "�������� ����� ������, ��� ��������������" << endl;
                int k= 0;
                while (k < 1 || k>house.getN()) {
                    house.get_info();
                    cin >> k;

                }
                house.change_zakaz_info(k);
                cout << "���������� ������ ��������.";
            }
            if (var == 7) {
                run = 0;
            }
        }
    }

    void menu() {
        cout << "Commands: " << endl;
        cout << "1. ������� ���������� ���� �������." << endl;
        cout << "2. ������� ����� �����." << endl;
        cout << "3. ������� �����." << endl;
        cout << "4. ��������� ������ � ����." << endl;
        cout << "5. ��������� ������ �� �����." << endl;
        cout << "6. �������� ���������� ������." << endl;
        cout << "7. ����� �� ���������." << endl;
    }
};