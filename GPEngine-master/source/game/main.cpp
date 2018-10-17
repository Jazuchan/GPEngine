#include <haruengine/haru.h>

#include <iostream>


//class Player: public Segment
//{
//public:
//	void onTick()
//	{
//		std::cout << "hello world" << std::endl;
//		std::cout << "world hello" << std::endl;
//	};
//};

class CheckScreen : public haru::Segment
{
public:
	void onInit( std::string color )
	{
		//std::cout << "onInit " << color << std::endl;
	}

	void onBegin()
	{
		//std::cout << "onBegin" << std::endl;
	}

	void onTick()
	{
		//std::cout << "onTick" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "onTick" << std::endl;
	}
};

int main()
{
	std::shared_ptr<haru::Root> r = haru::Root::load();
	std::shared_ptr<haru::Object> o = r->addObject();

	std::shared_ptr<CheckScreen> cs = o->addSegment<CheckScreen>( "Green" );
	std::shared_ptr<haru::MeshRenderer> mr = o->addSegment<haru::MeshRenderer>();
	std::shared_ptr<haru::MeshRenderer> mr2 = o->addSegment<haru::MeshRenderer>();


	r->start();

	//const GLfloat positions[] =
	//{
	//	0.0f, 0.5f, 0.0f,
	//	-0.5f, -0.5f, 0.0f,
	//	0.5f, -0.5f, 0.0f
	//};

	//GLuint positionsVboId = 0;

	//glGenBuffers( 1, &positionsVboId );

	//if(!positionsVboId)
	//{
	//	throw std::exception();
	//}

	//glBindBuffer( GL_ARRAY_BUFFER, positionsVboId );
	//glBufferData( GL_ARRAY_BUFFER, sizeof( positions ), positions, GL_STATIC_DRAW );
	//glBindBuffer( GL_ARRAY_BUFFER, 0 );

	//GLuint vaoId = 0;

	//glGenVertexArrays( 1, &vaoId );

	//if(!vaoId)
	//{
	//	throw std::exception();
	//}

	//glBindVertexArray( vaoId );

	//glBindBuffer( GL_ARRAY_BUFFER, positionsVboId );

	//glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE,
	//	3 * sizeof( GLfloat ), ( void * ) 0 );
	//glEnableVertexAttribArray( 0 );

	//glBindBuffer( GL_ARRAY_BUFFER, 0 );
	//glBindVertexArray( 0 );

	//const GLchar *vertexShaderSrc =
	//"attribute vec3 in_Position;			"\
	//"										"\
	//"void main()							"\
	//"{										"\
	//"gl_Position = vec4(in_Position, 1.0);	"\
	//"}										";
	//
	//GLuint vertexShaderId = glCreateShader( GL_VERTEX_SHADER );
	//glShaderSource( vertexShaderId, 1, &vertexShaderSrc, NULL );
	//glCompileShader( vertexShaderId );
	//GLint success = 0;
	//glGetShaderiv( vertexShaderId, GL_COMPILE_STATUS, &success );

	//if(!success)
	//{
	//	throw std::exception();
	//}

	//const GLchar *fragmentShaderSrc =
	//"void main()							"\
	//"{										"\
	//"gl_FragColor = vec4(1, 0, 1, 1);		"\
	//"}										";

	//GLuint fragmentShaderId = glCreateShader( GL_FRAGMENT_SHADER );
	//glShaderSource( fragmentShaderId, 1, &fragmentShaderSrc, NULL );
	//glCompileShader( fragmentShaderId );
	//glGetShaderiv( fragmentShaderId, GL_COMPILE_STATUS, &success );

	//if(!success)
	//{
	//	throw std::exception();
	//}

	//GLuint programId = glCreateProgram();
	//glAttachShader( programId, vertexShaderId );
	//glAttachShader( programId, fragmentShaderId );

	//glBindAttribLocation( programId, 0, "in_Position" );

	//glLinkProgram( programId );
	//glGetProgramiv( programId, GL_LINK_STATUS, &success );

	//if(!success)
	//{
	//	throw std::exception();
	//}

	//glDetachShader( programId, vertexShaderId );
	//glDeleteShader( vertexShaderId );
	//glDetachShader( programId, fragmentShaderId );
	//glDeleteShader( fragmentShaderId );

	//glUseProgram( programId );
	//glBindVertexArray( vaoId );

	//glDrawArrays( GL_TRIANGLES, 0, 3 );

	//glBindVertexArray( 0 );
	//glUseProgram( 0 )

	//SDL_DestroyWindow( window );
	//SDL_Quit();

	//std::shared_ptr<Root> root = std::make_shared<Root>();

	//std::shared_ptr<Object> player = root->addObject();
	//player->addSegment<Player>();

	//root->start();

	//std::cout<< "hello world" << std::endl;

	return 0;
}
