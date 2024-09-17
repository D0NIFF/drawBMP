/*
    © D0NIFF
*/

#include <iostream>
#include "BMPClient.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "[Ошибка] Не указан путь к BMP файлу. Пример использования: " << argv[0] << " <путь_к_BMP_файлу>" << std::endl;
        return 1;
    }

    BMPClient viewer;
    viewer.openBMP(argv[1]);
    viewer.displayBMP();
    viewer.closeBMP();

    return 0;
}
