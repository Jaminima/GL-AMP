#include <iostream>
#include "../GL-AMP/framework.h"

void RenderPoint(Point cam, Point triP, array_view<Color, 2> sBuf, unsigned int w, unsigned int h) restrict(amp) {
	Ray r(cam, triP, false);
	ScreenPos p = r.GetScreenPosition(w, h);
	sBuf[p.y][p.x].Set(255, 255, 255);
}

void RenderScene(array_view<Color, 2>* sBuffer, array_view<Triangle, 1>* triBuffer) {
    array_view<Color, 2> sBuf = *sBuffer;
    array_view<Triangle, 1> tBuff = *triBuffer;

	unsigned int w = GL::window_Width, h = GL::window_Height;

	Point cam(0, 0, 10);

	ClearView();

	parallel_for_each(
		extent<1>(TriangleViewHead),
		[=](index<1> idx)restrict(amp) {
			RenderPoint(cam, tBuff[idx].p1, sBuf, w, h);
			RenderPoint(cam, tBuff[idx].p2, sBuf, w, h);
			RenderPoint(cam, tBuff[idx].p3, sBuf, w, h);
		}
    );
}

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

	pick_accelerator();

	Triangle* t = new Triangle[]{
		//Front
			Triangle(Point(3, 3, 3), Point(3, 5, 3), Point(3, 5, 5)),
			Triangle(Point(3, 3, 3), Point(3, 3, 5), Point(3, 5, 5)),

			//Back
				Triangle(Point(5, 3, 3), Point(5, 5, 3), Point(5, 5, 5)),
				Triangle(Point(5, 3, 3), Point(5, 3, 5), Point(5, 5, 5)),

				//Left
					Triangle(Point(3, 3, 3), Point(3, 5, 3), Point(5, 5, 3)),
					Triangle(Point(3, 3, 3), Point(5, 3, 3), Point(5, 5, 3)),

					//Right
						Triangle(Point(3, 3, 5), Point(3, 5, 5), Point(5, 5, 5)),
						Triangle(Point(3, 3, 5), Point(5, 3, 5), Point(5, 5, 5)),

						//Bottom
							Triangle(Point(3, 3, 3), Point(5, 3, 3), Point(5, 3, 5)),
							Triangle(Point(3, 3, 3), Point(3, 3, 5), Point(5, 3, 5)),

							//Top
								Triangle(Point(3, 5, 3), Point(5, 5, 3), Point(5, 5, 5)),
								Triangle(Point(3, 5, 3), Point(3, 5, 5), Point(5, 5, 5)),
	};

	Ray r(Point(1, 1, 21), t[1].p2, false);

	std::cout << r.direction.y << '\n';

	ScreenPos p = r.GetScreenPosition(511, 511);

	std::cout << p.y;

    /*GL::InitializeWindow(argc, argv);
    
    GL::renderSceneFunction = &RenderScene;

    Mesh M(t, 12);

    GL::StartGL();*/

    while (true) {}
}
