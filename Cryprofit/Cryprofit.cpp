﻿// Cryprofit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    system("chcp 1251 > nul");

    cout << "      ##   ##    ########   ##          ##           ##     \n";
    cout << "     ##   ##    ########   ##          ##        ##     ##  \n";
    cout << "    #######    ##         ##          ##        ##       ## \n";
    cout << "   #######    ########   ##          ##        ##       ##  \n";
    cout << "  ##   ##    ##         ##          ##        ##       ##   \n";
    cout << " ##   ##    ########   ########    ########    ##     ##    \n";
    cout << "##   ##    ########   ########    ########        ##        \n";

    cout << endl;

    cout << "===========================================================>" << endl;

    cout << endl;

    cout << "Введите, кол - во токенов, которые Вы купили: ";
    double tokens = 0;
    cin >> tokens;
 
    cout << endl;

    cout << "Введите, цену покупки за один токен: ";
    double purchasePrice = 0;
    cin >> purchasePrice;

    cout << endl;

    cout << "Введите, цену продажи за один токен: ";
    double sellingPrice = 0;
    cin >> sellingPrice;

    cout << endl;

    cout << "Введите, цену, которая составила комиссия: ";
    double commission = 0;
    cin >> commission;

    cout << endl;

    cout << "===========================================================>" << endl;

    cout << endl;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    double profit = (sellingPrice * tokens) - (purchasePrice * tokens) - commission;

    cout << "Прибыль: ";

    if(profit <= 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        cout << "0 USDT" << endl;
    }
    else
    {
        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
        cout << profit << " USDT" << endl;
    }

    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    system("pause > nul");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
