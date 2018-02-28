#include "skyBox.h"
#include <iostream>
#include <string>
#include "stb_image.h"

using namespace std;
enum { SKY_LEFT = 0, SKY_BACK, SKY_RIGHT, SKY_FRONT, SKY_TOP, SKY_BOTTOM };
unsigned int skyBoxSides[6];
string filepath = "cubemapsame_desert/desertsky_";
string fileEnding[6] = { "lf.tga","bk.tga","rt.tga","ft.tga","up.tga","dn.tga" };

skyBox::skyBox()
{
}


skyBox::~skyBox()
{
}


void skyBox::killskybox()
{
	glDeleteTextures(6, &skyBoxSides[0]);
}
void skyBox::initskybox()
{
	int width, height, bpp;
	for (int x = 0; x < 6; x++)
	{
		glGenTextures(1, &skyBoxSides[x]);
	}

	unsigned char* l = stbi_load(string(filepath + fileEnding[0]).c_str() , &width, &height, &bpp, 4);
	if (!l)
		printf("%s\n", stbi_failure_reason());
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_LEFT]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger

	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		width,		//width
		height,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		l);


	unsigned char* ba = stbi_load(string(filepath + fileEnding[1]).c_str(), &width, &height, &bpp, 4);
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_BACK]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger

	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		width,		//width
		height,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		ba);
	unsigned char* r = stbi_load(string(filepath + fileEnding[2]).c_str(), &width, &height, &bpp, 4);
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_RIGHT]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger

	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		width,		//width
		height,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		r);
	unsigned char* f = stbi_load(string(filepath + fileEnding[3]).c_str(), &width, &height, &bpp, 4);
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_FRONT]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger

	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		width,		//width
		height,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		f);
	unsigned char* t = stbi_load(string(filepath + fileEnding[4]).c_str(), &width, &height, &bpp, 4);
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_TOP]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger

	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		width,		//width
		height,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		t);
	unsigned char* bo = stbi_load(string(filepath + fileEnding[5]).c_str(), &width, &height, &bpp, 4);
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_BOTTOM]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger
	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		width,		//width
		height,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		bo);


}
void skyBox::drawSkybox(float size)
{
	glColor3f(1, 1, 1);
	bool b1 = glIsEnabled(GL_TEXTURE_2D);     //new, we left the textures turned on, if it was turned on
	glDisable(GL_LIGHTING); //turn off lighting, when making the skybox
	glDisable(GL_DEPTH_TEST);       //turn off depth texting
	glEnable(GL_TEXTURE_2D);        //and turn on texturing
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_BACK]);  //use the texture we want
	glBegin(GL_QUADS);      //and draw a face
							//back face
	glTexCoord2f(0, 0);      //use the correct texture coordinate
	glVertex3f(size / 2, size / 2, size / 2);       //and a vertex
	glTexCoord2f(1, 0);      //and repeat it...
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_LEFT]);
	glBegin(GL_QUADS);
	//left face
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_FRONT]);
	glBegin(GL_QUADS);
	//front face
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_RIGHT]);
	glBegin(GL_QUADS);
	//right face
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_TOP]);
	glBegin(GL_QUADS);                      //top face
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skyBoxSides[SKY_BOTTOM]);
	glBegin(GL_QUADS);
	//bottom face
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
	glEnable(GL_DEPTH_TEST);
	if (!b1)
		glDisable(GL_TEXTURE_2D);
}