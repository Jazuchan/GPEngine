#include "VertexArray.h"
#include "VertexBuffer.h"

#include <fstream>
#include <iostream>

namespace haru
{

VertexArray::VertexArray() : m_dirty(false)
{
  glGenVertexArrays(1, &m_id);

  if(!m_id)
  {
    throw std::exception();
  }

  m_buffers.resize(10);
}

void VertexArray::SplitStringWhitespace( std::string& _input, std::vector<std::string>& _output )
{
	std::string m_curr;
	
	_output.clear();

	for(size_t i = 0; i < _input.length(); i++)
	{
		if(_input.at( i ) == ' ' ||
			_input.at( i ) == '\r' ||
			_input.at( i ) == '\n' ||
			_input.at( i ) == '\t')
		{
			if(m_curr.length() > 0)
			{
				_output.push_back( m_curr );
				m_curr = "";
			}
		}
		else
		{
			m_curr += _input.at( i );
		}
	}

	if(m_curr.length() > 0)
	{
		_output.push_back( m_curr );
	}
}

void VertexArray::SplitString( std::string& _input, char _splitter, std::vector<std::string>& _output )
{
	std::string m_curr;
	_output.clear();

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input.at(i) == _splitter)
		{
			_output.push_back( m_curr);
			m_curr = "";
		}
		else
		{
			m_curr += _input.at(i);
		}
	}

	if(m_curr.length() > 0)
	{
		_output.push_back( m_curr );
	}
}

VertexArray::VertexArray( std::string _path ) : m_dirty( false )
{
	glGenVertexArrays( 1, &m_id );

	if(!m_id)
	{
		throw std::exception();
	}

	m_buffers.resize( 10 );
	std::ifstream m_file( _path.c_str() );

	if(!m_file.is_open())
	{
		throw std::exception();
	}

	std::string m_line;
	std::vector<std::string> m_splitLine;
	std::vector<glm::vec3> m_positions;
	std::vector<glm::vec2> m_texCoords;
	std::vector<glm::vec3> m_normals;

	std::shared_ptr<VertexBuffer> m_positionBuffer = NULL;
	std::shared_ptr<VertexBuffer> m_texCoordBuffer = NULL;
	std::shared_ptr<VertexBuffer> m_normalBuffer = NULL;

	while(!m_file.eof())
	{
		std::getline( m_file, m_line );
		if(m_line.length() < 1) continue;
		SplitStringWhitespace( m_line, m_splitLine );
		if(m_splitLine.size() < 1) continue;

		if(m_splitLine.at( 0 ) == "v")
		{
			if(!m_positionBuffer)
			{
				m_positionBuffer = std::make_shared<VertexBuffer>();
			}

			m_positions.push_back( glm::vec3(
			atof( m_splitLine.at( 1 ).c_str()),
			atof( m_splitLine.at( 2 ).c_str()),
			atof( m_splitLine.at( 3 ).c_str())));

		}
		else if(m_splitLine.at( 0 ) == "vt")
		{
			if(!m_texCoordBuffer)
			{
				m_texCoordBuffer = std::make_shared<VertexBuffer>();
			}

			m_texCoords.push_back( glm::vec2(
			atof( m_splitLine.at( 1 ).c_str()),
			1.0f - atof( m_splitLine.at( 2 ).c_str())));
		}
		else if(m_splitLine.at( 0 ) == "vn")
		{
			if(!m_normalBuffer)
			{
				m_normalBuffer = std::make_shared<VertexBuffer>();
			}

			m_normals.push_back( glm::vec3(
			atof( m_splitLine.at( 1 ).c_str()),
			atof( m_splitLine.at( 2 ).c_str()),
			atof( m_splitLine.at( 3 ).c_str())));
		}
		else if(m_splitLine.at( 0 ) == "f")
		{
			std::vector<std::string> m_subsplit;

			SplitString( m_splitLine.at( 1 ), '/', m_subsplit );
			m_positionBuffer->Add( m_positions.at( atoi( m_subsplit.at( 0 ).c_str() ) - 1 ) );
			if(m_texCoordBuffer)
			{
				m_texCoordBuffer->Add( m_texCoords.at( atoi( m_subsplit.at( 1 ).c_str() ) - 1 ) );
			}
			if(m_normalBuffer)
			{
				m_normalBuffer->Add( m_normals.at( atoi( m_subsplit.at( 2 ).c_str() ) - 1 ) );
			}

			SplitString( m_splitLine.at( 2 ), '/', m_subsplit );
			m_positionBuffer->Add( m_positions.at( atoi( m_subsplit.at( 0 ).c_str() ) - 1 ) );
			if(m_texCoordBuffer)
			{
				m_texCoordBuffer->Add( m_texCoords.at( atoi( m_subsplit.at( 1 ).c_str() ) - 1 ) );
			}
			if(m_normalBuffer)
			{
				m_normalBuffer->Add( m_normals.at( atoi( m_subsplit.at( 2 ).c_str() ) - 1 ) );
			}

			SplitString( m_splitLine.at( 3 ), '/', m_subsplit );
			m_positionBuffer->Add( m_positions.at( atoi( m_subsplit.at( 0 ).c_str() ) - 1 ) );
			if(m_texCoordBuffer)
			{
				m_texCoordBuffer->Add( m_texCoords.at( atoi( m_subsplit.at( 1 ).c_str() ) - 1 ) );
			}
			if(m_normalBuffer)
			{
				m_normalBuffer->Add( m_normals.at( atoi( m_subsplit.at( 2 ).c_str() ) - 1 ) );
			}

			if(m_splitLine.size() < 5) continue;

			SplitString( m_splitLine.at( 3 ), '/', m_subsplit );
			m_positionBuffer->Add( m_positions.at( atoi( m_subsplit.at( 0 ).c_str() ) - 1 ) );
			if(m_texCoordBuffer)
			{
				m_texCoordBuffer->Add( m_texCoords.at( atoi( m_subsplit.at( 1 ).c_str() ) - 1 ) );
			}
			if(m_normalBuffer)
			{
				m_normalBuffer->Add( m_normals.at( atoi( m_subsplit.at( 2 ).c_str() ) - 1 ) );
			}

			SplitString( m_splitLine.at( 4 ), '/', m_subsplit );
			m_positionBuffer->Add( m_positions.at( atoi( m_subsplit.at( 0 ).c_str() ) - 1 ) );
			if(m_texCoordBuffer)
			{
				m_texCoordBuffer->Add( m_texCoords.at( atoi( m_subsplit.at( 1 ).c_str() ) - 1 ) );
			}
			if(m_normalBuffer)
			{
				m_normalBuffer->Add( m_normals.at( atoi( m_subsplit.at( 2 ).c_str() ) - 1 ) );
			}

			SplitString( m_splitLine.at( 1 ), '/', m_subsplit );
			m_positionBuffer->Add( m_positions.at( atoi( m_subsplit.at( 0 ).c_str() ) - 1 ) );
			if(m_texCoordBuffer)
			{
				m_texCoordBuffer->Add( m_texCoords.at( atoi( m_subsplit.at( 1 ).c_str() ) - 1 ) );
			}
			if(m_normalBuffer)
			{
				m_normalBuffer->Add( m_normals.at( atoi( m_subsplit.at( 2 ).c_str() ) - 1 ) );
			}
		}
	}

	SetBuffer( "in_Position", m_positionBuffer );
	if(m_texCoordBuffer) SetBuffer( "in_TexCoord", m_texCoordBuffer );
	if(m_normalBuffer) SetBuffer("in_Normal", m_normalBuffer);
}

void VertexArray::SetBuffer(std::string attribute, std::shared_ptr<VertexBuffer> _buffer)
{
  if(attribute == "in_Position")
  {
    m_buffers.at(0) = _buffer;
  }
  else if(attribute == "in_Color")
  {
	m_buffers.at(1) = _buffer;
  }
  else if(attribute == "in_TexCoord")
  {
	m_buffers.at( 2 ) = _buffer;
  }
  else if(attribute == "in_Normal")
  {
	m_buffers.at( 3 ) = _buffer;
  }
  else
  {
    throw std::exception();
  }

  m_dirty = true;
}

int VertexArray::GetVertexCount()
{
  if(!m_buffers.at(0))
  {
    throw std::exception();
  }

  return m_buffers.at(0)->GetDataSize() / m_buffers.at(0)->GetComponents();
}

GLuint VertexArray::GetId()
{
  if(m_dirty)
  {
    glBindVertexArray(m_id);

    for(size_t i = 0; i < m_buffers.size(); i++)
    {
      if(m_buffers.at(i))
      {
        glBindBuffer(GL_ARRAY_BUFFER, m_buffers.at(i)->GetId());

        glVertexAttribPointer(i, m_buffers.at(i)->GetComponents(), GL_FLOAT, GL_FALSE,
          m_buffers.at(i)->GetComponents() * sizeof(GLfloat), (void *)0);

        glEnableVertexAttribArray(i);
      }
      else
      {
        glDisableVertexAttribArray(i);
      }
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    m_dirty = false;
  }

  return m_id;
}

}
