#include <iostream>
#include "../GL-AMP/framework.h"

void RenderScene(array_view<Color, 2>* sBuffer) {
    array_view<Color, 2> sBuf = *sBuffer;
    parallel_for_each(
        sBuffer->extent,
        [=](index<2> idx)restrict(amp) {
            sBuf[idx].Set(idx[0]%255, idx[1]%255, (idx[0]+idx[1])%255);
        }
    );

    sBuffer->synchronize();
}

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";
    GL::InitializeWindow(argc, argv);
    
    GL::renderSceneFunction = &RenderScene;

    GL::StartGL();

    while (true) {}
}
