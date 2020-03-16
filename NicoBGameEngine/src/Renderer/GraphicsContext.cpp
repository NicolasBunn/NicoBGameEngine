#include "Renderer/GraphicsContext.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace NicoBGameEngine
{
	GraphicsContext* GraphicsContext::Create(void* windows)
	{
		return new OpenGLContext(static_cast<GLFWwindow*>(windows));
	}


}