#include "BMPClient.h"

/*
    Открывает BMP файл
*/
void BMPClient::openBMP(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file) {
        std::cerr << "[Ошибка] Не удалось открыть файл: " << fileName << std::endl;
        return;
    }

    BITMAPFILEHEADER bmpHeader;
    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));

    if (bmpHeader.bfType != this->bmpFomatCode) {
        std::cerr << "[Ошибка] Файл не является BMP." << std::endl;
        return;
    }

    BITMAPINFOHEADER bmpInfoHeader;
    file.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));

    width = bmpInfoHeader.biWidth;
    height = bmpInfoHeader.biHeight;

    // Размер данных изображения
    data.resize(width * height * 3);
    file.seekg(bmpHeader.bfOffBits, std::ios::beg);
    file.read(reinterpret_cast<char*>(data.data()), data.size());

    file.close();
}


/*
    Выводит значения в консоль (Черное / Белое)
*/
void BMPClient::displayBMP()
{
    // Т.к. BMP хранит данные в инвертированном порядке
    for (int32_t y = height - 1; y >= 0; --y) 
    { 
        for (int32_t x = 0; x < width; ++x) 
        {
            size_t index = (x + y * width) * 3;
            uint8_t blue = data[index];
            uint8_t green = data[index + 1];
            uint8_t red = data[index + 2];

            if      (red == 0 && green == 0 && blue == 0)       std::cout << "#"; // Для черного #
            else if (red == 255 && green == 255 && blue == 255) std::cout << "$"; // Для белого показывает $
        }
        std::cout << std::endl;
    }
}


/*
    Завершает программу
*/
void BMPClient::closeBMP()
{
    data.clear();
}
