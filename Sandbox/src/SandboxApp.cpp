#include <Criston.h>
#include <stdio.h>

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
	printf("New Application Created!");
	return new Sandbox;	
};