#include <cstdlib>
#include <iostream>
#include "Renderer/backend.h"

using Rendering::BackEnd;
using Rendering::BackEndType;

int main() {
	BackEnd backEnd;
	backEnd.Initialize(BackEndType::OpenGL);

	std::cout << "Initialized engine!" << std::endl;

	backEnd.MainLoop();

	backEnd.openGLRenderer.Exit();
	std::cout << "Successfully exit!" << std::endl;

	return 0;
}