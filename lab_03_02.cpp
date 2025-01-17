﻿// lab_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <curl/curl.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "histogram.h"
#include "svg.h"
#include <windows.h>

using namespace std;
DWORD WINAPI GetVersion(void);
vector<double> input_numbers(istream& in, size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}
Input
read_input(istream& in, bool prompt) {
    Input data;
    if (true)
    {
        cerr << "Enter number count: ";
        size_t number_count;
        in >> number_count;

        cerr << "Enter numbers: ";
        data.numbers = input_numbers(in, number_count);

        cerr << "Enter bin count: ";
        size_t bin_count;
        in >> bin_count;
    }
    else
    {
        size_t number_count;
        in >> number_count;
        data.numbers = input_numbers(in, number_count);
        size_t bin_count;
        in >> bin_count;
    }


    return data;
}


int main(int argc, char* argv[])
{
    const char* name = "Commander Shepard";
    int year = 2154;
    printf("%s was born in %d.\n", name, year);
    printf("n = %08x\n", 0x1234567); // 01234567

    const auto R = GetVersion();
    printf("n = %10x\n", R);
    printf("n = %16x\n", R);
    
    DWORD mask = 0b00000000'00000000'11111111'11111111;
    DWORD version = R & mask;
    printf("ver = %lu\n", version);
    DWORD mask2 = 0b00000000'11111111;
    DWORD version_major = version & mask2;
    printf("version_major = %lu\n", version_major);
    DWORD version_minor = version >> 8;
    printf("version_minor = %lu\n", version_minor);
    DWORD build;
    DWORD platform = R >> 16;
    printf("ver2 = %lu\n", platform);
    if ((R & 0x80000000) == 0)
    {
        build = platform;
        printf("build = %lu\n", build);

    }
    cerr << "Windows" << " " << "v" << " " << version_major << "." << version_minor << " " << "(build" << " " << build << ")" << endl;
    if (argc > 1)
    {
        CURL* curl = curl_easy_init();
        if (curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &buffer);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                cerr « curl_easy_strerror(res);
                cerr « "problem" « endl;
                exit(1);
            }
            else {
                cerr « 'OK';
            }
            /*long req;
            res = curl_easy_getinfo(curl, CURLINFO_REQUEST_SIZE, &req);
            cerr « "REQUEST_SIZE: " « req « endl;*/
        }
        return 0;
    }
    curl_global_init(CURL_GLOBAL_ALL);
    //ввод данных
    
    
    const auto input = read_input(cin, true);
    
    
    size_t interval;
    cerr << "enter size of interval - ";
    cin >> interval;
   
    if (proverka_intervals(interval) == false)
    {
        cerr << "ERROR";
        return 1;
    }
    //расчет гиcтограммы
    double min, max;
    find_minmax(input.numbers, min, max);

     const auto bins = make_histogram(input.numbers, min, max, input.bin_count, input.number_count);
    //вывод данных
    
    
    show_histogram_svg(bins, interval);
    
   




    return 0;
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
