#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"
#include "HelloTriangle.h"

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		// PushLayer(new Sandbox2D());
		PushLayer(new HelloTriangle());
	}

	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
