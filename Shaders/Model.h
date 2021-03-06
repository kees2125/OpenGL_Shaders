#pragma once

#include <string>
#include <vector>

#include <windows.h>
#include <gl/GL.h>

class Texture;

class Model
{
private:
	class MaterialInfo
	{
	public:
		MaterialInfo();
		std::string name;
		Texture* texture;
		Texture* bumpMap;
		float ambient[3] = {0, 0, 0};
		float shininess = 10;
		bool hasTexture;
	};

	class ObjGroup
	{
	public:
		std::string name;
		int start;
		int end;
		int materialIndex;
	};

	std::vector<ObjGroup*> groups;
	std::vector<MaterialInfo*> materials;
	GLuint _vertexArray;

	void loadMaterialFile(std::string fileName, std::string dirName);
public:
	Model(std::string filename);
	~Model(void);

	void draw();
};

