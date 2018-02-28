#include "GL\glew.h"
#include "GL\freeglut.h"
#include "Window.h"
#include "Modelmanager.h"
#include <iostream>


GLint gameWindowInt;
Window* RenderWindow;
Modelmanager* ModelManager;
float lastTime;
bool wireframeEnabled = false;

void Init();
void Idle();
void Display();
void KeyEvent(unsigned char, int, int);
void KeyEventUp(unsigned char, int, int);
void SpecialKeyEvent(int, int, int);

#ifdef WIN32
void GLAPIENTRY onDebug(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
#else
void onDebug(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam)
#endif
{
	std::cout << message << std::endl;
}

void Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

	glewInit();

	if (glDebugMessageCallback)
	{
		glDebugMessageCallback(&onDebug, NULL);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
		glEnable(GL_DEBUG_OUTPUT);
	}
}

void Idle()
{
	float time = glutGet(GLUT_ELAPSED_TIME);
	float elapsed = time - lastTime;


	RenderWindow->rotation += elapsed / 1000.0f;

	ModelManager->movement.move(elapsed);
	glutPostRedisplay();
	lastTime = time;
}

void Display()
{
	
	RenderWindow->Setup();
	RenderWindow->Display();
	
}

void KeyEvent(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		ModelManager->movement.turnLeft(true);
		break;
	case 'd':
		ModelManager->movement.turnRight(true);
		break;
	case'w':
		ModelManager->movement.goForward();
		break;
	case 's':
		ModelManager->movement.goBackward();
		break;
	case '[':
		RenderWindow->PreviousShader();
		break;
	case ']':
		RenderWindow->NextShader();
		break;
	case '.':
		ModelManager->PreviousModel();
		break;
	case '/':
		ModelManager->NextModel();
		break;
	case 'p':
		RenderWindow->postProcessingEnabled = !RenderWindow->postProcessingEnabled;
		break;
	case 'l':
		RenderWindow->PreviousPostShader();
		break;
	case ';':
		RenderWindow->NextPostShader();
		break;
	case 't':
		if (wireframeEnabled)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		wireframeEnabled = !wireframeEnabled;
		break;
	case 27:
		exit(0);
		break;
	}
}

void KeyEventUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		ModelManager->movement.turnLeft(false);
		break;
	case 'd':
		ModelManager->movement.turnRight(false);
		break;
	case 'w':
		ModelManager->movement.stop();
		break;
	case 's':
		ModelManager->movement.stop();
		break;
	}
}

void SpecialKeyEvent(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F11:
		glutFullScreenToggle();
		break;
	}
}

void reshape(int newWidth, int newHeight)
{
	RenderWindow->screenSize.x = newWidth;
	RenderWindow->screenSize.y = newHeight;
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	glutInitWindowSize(1600, 900);
	gameWindowInt = glutCreateWindow("Shader_Window");
	glutIdleFunc(Idle);
	glutDisplayFunc(Display);
	glutKeyboardFunc(KeyEvent);
	glutKeyboardUpFunc(KeyEventUp);
	glutSpecialFunc(SpecialKeyEvent);
	glutReshapeFunc(reshape);
	Init();

	ModelManager = new Modelmanager();
	RenderWindow = new Window(ModelManager);

	glutMainLoop();
}
