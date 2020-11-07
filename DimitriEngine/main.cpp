#include <cstdlib>
#include <iostream>
#include "Renderer/backend.h"

using Rendering::BackEnd;
using Rendering::BackEndType;

int main() {
	BackEnd backEnd = BackEnd(BackEndType::Vulkan);

	std::cout << "Initialized engine!" << std::endl;

	backEnd.MainLoop();

	backEnd.openGLRenderer.Exit();
	return 0;
}