#pragma once

#include "Hazel.h"

class HelloTriangle : public Hazel::Layer
{
public:
	HelloTriangle();
	virtual ~HelloTriangle() = default;

	// ��ʼ������
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	// ��������
	void OnUpdate(Hazel::Timestep ts) override;
	
	// ���½���
	virtual void OnImGuiRender() override;

	// ��Ӧ�¼�
	void OnEvent(Hazel::Event& e) override;
private:
	Hazel::ShaderLibrary mShaderLibrary;
	Hazel::Ref<Hazel::Shader> mShader;
	Hazel::Ref<Hazel::VertexArray> mVertexArray;
	Hazel::Ref<Hazel::Texture2D> mTexture;
};

