#pragma once
#include "../transform/transform.h"

namespace DimitriEngine {
	class Light
	{
	public:
		Transform transform;


		Light(); // Constructor with default values
		Light(Transform _transform); // Constructor with user-defined transform

	
		void Draw();
	private:

	};
}


