#include <glad/glad.h>

#include "Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "OpenGLWindow.h"
#include "glm/glm.hpp"

#include "Core/Input.h"

#include "Shapes/Shapes.h"

namespace NicoBGameEngine
{
	static bool s_GLFWInitialized = false;
	static void GLFWErrorCallback(int error, const char* description)
	{
		std::cout << "Hello Error " << std::endl;
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new OpenGLWindow(props);
	}

	OpenGLWindow::OpenGLWindow(const WindowProps& props)
		: _camera(glm::vec3(0.0f, 0.0f, 1.0f))
	{
		Init(props);
	}

	OpenGLWindow::~OpenGLWindow()
	{
		Shutdown();
	}

	void OpenGLWindow::Init(const WindowProps& props)
	{
		_data.title = props.title;
		_data.width = props.width;
		_data.height = props.height;

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();

			NB_ASSERTS(success, "Could not initialize GLFW");

			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)props.width, (int)props.height, _data.title.c_str(), nullptr, nullptr);

		_context = GraphicsContext::Create(_window);
		_context->Init();

		_vertexArray.reset(VertexArray::Create());

		float vertices[] = {
			// positions
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f

		};
		unsigned __int32 indices[] = {
			0, 1, 2,
		};

		glfwSetWindowUserPointer(_window, &_data);


		BufferLayout layout =
		{
			{ShaderDataType::Float3,"a_Position"}
		};

		BufferLayout layout2(layout);

		std::shared_ptr<Triangle> t = Triangle::GetTriangle();
		
		_vertexBuffer.reset(VertexBuffer::Create(t->v, t->SizeVertices()));
		_vertexBuffer->SetLayout(layout);

		_vertexArray->AddVertexBuffer(_vertexBuffer);

		_indexBuffer.reset(IndexBuffer::Create(t->i, t->SizeIndices()));
		_vertexArray->SetIndexBuffer(_indexBuffer);


		glBindVertexArray(0);

		std::string vertexSrc = R"(
			#version 330 core
			layout(location = 0) in vec3 a_Position;
			uniform mat4 proj;
			uniform mat4 view;
			uniform mat4 model;
			void main()
			{
				gl_Position =  view * proj *  model * vec4(a_Position,1.0f);
			}

			)";

		std::string fragSrc = R"(
			#version 330 core
			layout(location = 0) out vec4 color;
			void main()
			{
				color = vec4(1.0f,0.0f,0.0f,1.0f);
			}

			)";

		_shader.reset(new OpenGLShader("SimpleShader", vertexSrc, fragSrc));

		int screenWidth;
		int screenHeight;

		glfwGetFramebufferSize(_window, &screenWidth, &screenHeight);

		_screenWidth = (float)screenWidth;
		_screenHeight = (float)screenHeight;

		_lastFrame = 0.0f;
		_deltaTime = 0.0f;
	}

	void OpenGLWindow::Shutdown()
	{
		glfwDestroyWindow(_window);
	}

	void OpenGLWindow::OnUpdate()
	{
		RenderCommand::SetClearColor({ 0.2f, 0.3f, 0.3f, 1.0f });
		RenderCommand::Clear();

		float currentFrame = glfwGetTime();
		_deltaTime = currentFrame - _lastFrame;
		_lastFrame = currentFrame;

		if (NicoBGameEngine::Input::IsKeyPressed(NBGE_KEY_W))
		{
			_camera.ProcessKeyboard(Camera::FORWARD, _deltaTime);
		}
		if (NicoBGameEngine::Input::IsKeyPressed(NBGE_KEY_S))
		{
			_camera.ProcessKeyboard(Camera::BACKWARD, _deltaTime);
		}
		if (NicoBGameEngine::Input::IsKeyPressed(NBGE_KEY_A))
		{
			_camera.ProcessKeyboard(Camera::LEFT, _deltaTime);
		}
		if (NicoBGameEngine::Input::IsKeyPressed(NBGE_KEY_D))
		{
			_camera.ProcessKeyboard(Camera::RIGHT, _deltaTime);
		}

		_projection = glm::perspective(glm::radians(_camera._zoom), (float)_screenWidth / (float)_screenHeight, 0.1f, 100.0f);
		_view = _camera.GetViewMatrix();
		_model = glm::mat4(1.0f);
		_model = glm::translate(_model, glm::vec3(0.0f, 0.0f, -2.0f));

		Renderer::BeginScene();
		_shader->Bind();
		_shader->SetMat4("proj", _projection);
		_shader->SetMat4("model", _model);
		_shader->SetMat4("view", _view);
		Renderer::Submit(_vertexArray);
		Renderer::EndScene();
		_context->SwapBuffers();


	}
}

