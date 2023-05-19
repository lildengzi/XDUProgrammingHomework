#include "BMPZoom.h" 
#include <iostream>

int main(int argc, char* argv[])
{
    BMPZoom *z = new BMPZoom;
    if (argc <= 3)
    {
        char input[1001], output[1001];
        int ratio;
        std::cout << "Input path: ";
        std::cin >> input;
        std::cout << "Zoom ratio: ";
        std::cin >> ratio;
        std::cout << "Output path: ";
        std::cin >> output;
        z->zoom(input, ratio, output);
    }
    else
        z->zoom(argv[1], atoi(argv[2]), argv[3]);
    return 0;
}