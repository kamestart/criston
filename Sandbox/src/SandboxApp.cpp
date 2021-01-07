#include <Criston.h>

class Sandbox : public Criston::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}

};



Criston::Application* Criston::CreateApplication()
{
	return new Sandbox;	
};