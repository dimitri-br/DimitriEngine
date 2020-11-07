#pragma once
namespace Rendering {
	// BackEndType specifies what graphics API to use (default is OpenGL)
	enum class BackEndType {
		OpenGL,
		Vulkan,
		DirectX,
	};
}
