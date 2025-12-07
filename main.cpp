#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <locale>


using namespace std;

// Функция 1: Чтение строк из файла в вектор
vector<wstring> readLinesFromFile(const string& filename)
{
    vector<wstring> lines;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return lines;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            wstring wline(line.begin(), line.end());
            lines.push_back(wline);
        }
    }

    file.close();
    for (size_t i = 0; i < lines.size(); ++i) {
        wcout << L"[" << i << L"] " << lines[i] << endl;
    }

    return lines;
}

// Функция 2: Вывод вектора строк на экран
void printLinesToConsole(const vector<wstring>& lines) {
   if (lines.empty()) {
       wcout << L"Вектор строк пуст. Нечего выводить." << endl;
       return;
   }

   wcout << L"\n=== ВЫВОД СОДЕРЖИМОГО (" << lines.size() << L" строк) ===" << endl;
   wcout << L"------------------------------------------------" << endl;

   for (size_t i = 0; i < lines.size(); ++i) {
       wcout << L"Строка " << (i + 1) << L": \"" << lines[i] << L"\"" << endl;
   }

   wcout << L"------------------------------------------------" << endl;
   wcout << L"Всего строк: " << lines.size() << endl;
}
// Функция 3: Запись вектора строк в файл
void writeLinesToFile(const vector<wstring>& lines, const string& filename) {
    if (lines.empty()) {
        wcout << L"Предупреждение: попытка записать пустой вектор в файл." << endl;
        return;
    }

    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    for (const auto& line : lines) {
        string str(line.begin(), line.end());
        file << str << endl;
    }

    file.close();

    wcout << L"Успешно записано " << lines.size() << L" строк в файл '"
         << filename.c_str() << L"'" << endl;
}


int main() {

    setlocale(LC_ALL, "Russian");
    wcout << L"=== ПРОГРАММА ДЛЯ РАБОТЫ С ТЕКСТОВЫМИ ФАЙЛАМИ ===" << endl;
    wcout << L"Авторы: Маруков, Лошкарёв, Перминов." << endl;
    wcout << endl;

    string inputFilename = "input.txt";
    string outputFilename = "output.txt";

    wcout << L"Имя входного файла: " << inputFilename.c_str()<< endl;
    wcout << L"Имя выходного файла: " << outputFilename.c_str()<< endl;
    wcout << endl;

    // 1. Чтение из файла
    wcout << L"Шаг 1: Чтение данных из файла..." << endl;
    vector<wstring> lines = readLinesFromFile(inputFilename);

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
