#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace std;

// Функция 1: Чтение строк из файла в вектор
vector<string> readLinesFromFile(const string& filename) {
    vector<string> lines;
    ifstream file(filename);

    if (!file.is_open()) {
        wcerr << L"Ошибка: не удалось открыть файл " << filename.c_str() << endl;
        return lines;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    file.close();
    for (size_t i = 0; i < lines.size(); ++i) {
        wcout << L"[" << i << L"] " << lines[i].c_str() << endl;
    }

    return lines;
}

// Функция 2: Вывод вектора строк на экран
void printLinesToConsole(const vector<string>& lines) {
    // TODO: Реализовать вывод на экран
    wcout << L"[ОТЛАДКА] Функция printLinesToConsole() пока не реализована." << endl;
}

// Функция 3: Запись вектора строк в файл
void writeLinesToFile(const vector<string>& lines, const string& filename) {
    // TODO: Реализовать запись в файл
    wcout << L"[ОТЛАДКА] Функция writeLinesToFile() пока не реализована." << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    wcout << L"=== ПРОГРАММА ДЛЯ РАБОТЫ С ТЕКСТОВЫМИ ФАЙЛАМИ ===" << endl;
    wcout << L"Авторы: Маруков, Лошкарёв, Перминов." << endl;
    wcout << endl;

    string inputFilename = "input.txt";
    string outputFilename = "output.txt";

    wcout << L"Имя входного файла: " << inputFilename.c_str() << endl;
    wcout << L"Имя выходного файла: " << outputFilename.c_str() << endl;
    wcout << endl;

    // 1. Чтение из файла
    wcout << L"Шаг 1: Чтение данных из файла..." << endl;
    vector<string> lines = readLinesFromFile(inputFilename);

    // 2. Вывод на экран
    wcout << L"Шаг 2: Вывод данных на экран..." << endl;
    printLinesToConsole(lines);

    // 3. Запись в файл
    wcout << L"Шаг 3: Запись данных в файл..." << endl;
    writeLinesToFile(lines, outputFilename);

    wcout << endl;
    wcout << L"Программа успешно завершена!" << endl;


    return 0;
}
