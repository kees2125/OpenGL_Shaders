#version 330 core

uniform sampler2D s_texture;
uniform float time;
varying vec2 texCoord;


vec2 SineWave( vec2 p )
    {
    float value1 = 0.6f;
    float value2 = 0.0f;
    float value3 = 0.05f;
    // convert Vertex position <-1,+1> to texture coordinate <0,1> and some shrinking so the effect dont overlap screen
    //p.x=( value2*p.x)+value1;
   // p.y=(-value2*p.y)+value1;
    // wave distortion
    float x = sin( 25.0*p.y + 30.0*p.x + 6.28*time) * value3;
    float y = sin( 25.0*p.y + 30.0*p.x + 6.28*time) * value3;
    return vec2(p.x+x, p.y+y);
    }

void main()
{
	gl_FragColor = texture2D(s_texture, SineWave(texCoord));
}