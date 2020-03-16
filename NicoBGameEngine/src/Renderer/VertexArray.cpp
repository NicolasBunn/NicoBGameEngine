#include "Renderer/VertexArray.h"

#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace NicoBGameEngine
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetApi())
		{
			case RendererAPI::API::OpenGL:
				return new OpenGLVertexArray();
		}

		return nullptr;
	}


}