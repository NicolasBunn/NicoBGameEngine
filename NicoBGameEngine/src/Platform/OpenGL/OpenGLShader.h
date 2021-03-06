#pragma once

#include "Renderer/Shader.h"
#include "Core/Core.h"
#include <glm/glm.hpp>

namespace NicoBGameEngine
{
	class OpenGLShader : public Shader
	{
		public:
			OpenGLShader() {}
			OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);

			virtual ~OpenGLShader();

			virtual void Bind() const override;
			virtual void Unbind() const override;

			virtual void SetInt(const std::string& name, int value) override;
			virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
			virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
			virtual void SetMat4(const std::string& name, const glm::mat4& value) override;

			virtual const std::string& GetName() const override {
				return _name;
			}

			void UploadUniformInt(const std::string& name, int value);
			void UploadUniformFloat(const std::string& name, float value);
			void UploadUniformFloat2(const std::string& name, const glm::vec2& value);
			void UploadUniformFloat3(const std::string& name, const glm::vec3& value);
			void UploadUniformFloat4(const std::string& name, const glm::vec4& value);

			void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
			void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);

			unsigned __int32 _rendererId;
			std::string _name;

	};



}