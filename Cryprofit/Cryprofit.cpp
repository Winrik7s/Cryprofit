// Cryprofit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>

#include <curl/curl.h>
#include <windows.h>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string getPrice(const string& crypt)
{
    if(crypt.empty())
    {
        cerr << "Название криптовалюты не может быть пустым." << endl;
        return "";
    }

    CURL* curl;
    CURLcode res;

    string readBuffer;
    curl = curl_easy_init();

    if(curl)
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        string url = "https://api.coingecko.com/api/v3/simple/price?ids=" + crypt + "&vs_currencies=usd";

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); //Отключаем проверку SSL

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) 
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cerr << endl;
            cerr << " | curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return "";
        }

        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    system("chcp 1251 > nul");

    cout << " /(.)(.)\\ CRYPROF1T /(.)(.)\\" << endl;
    cout << endl;

    string symbol = " ";
    string crypt;

    while (symbol != "n")
    {
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        cout << " | Получить курс криптовалюты?" << endl;
        cout << " | y - Да, n - Нет: ";

        cin >> symbol;
        cout << endl;

        if (symbol == "y")
        {
            cout << " | Введите название криптовалюты: ";
            cin >> crypt;

            string priceData = getPrice(crypt);

            if (!priceData.empty())
            {
                cout << " | Курс " << crypt << " в USD: ";
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
                cout << priceData << endl;
                cout << endl;
            }
            else
            {
                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                cout << " | Ошибка при получении данных." << endl;
                cout << endl;
            }
        }
        else if (symbol == "n")
        {
            cout << " | Хорошо, посмотрим расчет." << endl;
            cout << endl;
        }
        else
        {
            cout << " | Извините, неизвестная команда." << endl;
            cout << endl;
        }
    }

    symbol = " ";

    while (symbol != "n")
    {
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        cout << " | Получить расчет?" << endl;
        cout << " | y - Да, n - Нет: ";

        cin >> symbol;
        cout << endl;

        if (symbol == "y")
        {
            cout << " | Введите кол - во токенов, которые Вы купили: ";

            string line;

            cin >> line;
            double tokens = atof(line.c_str());

            cout << " | Введите цену покупки за один токен: ";

            cin >> line;
            double purchasePrice = atof(line.c_str());

            cout << endl;

            cout << " | Введите цену продажи за один токен: ";

            cin >> line;
            double sellingPrice = atof(line.c_str());

            cout << " | Введите цену, которая составила комиссия: ";

            cin >> line;
            double commission = atof(line.c_str());

            cout << endl;

            double profit = (sellingPrice * tokens) - (purchasePrice * tokens) - commission;
            cout << " | Прибыль: ";

            if (profit <= 0)
            {
                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                cout << "0 USDT" << endl;
                cout << endl;
            }
            else
            {
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
                cout << profit << " USDT" << endl;
                cout << endl;
            }
        }
        else if (symbol == "n")
        {
            return 0;
        }
        else
        {
            cout << " | Извините, неизвестная команда." << endl;
            cout << endl;
        }

    }

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
