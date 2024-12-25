// Cryprofit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <curl/curl.h>

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
        cout << "Название криптовалюты не может быть пустым." << endl;
        return "";
    }

    CURL* curl;
    CURLcode res;

    string readBuffer;
    curl = curl_easy_init();

    if(curl)
    {
        string url = "https://api.coingecko.com/api/v3/simple/price?ids=" + crypt + "&vs_currencies=usd";

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) 
        {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return "";
        }

        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

int main()
{
    system("chcp 1251 > nul");

    string symbol = " ";
    string crypt;

    while(symbol != "n")
    {
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
                cout << " | Курс " << crypt << " в USD: " << priceData << endl;
                cout << endl;
            }
            else
            {
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

    while(symbol != "n")
    {
        cout << " | Получить расчет?" << endl;
        cout << " | y - Да, n - Нет: ";

        cin >> symbol;
        cout << endl;

        if (symbol == "y") 
        {
            cout << " | Введите кол - во токенов, которые Вы купили: ";

            double tokens = 0;
            cin >> tokens;

            cout << " | Введите цену покупки за один токен: ";

            double purchasePrice = 0;
            cin >> purchasePrice;

            cout << endl;

            cout << " | Введите цену продажи за один токен: ";

            double sellingPrice = 0;
            cin >> sellingPrice;

            cout << " | Введите цену, которая составила комиссия: ";

            double commission = 0;
            cin >> commission;

            cout << endl;

            double profit = (sellingPrice * tokens) - (purchasePrice * tokens) - commission;
            cout << " | Прибыль: ";

            if (profit <= 0)
            {
                cout << "0 USDT" << endl;
                cout << endl;
            }
            else
            {
                cout << profit << " USDT" << endl;
                cout << endl;
            }
        }
        else if(symbol == "n")
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
