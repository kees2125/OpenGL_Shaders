#pragma once

#include "Shader.h"
#include "GL\freeglut.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include <vector>
#include "Modelmanager.h"
#pragma comment(lib, "glew32.lib")

class Window
{
public:
	Window(Modelmanager* ModelManager);
	~Window();
	void Setup();
	void Display();
	void NextShader();
	void PreviousShader();
	void NextPostShader();
	void PreviousPostShader();
	std::vector<Shader*> shaders;
	std::vector<Shader*> postProcessingShaders;
	int currentshader = 0;
	int currentPostShader = 0;
	glm::ivec2 screenSize;
	float rotation = 0;
	bool postProcessingEnabled = false;
};
