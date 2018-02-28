#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"

	class skyBox
	{
	public:
		skyBox();
		~skyBox();
		void drawSkybox(float size);
		void killskybox();
		void initskybox();
	};

