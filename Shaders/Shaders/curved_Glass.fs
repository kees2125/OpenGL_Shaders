#version 150
uniform samplerCube _Cube; 
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 camaraPosision;

void main()
{
//Pixel* dst = m_Surface->GetBuffer() + bx + by * pitchscreen;
//	for ( int x = 128; x > 0; x-- )
//	{
//		float lol =cheapsin( 0.025f * (float)(x - 50));
//		float dx = (float)(x - 64);
//		int ymax = (int)(abs(sqrt(4096-(dx*dx))));
//		int ymin = -ymax;
//		ymin++;
	
//		//for ( int y = 128; y > 0; y-- )
//		for(int y = ymax;y>ymin;y--)
//		{
			
//			int y1 = y+64;
//			int dist = (int)sqrt( dx * dx + y * y );
//		    int xoffs = (int)(((dist >> 1) + 10) * lol);
//			int yoffs = (int)(((dist >> 1) + 10) * cheapsin( 0.025f * (float)(y1 - 50) ) );
//			int u1 = ((bx + x) - 4 * xoffs) % SCRWIDTH;
//			int v1 = ((by + y1) - 4 * yoffs) % SCRHEIGHT;
//			int u2 = ((bx + x) + 2 * xoffs) % SCRWIDTH;
//			int v2 = ((by + y1) + 2 * yoffs) % SCRHEIGHT;
//			Pixel refl = src[u1 + v1 * pitch];
//			Pixel refr = src[u2 + v2 * pitch];
//			int reflscale = (int)(63.0f - 0.015f * ( -dist ++) * ( -dist ++));
//			int refrscale = (int)(0.015f * (-dist ++) * (- dist ++));
//			dst[x + y * m_Surface->GetPitch()] = ScaleColor( refl, 31 - (reflscale >> 1) ) + ScaleColor( refr, 63 - refrscale );
			
//		}
//	}

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