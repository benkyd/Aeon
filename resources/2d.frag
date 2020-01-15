#version 430

out vec4 FragColour;
  
in vec2 fTextCoord;

uniform sampler2D iTexture;

void main() 
{
	FragColour = texture(iTexture, fTextCoord);
	// FragColour = vec4( 1.0, .0, .0, 1.0); // texture(iTexture, fTextCoord);	
}
