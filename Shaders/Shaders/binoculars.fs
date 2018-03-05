#version 150 core

uniform sampler2D s_texture;
varying vec2 texCoord;

void main()
{
	vec4 color = texture2D(s_texture, texCoord);
	float length1 = sqrt((texCoord.x - 0.35) * (texCoord.x - 0.35) + (texCoord.y - 0.5) * (texCoord.y - 0.5));
    float length2 = sqrt((texCoord.x - 0.65) * (texCoord.x - 0.65) + (texCoord.y - 0.5) * (texCoord.y - 0.5));
	if(length1 < 0.2 || length2 < 0.2)
	{
		gl_FragColor = color;
	}
	else
	{
		gl_FragColor = vec4(0, 0, 0, 0);
	}
}