#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h> // OpenGL windowing

#include <cstdlib>	//cstrings
#include <iostream> // IO stream (input/output)
#include "BackEndType.h"
#include <glm/glm.hpp>
#include <chrono>



namespace Rendering {
	// Function to resize the window at runtime
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	// Window class for the OpenGL backend. This class controls all window activities for the engine.
	class Window
	{
	public:
		// Window constructor
		Window();

		void LoadOpenGL();

		void LoadVulkan();


		// Needed to display and update the screen
		void SwapWindowBuffers();

		// Check the current keys being pressed, used for input
		int CheckKey(int keycode);

		// Get the window instance (Use as little as possible)
		GLFWwindow* GetWindow();

		// Check if the window should be closed
		bool CheckClose();

		// Set the value of whether or not the window should be closed
		void CloseWindow(bool value);

		// Set the clear color for the background
		void SetClearColor(float r, float g, float b, float a);

		// Safely close and exit the window
		void Exit();

		glm::vec2 MousePos;

		glm::vec2 GetMousePos();

		void mouseCallback(GLFWwindow* window, double xpos, double ypos);
	private:
		GLFWwindow* window;

		Rendering::BackEndType backEndType;

	};
}


