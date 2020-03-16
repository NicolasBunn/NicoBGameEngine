#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/Camera.h"
#include "Renderer/GraphicsContext.h"

#include "Renderer/Shader.h"
#include "Renderer/Buffer.h"

#include "Renderer/VertexArray.h"

#include "glm/glm.hpp"

namespace NicoBGameEngine
{
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(const WindowProps& props);
		virtual ~OpenGLWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return _data.width; }
		inline unsigned int GetHeight() const override { return _data.height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override
		{
			_data.eventCallback = callback;
		}

		GraphicsContext* _context;
		Shared<Shader> _shader;
		std::shared_ptr<VertexBuffer> _vertexBuffer;
		std::shared_ptr<IndexBuffer> _indexBuffer;
		std::shared_ptr<VertexArray> _vertexArray;

		std::shared_ptr<Shader> _redShader;
		std::shared_ptr<VertexBuffer> _squareVertexBuffer;
		std::shared_ptr<IndexBuffer> _squareIndexBuffer;

		glm::mat4 _projection;
		glm::mat4 _model;
		glm::mat4 _view;

		float _screenWidth;
		float _screenHeight;

		float _deltaTime;
		float _lastFrame;

		inline virtual void* GetNativeWindow() const { return _window; }

	private:

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		Camera _camera;
		GLFWwindow* _window;

		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			bool VSync;
			EventCallbackFn eventCallback;
		};

		WindowData _data;

		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
	};
}