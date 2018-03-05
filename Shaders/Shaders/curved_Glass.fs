#version 150
uniform samplerCube _Cube; 
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 camaraPosision;

void main()
{
            vec3 normalDirection;
            vec3 viewDirection;
            mat4 ModelMatrix = modelMatrix;
            mat4 modelMatrixInverse = inverse(modelMatrix); 
            
            normalDirection = normalize(vec3(
               vec4(gl_Normal, 0.0) * ModelMatrixInverse));
            viewDirection = vec3(modelMatrix * gl_Vertex 
               - vec4(camaraPosision, 1.0));

          float refractiveIndex = 1.5;
            vec3 refractedDirection = refract(normalize(viewDirection), 
               normalize(normalDirection), 1.0 / refractiveIndex);
            gl_FragColor = textureCube(_Cube, refractedDirection);
}