#pragma once
// OpenGL math library
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace OpenGL {
	class Projection {
	private:

	public:

		Projection();

		glm::mat4 projection;
		glm::mat4 view;
		glm::mat4 model;


		void UpdateView(glm::vec3 newPos);

		void UpdateModel(float angle, glm::vec3 rotPos);

		void UpdateProjection(float FOV, float centerPoint, float cullMin, float cullMax);
		void SetRawView(glm::mat4 newView);
	};
}
