#include "NicoBGameEngine.h"

class Sandbox : public NicoBGameEngine::Application
{
	public:

		Sandbox()
		{

		}

		~Sandbox()
		{

		}
};

NicoBGameEngine::Application* NicoBGameEngine::CreateApplication()
{
	return new Sandbox();
}
