#pragma once

#ifdef NB_PLATFORM_WINDOWS

extern NicoBGameEngine::Application* NicoBGameEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = NicoBGameEngine::CreateApplication();
	app->Run();

	delete app;
}

#endif
