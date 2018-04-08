#version 330 core

layout (triangles) in;
layout (points) out;
in vec2 texCoordIn[];
in vec3 colorIn[];
in vec3 normalIn[];
out vec2 texCoord;
out vec3 color;
out vec3 normal;

vec4 getCenter(vec4 position)
{
	float x = (gl_in[0].gl_Position.x + gl_in[1].gl_Position.x + gl_in[2].gl_Position.x) / 3;
	float y = (gl_in[0].gl_Position.y + gl_in[1].gl_Position.y + gl_in[2].gl_Position.y) / 3;
	float z = (gl_in[0].gl_Position.z + gl_in[1].gl_Position.z + gl_in[2].gl_Position.z) / 3;
	float w = (gl_in[0].gl_Position.w + gl_in[1].gl_Position.w + gl_in[2].gl_Position.w) / 3;
	return vec4(x,y,z,w);
}

void main() {    
    gl_Position = gl_in[0].gl_Position;
	texCoord = texCoordIn[0];
	color = colorIn[0];
	normal = normalIn[0];
    EmitVertex();
	EndPrimitive();

	gl_Position = gl_in[0].gl_Position;
	texCoord = texCoordIn[0];
	color = colorIn[0];
	normal = normalIn[0];
    EmitVertex();
	EndPrimitive();

    gl_Position = gl_in[1].gl_Position;
	texCoord = texCoordIn[1];
	color = colorIn[1];
	normal = normalIn[1];
    EmitVertex();
	EndPrimitive();

	gl_Position = gl_in[2].gl_Position;
	texCoord = texCoordIn[2];
	color = colorIn[2];
	normal = normalIn[2];
    EmitVertex();
    
    EndPrimitive();
}  