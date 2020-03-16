#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace NicoBGameEngine
{
	RendererAPI* RenderCommand::_sRendererAPI = new OpenGLRendererAPI();
}