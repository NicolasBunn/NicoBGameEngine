#include "Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace NicoBGameEngine
{
	RendererAPI::API RendererAPI::s_RendererAPI = RendererAPI::API::OpenGL;

	RendererAPI* RendererAPI::Create()
	{
		switch (s_RendererAPI)
		{
			case RendererAPI::API::OpenGL:
				return new OpenGLRendererAPI();
				break;
		}

		return nullptr;
	}
}