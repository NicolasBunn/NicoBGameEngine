#include "Buffer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

#include "Renderer/Renderer.h"

namespace NicoBGameEngine
{
	VertexBuffer* VertexBuffer::Create(float* vertices, unsigned __int32 size)
	{
		switch (Renderer::GetApi())
		{
			case RendererAPI::API::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
				break;
		}

		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(unsigned __int32* vertices, unsigned __int32 size)
	{
		switch (Renderer::GetApi())
		{
		case RendererAPI::API::OpenGL:
			return new OpenGLIndexBuffer(vertices, size);
			break;
		}

		return nullptr;
	}
}