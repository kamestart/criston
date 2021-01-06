#pragma once


#ifdef CRISTON_PLATFORM_WINDOWS
	
extern Criston::Application* Criston::CreateApplication();

int main(int argc, char** argv)
{
	Criston::Log::Init();
	CS_CORE_WARN("Initialized Logging!");
	int a = 5;
	CS_CLIENT_INFO("Hello! var={0}", a);

	auto app = Criston::CreateApplication();
	app->Run();
	delete app;
}

#endif