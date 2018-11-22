#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "RenderTexture.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>

namespace haru
{

void MeshRenderer::OnInit()
{
  m_hallShape = std::make_shared<VertexArray>("../resources/re_hall_baked.obj");
  m_hallTex = std::make_shared<Texture>("../resources/re_hall_diffuse.png");

  m_cube = std::make_shared<VertexArray>("../resources/models/cube.obj");
 // m_texture = std::make_shared<Texture>("../resources/textures-materials/black.png");
  m_texture = std::make_shared<Texture>( "../resources/curuthers_diffuse.png" );
  
  m_shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
  m_lightkeyShader = std::make_shared<ShaderProgram>( "../resources/shaders/lightkeypass.vert", "../resources/shaders/lightkeypass.frag" );
  m_nullShader = std::make_shared<ShaderProgram>( "../resources/shaders/nullpass.vert", "../resources/shaders/nullpass.frag" );
  m_blurShader = std::make_shared<ShaderProgram>( "../resources/shaders/blur.vert", "../resources/shaders/blur.frag" );
  m_mergeShader = std::make_shared<ShaderProgram>( "../resources/shaders/mergepass.vert", "../resources/shaders/mergepass.frag" );

  m_rt = std::make_shared<RenderTexture>( 1024, 1024 );
  m_lightkeyRt = std::make_shared<RenderTexture>( 1024, 1024 );
  m_blurRt = std::make_shared<RenderTexture>( 1024, 1024 );
  m_blur2Rt = std::make_shared<RenderTexture>( 1024, 1024 );
  m_blur3Rt = std::make_shared<RenderTexture>( 1024, 1024 );
  m_mergeRt = std::make_shared<RenderTexture>( 1024, 1024 );

	m_rt->Clear();
  m_shader->SetUniform("in_Projection", glm::perspective(glm::radians(45.0f),(float) m_windowW / (float) m_windowH, 0.1f, 100.f));
}

void MeshRenderer::OnDisplay()
{
	x += m_randX;
	y += m_randY;
	glm::mat4 m_model(1.0f);
	m_model = glm::rotate( m_model, glm::radians( 0.0f ), glm::vec3( 0, 1, 0 ) );
	m_shader->SetUniform("in_View", glm::inverse(m_model));
	
	m_model = glm::mat4(1.0f);
	m_model = glm::translate(m_model, glm::vec3(0.0f, 0.0f, -16.0f)); //offset away from the camera
	m_model = glm::rotate(m_model, glm::radians(90.0f), glm::vec3(0, 1, 0)); //rotate player object as pivot
	m_shader->SetUniform("in_Model", m_model);
	m_shader->SetUniform("in_Texture", m_hallTex);
	m_shader->Draw(m_rt, m_hallShape);

	m_model = glm::mat4(1.0f);
	m_model = glm::translate(m_model, glm::vec3(0.0f, 0.0f, -16.0f)); 
	m_model = glm::rotate( m_model, glm::radians( angle), glm::vec3( x, y, 0 ) );
	m_shader->SetUniform("in_Model", m_model);
	m_shader->SetUniform("in_Texture", m_texture);
	m_shader->Draw(m_rt, m_cube);


	m_lightkeyShader->SetUniform( "in_Texture", m_rt );
	m_lightkeyShader->Draw( m_lightkeyRt );

	m_blurShader->SetUniform( "in_Texture", m_lightkeyRt );
	m_blurShader->Draw( m_blurRt );

	m_blurShader->SetUniform( "in_Texture", m_blurRt );
	m_blurShader->Draw( m_blur2Rt );

	m_blurShader->SetUniform( "in_Texture", m_blur2Rt );
	m_blurShader->Draw( m_blur3Rt );

	m_mergeShader->SetUniform( "in_TextureA", m_rt );
	m_mergeShader->SetUniform( "in_TextureB", m_blur3Rt );
	m_mergeShader->Draw( m_mergeRt );

	m_nullShader->SetViewport( glm::vec4( 0, 0, m_windowW, m_windowH ) );
	m_nullShader->SetUniform( "in_Texture", m_rt );
	m_nullShader->Draw();

	angle += 5.0f;
	/*m_randX = rand() % 30;
	m_randY = rand() % 30;

	x += m_randX;
	y += m_randY;*/
}

}
