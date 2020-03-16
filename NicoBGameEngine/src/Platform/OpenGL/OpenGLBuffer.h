#pragma once

#include "Renderer/Buffer.h"

namespace NicoBGameEngine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, unsigned __int32 size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		
		virtual const BufferLayout& GetLayout() const override
		{
			return _layout;
		}

		virtual void SetLayout(const BufferLayout& layout) override
		{
			_layout = layout;
		}

		unsigned __int32 _vao;
		BufferLayout _layout;


	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
		public:
			OpenGLIndexBuffer(unsigned __int32* indices, unsigned __int32 count);
			virtual ~OpenGLIndexBuffer();

			virtual void Bind() const override;
			virtual void Unbind() const override;

			unsigned __int32 GetCount() const override { return _count; }

			unsigned __int32 _ebo;
			unsigned __int32 _count;


	};
}
