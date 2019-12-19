#include "HelloTriangle.h"

HelloTriangle::HelloTriangle()
	: Layer("ExampleLayer")
{

}

void HelloTriangle::OnAttach()
{
	std::string shaderPath = "D:/github/Hazel/Sandbox/assets/shaders/";
	mShader = mShaderLibrary.Load("Triangle", shaderPath + "Triangle.glsl");
	
	float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};

	unsigned int indices[] = {  // note that we start from 0!
	0, 1, 3,  // first Triangle
	1, 2, 3   // second Triangle
	};

	mVertexArray = Hazel::VertexArray::Create();
	Hazel::Ref<Hazel::VertexBuffer> vBuffer = Hazel::VertexBuffer::Create(vertices, sizeof(vertices));
	Hazel::BufferElement element(Hazel::ShaderDataType::Float3, "a_Position");
	vBuffer->SetLayout(Hazel::BufferLayout({ element }));
	Hazel::Ref<Hazel::IndexBuffer> iBuffer = Hazel::IndexBuffer::Create(indices, 6);
	mVertexArray->AddVertexBuffer(vBuffer);
	mVertexArray->SetIndexBuffer(iBuffer);

}

void HelloTriangle::OnDetach()
{
}

void HelloTriangle::OnUpdate(Hazel::Timestep ts)
{
	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Hazel::RenderCommand::Clear();

	mShader->Bind();
	mVertexArray->Bind();
	Hazel::RenderCommand::DrawIndexed(mVertexArray);
}

void HelloTriangle::OnImGuiRender()
{
}

void HelloTriangle::OnEvent(Hazel::Event& e)
{
}
