#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

class BMPClient 
{
public:
    BMPClient() : width(0), height(0), data() {}
    ~BMPClient() { closeBMP(); } //

    void openBMP(const std::string& fileName);
    void displayBMP();
    void closeBMP();

private:
    int32_t width;  // Длина
    int32_t height; // Ширина
    const uint16_t bmpFomatCode = 0x4D42; // Тип формата BMP
    std::vector<uint8_t> data;
};