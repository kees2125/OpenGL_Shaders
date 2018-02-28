#include "Shader.h"
#include <iostream>
#include <fstream>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

Shader::Shader(std::string vsfile, std::string fsfile, std::string gsfile)
{
	std::cout << "loading: " << vsfile << ", " << fsfile << " and " << gsfile << std::endl;
	std::ifstream vertexShaderFile(vsfile);
	std::string vertexShaderData((std::istreambuf_iterator<char>(vertexShaderFile)), std::istreambuf_iterator<char>());
	const char* cvertexShaderData = vertexShaderData.c_str();

	std::ifstream fragShaderFile(fsfile);
	std::string fragShaderData((std::istreambuf_iterator<char>(fragShaderFile)), std::istreambuf_iterator<char>());
	const char* cfragShaderData = fragShaderData.c_str();

	std::ifstream geometryShaderFile(gsfile);
	std::string geometryShaderData((std::istreambuf_iterator<char>(geometryShaderFile)), std::istreambuf_iterator<char>());
	const char* cgeometryShaderData = geometryShaderData.c_str();

	programId = glCreateProgram();								

	GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);			
	glShaderSource(vertexId, 1, &cvertexShaderData, NULL);		
	glCompileShader(vertexId);									
	checkShaderErrors(vertexId);								
	glAttachShader(programId, vertexId);						

	GLuint geometryId = glCreateShader(GL_GEOMETRY_SHADER);
	glShaderSource(geometryId, 1, &cgeometryShaderData, NULL);
	glCompileShader(geometryId);
	checkShaderErrors(geometryId);
	glAttachShader(programId, geometryId);

	GLuint fragmentId = glCreateShader(GL_FRAGMENT_SHADER);		
	glShaderSource(fragmentId, 1, &cfragShaderData, NULL);		
	glCompileShader(fragmentId);								
	checkShaderErrors(fragmentId);								
	glAttachShader(programId, fragmentId);						

	bindAttribute(0, "a_position");
	bindAttribute(1, "a_color");
	bindAttribute(2, "a_texcoord");

	link();
	use();
}

void Shader::checkShaderErrors(GLuint shaderId)
{
	GLint status;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);					
	if (status == GL_FALSE)
	{
		int length, charsWritten;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);				
		char* infolog = new char[length + 1];
		memset(infolog, 0, length + 1);
		glGetShaderInfoLog(shaderId, length, &charsWritten, infolog);		
		std::cout << "Error compiling shader:\n" << infolog << std::endl;
		delete[] infolog;
	}
}

void Shader::link()
{
	glLinkProgram(programId);								
}

void Shader::use()
{
	glUseProgram(programId);								
}

int Shader::getUniformLocation(const std::string &name)
{
	auto it = uniforms.find(name);
	if (it != uniforms.end())
		return it->second;
	GLuint location = glGetUniformLocation(programId, name.c_str());
	uniforms[name] = location;
	return location;
}

void Shader::bindAttribute(GLuint index, const GLchar* value)
{
	glBindAttribLocation(programId, index, value);
}
