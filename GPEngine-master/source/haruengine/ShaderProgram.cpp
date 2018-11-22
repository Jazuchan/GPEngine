#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"
#include "RenderTexture.h"

#include <glm/ext.hpp>

#include <fstream>
#include <iostream>

namespace haru
{
ShaderProgram::ShaderProgram( std::string _vert, std::string _frag )
{
	std::ifstream m_file( _vert.c_str() );
	std::string m_vertSrc;

	if(!m_file.is_open())
	{
		throw std::exception();
	}

	while(!m_file.eof())
	{
		std::string m_line;
		std::getline( m_file, m_line );
		m_vertSrc += m_line + "\n";
	}

	m_file.close();
	m_file.open( _frag.c_str() );
	std::string m_fragSrc;

	if(!m_file.is_open())
	{
		throw std::exception();
	}

	while(!m_file.eof())
	{
		std::string m_line;
		std::getline( m_file, m_line );
		m_fragSrc += m_line + "\n";
	}

	const GLchar *m_vs = m_vertSrc.c_str();
	GLuint m_vertexShaderId = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( m_vertexShaderId, 1, &m_vs, NULL );
	glCompileShader( m_vertexShaderId );
	GLint m_success = 0;
	glGetShaderiv( m_vertexShaderId, GL_COMPILE_STATUS, &m_success );

	if(!m_success)
	{
		throw std::exception();
	}

	const GLchar *m_fs = m_fragSrc.c_str();
	GLuint m_fragmentShaderId = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( m_fragmentShaderId, 1, &m_fs, NULL );
	glCompileShader( m_fragmentShaderId );
	glGetShaderiv( m_fragmentShaderId, GL_COMPILE_STATUS, &m_success );

	if(!m_success)
	{
		/*GLint maxLength = 0;
		glGetShaderiv( m_fragmentShaderId, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(m_fragmentShaderId, maxLength, &maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
*/
		throw std::exception();
	}

	m_id = glCreateProgram();
	glAttachShader( m_id, m_vertexShaderId );
	glAttachShader( m_id, m_fragmentShaderId );
	glBindAttribLocation( m_id, 0, "in_Position" );
	glBindAttribLocation( m_id, 1, "in_Color" );
	glBindAttribLocation( m_id, 2, "in_TexCoord" );
	glBindAttribLocation( m_id, 3, "in_Normal" );

	if(glGetError() != GL_NO_ERROR)
	{
		throw std::exception();
	}

	glLinkProgram( m_id );
	glGetProgramiv( m_id, GL_LINK_STATUS, &m_success );

	if(!m_success)
	{
		throw std::exception();
	}

	glDetachShader( m_id, m_vertexShaderId );
	glDeleteShader( m_vertexShaderId );
	glDetachShader( m_id, m_fragmentShaderId );
	glDeleteShader( m_fragmentShaderId );

	m_positions = std::make_shared<VertexBuffer>();
	m_positions->Add( glm::vec2( -1.0f, 1.0f ) );
	m_positions->Add( glm::vec2( -1.0f, -1.0f ) );
	m_positions->Add( glm::vec2( 1.0f, -1.0f ) );
	m_positions->Add( glm::vec2( 1.0f, -1.0f ) );
	m_positions->Add( glm::vec2( 1.0f, 1.0f ) );
	m_positions->Add( glm::vec2( -1.0f, 1.0f ) );
				 
	m_texCoords = std::make_shared<VertexBuffer>();
	m_texCoords->Add( glm::vec2( 0.0f, 0.0f ) );
	m_texCoords->Add( glm::vec2( 0.0f, -1.0f ) );
	m_texCoords->Add( glm::vec2( 1.0f, -1.0f ) );
	m_texCoords->Add( glm::vec2( 1.0f, -1.0f ) );
	m_texCoords->Add( glm::vec2( 1.0f, 0.0f ) );
	m_texCoords->Add( glm::vec2( 0.0f, 0.0f ) );

	m_simpleShape = std::make_shared<VertexArray>();
	m_simpleShape->SetBuffer( "in_Position", m_positions );
	m_simpleShape->SetBuffer( "in_TexCoord", m_texCoords );
}

void ShaderProgram::Draw( std::shared_ptr<RenderTexture> _renderTexture, std::shared_ptr<VertexArray> _vertexArray )
{
	glBindFramebuffer( GL_FRAMEBUFFER, _renderTexture->GetFbId() );
	glm::vec4 m_lastViewport = m_viewport;
	m_viewport = glm::vec4( 0, 0, _renderTexture->GetSize().x, _renderTexture->GetSize().y );
	Draw( _vertexArray );
	m_viewport = m_lastViewport;
	glBindFramebuffer( GL_FRAMEBUFFER, 0 );
}

void ShaderProgram::Draw( std::shared_ptr<RenderTexture> _renderTexture )
{
	Draw( _renderTexture, m_simpleShape );
}

void ShaderProgram::Draw()
{
	Draw( m_simpleShape );
}

void ShaderProgram::Draw( std::shared_ptr<VertexArray> _vertexArray )
{
	glViewport( m_viewport.x, m_viewport.y, m_viewport.z, m_viewport.w );
	glUseProgram( m_id );
	glBindVertexArray( _vertexArray->GetId() );

	for(size_t i = 0; i < m_samplers.size(); i++)
	{
		glActiveTexture( GL_TEXTURE0 + i );

		if(m_samplers.at( i ).m_texture)
		{
			glBindTexture( GL_TEXTURE_2D, m_samplers.at( i ).m_texture->GetId() );
		}
		else
		{
			glBindTexture( GL_TEXTURE_2D, 0 );
		}
	}

	glDrawArrays( GL_TRIANGLES, 0, _vertexArray->GetVertexCount() );

	for(size_t i = 0; i < m_samplers.size(); i++)
	{
		glActiveTexture( GL_TEXTURE0 + i );
		glBindTexture( GL_TEXTURE_2D, 0 );
	}

	glBindVertexArray( 0 );
	glUseProgram( 0 );
}

void ShaderProgram::SetUniform( std::string _uniform, glm::vec4 _value )
{
	GLint m_uniformId = glGetUniformLocation( m_id, _uniform.c_str() );

	if(m_uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram( m_id );
	glUniform4f( m_uniformId, _value.x, _value.y, _value.z, _value.w );
	glUseProgram( 0 );
}

void ShaderProgram::SetUniform( std::string _uniform, float _value )
{
	GLint m_uniformId = glGetUniformLocation( m_id, _uniform.c_str() );

	if(m_uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram( m_id );
	glUniform1f( m_uniformId, _value );
	glUseProgram( 0 );
}

void ShaderProgram::SetUniform( std::string _uniform, int _value )
{
	GLint m_uniformId = glGetUniformLocation( m_id,_uniform.c_str() );

	if(m_uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram( m_id );
	glUniform1i( m_uniformId, _value );
	glUseProgram( 0 );
}

void ShaderProgram::SetUniform( std::string _uniform, glm::mat4 _value )
{
	GLint m_uniformId = glGetUniformLocation( m_id, _uniform.c_str() );

	if(m_uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram( m_id );
	glUniformMatrix4fv( m_uniformId, 1, GL_FALSE, glm::value_ptr( _value ) );
	glUseProgram( 0 );
}

void ShaderProgram::SetUniform( std::string _uniform, std::shared_ptr<Texture> _texture )
{
	GLint m_uniformId = glGetUniformLocation( m_id, _uniform.c_str() );

	if(m_uniformId == -1)
	{
		throw std::exception();
	}

	for(size_t i = 0; i < m_samplers.size(); i++)
	{
		if(m_samplers.at( i ).m_id == m_uniformId)
		{
			m_samplers.at( i ).m_texture = _texture;

			glUseProgram( m_id );
			glUniform1i( m_uniformId, i );
			glUseProgram( 0 );
			return;
		}
	}

	Sampler m_s;
	m_s.m_id = m_uniformId;
	m_s.m_texture = _texture;
	m_samplers.push_back( m_s );

	glUseProgram( m_id );
	glUniform1i( m_uniformId, m_samplers.size() - 1 );
	glUseProgram( 0 );
}

GLuint ShaderProgram::GetId()
{
	return m_id;
}

void ShaderProgram::SetViewport( glm::vec4 _viewport )
{
	this->m_viewport = _viewport;
}
}