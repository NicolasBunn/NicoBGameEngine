#pragma once

#include <string>
#include <vector>

namespace NicoBGameEngine
{
	enum class ShaderDataType
	{
		None = 0, 
		Float, Float2, Float3, Float4,
		Mat3,Mat4,
		Int, Int2,Int3, Int4, Bool
	};

	static unsigned __int32 ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:    return 4;
			case ShaderDataType::Float2:   return 4 * 2;
			case ShaderDataType::Float3:   return 4 * 3;
			case ShaderDataType::Float4:   return 4 * 4;
			case ShaderDataType::Mat3:     return 4 * 3 * 3;
			case ShaderDataType::Mat4:     return 4 * 4 * 4;
			case ShaderDataType::Int:      return 4;
			case ShaderDataType::Int2:     return 4 * 2;
			case ShaderDataType::Int3:     return 4 * 3;
			case ShaderDataType::Int4:     return 4 * 4;
			case ShaderDataType::Bool:     return 1;
		}

		return 0;
	}

	struct BufferElement
	{
		std::string _name;
		ShaderDataType _type;
		unsigned __int32 _size;
		unsigned __int32 _offset;
		bool _normalized;

		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: _name(name),_type(type),_size(ShaderDataTypeSize(type)),_offset(0),_normalized(normalized)
		{

		}

		uint32_t GetComponentCount() const
		{
			switch (_type)
			{
				case ShaderDataType::Float:   return 1;
				case ShaderDataType::Float2:  return 2;
				case ShaderDataType::Float3:  return 3;
				case ShaderDataType::Float4:  return 4;
				case ShaderDataType::Mat3:    return 3 * 3;
				case ShaderDataType::Mat4:    return 4 * 4;
				case ShaderDataType::Int:     return 1;
				case ShaderDataType::Int2:    return 2;
				case ShaderDataType::Int3:    return 3;
				case ShaderDataType::Int4:    return 4;
				case ShaderDataType::Bool:    return 1;
			}

			return 0;
		}
	};

	class BufferLayout
	{
		public:

			BufferLayout() {}

			BufferLayout(const std::initializer_list<BufferElement>& element)
				:_elements(element)
			{
				CalculateOffsetsAndStride();
			}

			inline const std::vector<BufferElement>& GetElements() const
			{
				return _elements;
			}

			inline 	unsigned __int32 GetStride() const
			{
				return _stride;
			}

		private:

			void CalculateOffsetsAndStride()
			{
				size_t offset = 0;
				_stride = 0;
				for (auto& element : _elements)
				{
					element._offset = offset;
					offset += element._size;
					_stride += element._size;
				}
			}

			std::vector<BufferElement> _elements;
			unsigned __int32 _stride;
	};

	class VertexBuffer
	{
		public:
			virtual ~VertexBuffer() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual const BufferLayout& GetLayout() const = 0;
			virtual void SetLayout(const BufferLayout& layout) = 0;

			static VertexBuffer* Create(float* vertices, unsigned __int32 size);
	


	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned __int32 GetCount() const = 0;

		static IndexBuffer* Create(unsigned __int32* vertices, unsigned __int32 size);
	};


}
