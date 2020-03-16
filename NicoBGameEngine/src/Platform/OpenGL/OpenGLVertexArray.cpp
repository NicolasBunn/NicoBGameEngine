#include "Platform/OpenGL/OpenGLVertexArray.h"

#include <glad/glad.h>

namespace NicoBGameEngine
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return GL_FLOAT;
		case ShaderDataType::Float2:   return GL_FLOAT;
		case ShaderDataType::Float3:   return GL_FLOAT;
		case ShaderDataType::Float4:   return GL_FLOAT;
		case ShaderDataType::Mat3:     return GL_FLOAT;
		case ShaderDataType::Mat4:     return GL_FLOAT;
		case ShaderDataType::Int:      return GL_INT;
		case ShaderDataType::Int2:     return GL_INT;
		case ShaderDataType::Int3:     return GL_INT;
		case ShaderDataType::Int4:     return GL_INT;
		case ShaderDataType::Bool:     return GL_BOOL;
		}

		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &_rendererID);
		glBindVertexArray(_rendererID);
		//glCreateVertexArrays(1, &_rendererID); /// Crash a étudier
		//glCreateBuffers(1, &_rendererID); // Crash a étudier
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &_rendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(_rendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		glBindVertexArray(_rendererID);
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout().GetElements();
		for (const auto& e : layout)
		{
			glEnableVertexAttribArray(_vertexBufferInd);
			glVertexAttribPointer(_vertexBufferInd, e.GetComponentCount(), GL_FLOAT, e._normalized ? GL_TRUE : GL_FALSE, vertexBuffer->GetLayout().GetStride(), (const void*)e._offset);
			_vertexBufferInd++;
		}

		_vertexBuffers.push_back(vertexBuffer);

	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(_rendererID);
		indexBuffer->Bind();

		_indexBuffer = indexBuffer;

	}
}