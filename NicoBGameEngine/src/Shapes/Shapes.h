#pragma once

#include <memory>

namespace NicoBGameEngine
{
	class Triangle
	{
	public:
		unsigned __int32 i[3];
		float v[9];

		Triangle();

		static std::shared_ptr<Triangle> GetTriangle();

		unsigned int SizeVertices() const;
		unsigned int SizeIndices() const;
	};
}

