/*
    © D0NIFF
*/

#include <iostream>
#include "BMPClient.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "[Error] Used example: " << argv[0] << " <Path_to_BMP_file>" << std::endl;
        return 1;
    }

    BMPClient viewer;
    viewer.openBMP(argv[1]);
    viewer.displayBMP();
    viewer.closeBMP();

    return 0;
}
