#include <iostream>
#include <string>
#include <stdlib.h>
#include "client.h"
#include <time.h>
using namespace std;

class zakaz {
protected:
    client cl;
    int heightB, heightA, type;
    string date, grob;
public:
    client getClient() {
        return cl;
    }
    int getType() {
        return type;
    }
    string getDate() {
        return date;
    }
    string getGrob() {
        return grob;
    }
    int getHB() {
        return heightB;
    }
    int getHA() {
        return heightA;
    }
    virtual string getUrna() = 0;
    virtual void get_info() = 0;
    virtual void change_info() = 0;
    virtual void create_info() = 0;
    virtual int getNBus() = 0;
    virtual bool getV() = 0;
    virtual bool getS() = 0;
    virtual bool getA() = 0;
    virtual int getSize() = 0;
};

class Pogrebenie :public zakaz {
private:
    int bus_n, sizeclothes;

    string vid_groba[4] = {
        "�������.",
        "����������.",
        "������ ������.",
        "�������������."
    };
    string desc[4] = {
        "������������� �� ���������� �������, ������������, � ������� ��������.",
        "�������� ����� � �������� ��������, �� ������� ������� �� �������� �������.",
        "����� �� ���������� �����, �������������� �����. ������ �������.",
        "������������� ����� � ��������� �������."
    };

    bool venok = false, stone = false, relig_attr = false;
public:
    Pogrebenie() {
        this->type = 0;
    }
    Pogrebenie(string name, string surname, string number, string date, int n, int heightB, int heightA, string grob, bool venok, bool stone, bool relig_attr, int sizeclothes) {
        this->cl = *(new client(name, surname, number));
        this->date = date;
        this->bus_n = n;
        this->heightB = heightB;
        this->heightA = heightA;
        this->grob = grob;
        this->venok = venok;
        this->stone = stone;
        this->relig_attr = relig_attr;
        this->sizeclothes = sizeclothes;
    }
    void create_info() {
        string name, surname, number;

        cout << "������� ���� ��� � �������: ";
        cin >> name >> surname;

        cout << "������� ����� �������� ��� �����: "; cin >> number;
        cl = client(name, surname, number);
        cout << "������� ���� ���������� ���������� ���������: ";
        cin >> date;

        cout << "������� ���-�� ���� � ��������, ������� �������� ������ �� ����� ����������: ";
        cin >> bus_n;

        cout << "������� ���� ��������, �� � ����� ������: ";
        cin >> heightB >> heightA;

        cout << "������� ��� �����, ������� �� ������������� ������� �� ���������:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "[" << i + 1 << "] " << vid_groba[i] << " " << desc[i] << endl;
        }
        int k = 0;
        while (k < 1 || k>4) {
            cin >> k;
        }
        grob = vid_groba[k - 1];
        string select = "";
        while (select != "Y" && select != "N" && select != "y" && select != "n") {
            cout << "����� �� �����? [Y/N]" << endl;
            cin >> select;
        }
        if (select == "Y" or select == "y") venok = true;

        select = "";
        while (select != "Y" && select != "N" && select != "y" && select != "n") {
            cout << "����� �� ������������ ������? ���� ���, ������ ����� ����� ������ �����. [Y/N]" << endl;
            cin >> select;
        }
        if (select == "Y" or select == "y") stone = true;

        select = "";
        while (select != "Y" && select != "N" && select != "y" && select != "n") {
            cout << "����� �� ����������� ��������? [Y/N]" << endl;
            cin >> select;
        }
        if (select == "Y") relig_attr = true;

        cout << "������� ������ ������ ���������: ";
        cin >> sizeclothes;
    }

    client getClient() {
        return cl;
    }

    string getClientInfo() {
        cl.print();
    }
    int getNBus() {
        return bus_n;
    }
    bool getV() {
        return venok;
    }
    bool getS() {
        return stone;
    }
    bool getA() {
        return relig_attr;
    }
    int getSize() {
        return sizeclothes;
    }
    void get_info() {
        cl.print();
        string v, s, a;

        if (venok)v = "��";
        else v = "���";

        if (stone)s = "��";
        else s = "���";

        if (relig_attr)a = "��";
        else a = "���";

        cout << "��� ������: ����������;" << " ����: " << date << "; ���������� ���� � ��������: " << bus_n << "; �����: " << v << "; ��������� ������: " << s << "; ���������: " << a << "\n���� �������� (b / a): "
            << heightB << " - " << heightA << "; ������ ������: " << sizeclothes << "; ��� �����: " << grob << endl;
    }
    string getUrna() {
        return "";
    }
    void change_info() {
        cout << "�������� ����� ������, ������� �� ������ �� ���������������:\n";
        cout << "(1). ����" << endl;
        cout << "(2). ���������� ����� � ��������" << endl;
        cout << "(3). ��� �����" << endl;
        cout << "(4). ���������� � �������" << endl;
        cout << "(5). ���� �� ������" << endl;
        cout << "(6). ���� ����� ������" << endl;
        cout << "(7). ������� �����" << endl;
        cout << "(8). ������� ���������� �����" << endl;
        cout << "(9). ������� �����. ���." << endl;
        cout << "(10). ������ ������" << endl;
        int select = 0;
        while (select < 1 || select>10) {
            cin >> select;
        }
        switch (select) {
        case 1:
        {
            cout << "������� ���� ���������� ���������� ���������: ";
            cin >> date;
            break;
        }
        case 2:
        {
            cout << "������� ���-�� ���� � ��������, ������� �������� ������ �� ����� ����������: ";
            cin >> bus_n;
            break;
        }
        case 3:
        {
            cout << "������� ��� �����, ������� �� ������������� ������� �� ���������:" << endl;
            for (int i = 0; i < 4; i++) {
                cout << "[" << i + 1 << "] " << vid_groba[i] << " " << desc[i] << endl;
            }
            int k = 0;
            while (k < 1 || k>4) {
                cin >> k;
            }
            grob = vid_groba[k - 1];
            break;
        }
        case 4:
        {
            string name, surname, number;
            cout << "������� ��� ������ �������: ";
            cin >> name;
            cout << "������� ������� ������ �������: ";
            cin >> name;
            cout << "������� ����� �������� ������ ������� ��� ���������� �����: ";
            cin >> number;
            cl = client(name, surname, number);
            break;
        }
        case 5: {
            cout << "������� ���� �������� �� ������: ";
            cin >> heightB;
            break;
        }
        case 6: {
            cout << "������� ���� �������� ����� ������: ";
            cin >> heightA;
            break;
        }
        case 7: {
            string select = "";
            while (select != "Y" && select != "N" && select != "y" && select != "n") {
                cout << "����� �� �����? [Y/N]" << endl;
                cin >> select;
            }
            if (select == "Y" or select == "y") venok = true;
            else venok = false;
            break;
        }
        case 8: {
            string select = "";
            while (select != "Y" && select != "N" && select != "y" && select != "n") {
                cout << "����� �� ������������ ������? ���� ���, ������ ����� ����� ������ �����. [Y/N]" << endl;
                cin >> select;
            }
            if (select == "Y" or select == "y") stone = true;
            else stone = false;
            break;
        }
        case 9: {
            string select = "";
            while (select != "Y" && select != "N" && select != "y" && select != "n") {
                cout << "����� �� ����������� ��������? [Y/N]" << endl;
                cin >> select;
            }
            if (select == "Y") relig_attr = true;
            else relig_attr = false;
            break;
        }
        case 10: {
            cout << "������� ������ ������ ���������: ";
            cin >> sizeclothes;
            break;
        }
        default:
            break;
        }
    }
};
class Cremacia :public zakaz {
private:
    string urna;
    int urna_n;
    string vid_groba[3] = {
        "���������",
        "����������",
        "��������",
    };

    string vid_urni[4] = {
        "����������",
        "������������",
        "����������",
        "��������",
    };

public:
    Cremacia() { this->type = 1; }
    Cremacia(string name, string surname, string number, string date, int heightB, int heightA, string grob, string urna) {
        cl = client(name, surname, number);
        this->date = date;
        this->heightB = heightB;
        this->heightA = heightA;
        this->grob = grob;
        this->urna = urna;
        this->type = 1;
    }
    void create_info() {
        string name, surname, number;
        cout << "������� ���� ��� � �������: ";
        cin >> name >> surname;

        cout << "������� ����� �������� ��� �����: ";
        cin >> number;
        cl = client(name, surname, number);
        cout << "������� ���� ���������� ���������� ���������: ";
        cin >> date;

        cout << "������� ���� ��������, �� � ����� ������: ";
        cin >> heightB >> heightA;

        cout << "������� ��� �����, ������� �� ������������� ������� �� ����� ��������:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "[" << i + 1 << "] " << vid_groba[i] << endl;
        }
        int choose = 0;
        while (choose < 1 || choose>3) {
            cin >> choose;
        }
        grob = vid_groba[choose - 1];

        cout << "�� ������ ��������� ���������� ����?" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "[" << i + 1 << "] " << vid_urni[i] << endl;
        }
        choose = 0;
        while (choose < 1 || choose>4) {
            cin >> choose;
        }
        urna = vid_urni[choose - 1];
    }
    void get_info() {
        cl.print();
        cout << "��� ������: ��������;" << " ����: " << date << ";\n���� �������� (b/a): "
            << heightB << " - " << heightA << "; ��� �����: " << grob << "; �������� ����: " << urna << endl;
    }
    string getUrna() {
        return urna;
    }
    void change_info() {
        cout << "�������� ����� ������, ������� �� ������ �� ���������������" << endl;
        cout << "(1). ����" << endl;
        cout << "(2). ���� �� ������" << endl;
        cout << "(3). ���� ����� ������" << endl;
        cout << "(4). ���������� � �������" << endl;
        cout << "(5). ��� �����" << endl;
        cout << "(6). �������� ����" << endl;;
        int select = 0;
        while (select < 1 || select>6) {
            cin >> select;
        }
        switch (select) {
        case 1: {
            cout << "������� ���� ���������� ���������� ���������: ";
            cin >> date;
            break;
        }
        case 2: {
            cout << "������� ���� �������� �� ������: ";
            cin >> heightB;
            break;
        }
        case 3: {
            cout << "������� ���� �������� ����� ������: ";
            cin >> heightA;
            break;
        }
        case 4:
        {
            string name, surname, number;
            cout << "������� ��� ������ �������: ";
            cin >> name;
            cout << "������� ������� ������ �������: ";
            cin >> name;
            cout << "������� ����� �������� ������ ������� ��� ���������� �����: ";
            cin >> number;
            cl = client(name, surname, number);
            break;
        }
        case 5:
        {
            cout << "������� ��� �����, ������� �� ������������� ������� �� ����� ��������:" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "[" << i + 1 << "] " << vid_groba[i] << endl;
            }
            int k = 0;
            while (k < 1 || k>3) {
                cin >> k;
            }
            grob = vid_groba[k - 1];
            break;
        }
        case 6: {
            cout << "������� ��� �����, ������� �� ������������� ������� �� ����� ��������:" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "[" << i + 1 << "] " << vid_groba[i] << endl;
            }
            int k = 0;
            while (k < 1 || k>3) {
                cin >> k;
            }
            grob = vid_groba[k - 1];
        }
        default: {
            break;
        }
        }
    }
    int getNBus() {
        return 0;
    }
    bool getV() {
        return 0;
    }
    bool getS() {
        return 0;
    }
    bool getA() {
        return 0;
    }
    int getSize() {
        return 0;
    }
};