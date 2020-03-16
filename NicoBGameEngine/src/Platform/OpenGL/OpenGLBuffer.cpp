#include "Platform/OpenGL/OpenGLBuffer.h"

#include <glad/glad.h>

namespace NicoBGameEngine
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, unsigned __int32 size)
	{
		unsigned __int32 vbo;

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); 
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &_vao);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindVertexArray(_vao);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned __int32* indices, unsigned __int32 count)
		: _count(count)
	{
		glGenBuffers(1, &_ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned __int32) * sizeof(indices), indices, GL_STATIC_DRAW);

	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &_ebo);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}