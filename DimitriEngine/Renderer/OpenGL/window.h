#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h> // OpenGL windowing

#include <cstdlib>	//cstrings
#include <iostream> // IO stream (input/output)

namespace OpenGL{
	// Function to resize the window at runtime
	void static framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	// Window class for the OpenGL backend. This class controls all window activities for the engine.
	class Window
	{
	public:
		// Setup for the window - sets initial values
		void SetupWindow();

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

	private:
		GLFWwindow* window;
	};
}


