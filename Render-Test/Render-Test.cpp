#include <iostream>
#include "../GL-AMP/GL-Manager.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";
    GL::InitializeWindow(argc, argv);

    GL::StartGL();

    while (true) {}
}
