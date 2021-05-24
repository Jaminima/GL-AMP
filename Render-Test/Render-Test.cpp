#include <iostream>
#include "../GL-AMP/framework.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";
    GL::InitializeWindow(argc, argv);

    GL::StartGL();

    while (true) {}
}
