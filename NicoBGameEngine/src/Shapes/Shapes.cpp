#include "Shapes.h"

namespace NicoBGameEngine
{
	std::shared_ptr<Triangle> Triangle::GetTriangle()
	{
		return std::shared_ptr<Triangle>(new Triangle());
	}

	Triangle::Triangle()
	{
		v[0] = 0.5f; v[1] = -0.5f; v[2] = 0.0f;
		v[3] = -0.5f; v[4] = -0.5f; v[5] = 0.0f;
		v[6] = 0.0f; v[7] = 0.5f; v[8] = 0.0f;

		i[0] = 0; i[1] = 1; i[2] = 2;

	}

	unsigned int Triangle::SizeVertices() const
	{
		return sizeof(float) * 9;
	}

	unsigned int Triangle::SizeIndices() const
	{
		return sizeof(int) * 3;
	}
}


