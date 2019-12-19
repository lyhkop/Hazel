#pragma once

#include "Hazel.h"

class HelloTriangle : public Hazel::Layer
{
public:
	HelloTriangle();
	virtual ~HelloTriangle() = default;

	// 初始化函数
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	// 更新数据
	void OnUpdate(Hazel::Timestep ts) override;
	
	// 更新界面
	virtual void OnImGuiRender() override;

	// 响应事件
	void OnEvent(Hazel::Event& e) override;
private:
	Hazel::ShaderLibrary mShaderLibrary;
	Hazel::Ref<Hazel::Shader> mShader;
	Hazel::Ref<Hazel::VertexArray> mVertexArray;
	Hazel::Ref<Hazel::Texture2D> mTexture;
};

