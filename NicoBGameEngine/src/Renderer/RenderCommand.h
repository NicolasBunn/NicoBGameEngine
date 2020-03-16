#pragma once

#include "Renderer/RendererAPI.h"

namespace NicoBGameEngine
{
	class RenderCommand
	{
		public:

			inline static void SetClearColor(const glm::vec4& color)
			{
				_sRendererAPI->SetClearColor(color);
			}
			
			inline static void Clear()
			{
				_sRendererAPI->Clear();
			}

			inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
			{
				_sRendererAPI->DrawIndexed(vertexArray);
			}

			inline static void DrawArrays(const std::shared_ptr<VertexArray>& vertexArray)
			{
				_sRendererAPI->DrawArrays(vertexArray);
			}


		private:
			static RendererAPI* _sRendererAPI;
	};
}
