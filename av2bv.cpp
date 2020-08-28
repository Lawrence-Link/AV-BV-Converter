#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const char* table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
constexpr int randstable[10] = { 9, 8, 1, 6, 2, 4, 0, 7, 3, 5 };
constexpr int power_array[10] = { 6, 2, 4, 8, 5, 9, 3, 7, 1, 0 };
int operants;

void convert2BV() {
    long long av_processed;
    cout << "please type in an AV series number and hit enter." << endl;
    cout << "AV         \b\b\b\b\b\b\b\b\b";
    cin >> av_processed;
    int table_array_temp[10];
    av_processed = (av_processed ^ 177451812) + 100618342136696320;
    for (int i = 0; i <= 9; i++) {
        long long powX = pow((float)58, i);
        table_array_temp[i] = av_processed / powX % 58;
    }
    char ave_1[10], ave_2[11];
    for (int i = 0; i <= 9; i++)
        ave_1[i] = table[table_array_temp[i]];
    for (int i = 0; i <= 9; i++)
        ave_2[randstable[i]] = ave_1[i];
    ave_2[10] = '\0';
    cout << "BV" << ave_2 << endl;
}

void convert2AV() {
    char bv_processed[10];
    cout << "please type in an BV series number and hit enter." << endl;
    cout << "BV         \b\b\b\b\b\b\b\b\b";
    cin >> bv_processed;
    int exchange[10];
    memset(exchange, 0, 10);
    int answer;
    long double addup = 0;
    for (int i = 0; i <= 9; i++) {
        for (int b = 0; b <= 57; b++) {
            if (table[b] == bv_processed[i])
                exchange[i] = b;
        }
    }
    for (int i = 0; i <= 9; i++) {
        addup += exchange[i] * pow(58, power_array[i]);
    }
    addup -= 100618342136696320;
    answer = static_cast<long> (addup) ^ 0b1010100100111011001100100100;
    cout << "AV" << answer << endl;
}

int main() {
    cout.setf(ios_base::fixed, ios_base::floatfield);
    enum selection { av2bv = 1, bv2av };
    cout << "------------------------------\nBilibili video tag converter\nProgram Written by Lawrence Link\nFor more infomation please visit this project on\nhttps://github.com/Lawrence-Link/AV-BV-Converter\n------------------------------\n";
    cout << "Please choose one function\n1)Convert AV to BV  2)Convert BV to AV  q)Quit\n> " << "\b";
    cin >> operants;
    switch (operants)
    {
    case av2bv: {
        convert2BV();
        break;
    }
    case bv2av: {
        convert2AV();
        break;
    }
    default: {
        exit(0);
        break;
    }
    }
    system("PAUSE");
    return 0;
}