#version 150 core

uniform sampler2D s_texture;
varying vec2 texCoord;

void main()
{
	vec4 color = texture2D(s_texture, texCoord);
	float length1 = sqrt((texCoord.x - 0.2) * (texCoord.x - 0.2) + (texCoord.y - 0.2) * (texCoord.y - 0.2));
    float length2 = sqrt((texCoord.x - 0.8) * (texCoord.x - 0.8) + (texCoord.y - 0.8) * (texCoord.y - 0.8));
	if(length1 < 0.2 || length2 < 0.2)
	{
		gl_FragColor = color;
	}
	else
	{
		gl_FragColor = vec4(0, 0, 0, 0);
	}
}