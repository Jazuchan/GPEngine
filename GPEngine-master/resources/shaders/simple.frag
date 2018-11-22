uniform sampler2D in_Texture;

varying vec2 ex_TexCoord;
varying vec4 ex_Color;

//uniform vec3 lightColor


void main()
{
	//float ambientStrength = 0.1;
	//vec3 ambient = ambientStrength * lightColor
	vec4 tex = texture2D(in_Texture, ex_TexCoord);
	gl_FragColor = tex;
}
