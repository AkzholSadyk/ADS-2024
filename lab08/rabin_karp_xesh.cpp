#include <iostream>
#include <string>
using namespace std;

const int d = 256; // Размер алфавита
const int q = 101; // Простое число для модуляции

void rabinKarp(string pattern, string text) {
    int count=0;
    int m = pattern.size();
    int n = text.size();
    int i, j;
    int p = 0; // Хеш для шаблона
    int t = 0; // Хеш для текста
    int h = 1;

    // Вычисляем h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Вычисляем начальные хеши для шаблона и первого окна текста
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Сдвигаем окно по тексту
    for (i = 0; i <= n - m; i++) {
        // Проверяем совпадение хешей
        if (p == t) {
            // Проверяем символы по одному
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                count++;
                // cout << "Шаблон найден на позиции " << i << endl;
        }

        // Вычисляем хеш для следующего окна текста
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
    cout << count;
}

int main() {
    string text = "ABCCDDAEFGCDD";
    string pattern = "CDD";
    
    rabinKarp(pattern, text);
    
    return 0;
}
