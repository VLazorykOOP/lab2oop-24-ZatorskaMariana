#include <iostream>
#include <string>
#include <bitset>

using namespace std;

// Функція для підрахунку парності
int calculateParity(int asciiCode) {
    int count = 0;
    while (asciiCode) {
        count += (asciiCode & 1); // підраховуємо одиничні біти
        asciiCode >>= 1; // зсуваємо код вліво
    }
    return count % 2; // повертаємо парність
}

// Функція для шифрування тексту
void encryptText(const string& inputText) {
    string text = inputText;
    
    // Доповнюємо текст до 128 символів пробілами
    text.append(128 - text.length(), ' ');
    
    // Проходимо по кожному символу тексту
    for (int i = 0; i < text.length(); ++i) {
        char currentChar = text[i];
        
        // Отримуємо ASCII код символу
        int asciiCode = static_cast<int>(currentChar);
        
        // Обчислюємо біт парності
        int parityBit = calculateParity(asciiCode);
        
        // Позиція символу в рядку (7 біт)
        int position = i;
        
        // Створюємо бінарні рядки для результату
        bitset<1> parity(parityBit); // біт парності
        bitset<8> ascii(asciiCode); // ASCII код
        bitset<7> pos(position);    // Позиція символу
        
        // Формуємо результат
        bitset<16> encrypted;
        encrypted[0] = parity[0]; // Перший біт - біт парності
        for (int j = 1; j < 9; ++j) {
            encrypted[j] = ascii[j-1]; // 8 біт для ASCII
        }
        for (int j = 9; j < 16; ++j) {
            encrypted[j] = pos[j-9]; // 7 біт для позиції
        }
        
        // Виводимо результат
        cout << "Символ: '" << currentChar << "' -> Зашифровано: " << encrypted << endl;
    }
}

int main() {
    string inputText;
    
    // Вводимо текст
    cout << "Введіть текст до 128 символів: ";
    getline(cin, inputText);
    
    // Шифруємо текст
    cout << "Зашифрований текст: " << endl;
    encryptText(inputText);
    
    return 0;
}
