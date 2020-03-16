#pragma once

#include <string>
#include <unordered_map>

#include <glm/glm.hpp>


namespace NicoBGameEngine
{
	class Shader
	{
		public:
			Shader() {}
			Shader(const std::string& vertexSrc, const std::string& fragSrc);
			virtual ~Shader() {};

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void SetInt(const std::string& name, int value) = 0;
			virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
			virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;
			virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

			virtual const std::string& GetName() const = 0;

			//static Shader* Create(const std::string& filepath);
			//static Shader* Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	};

	class ShaderLibrary
	{
		public:

			void Add(const std::string& name, const Shader* shader);
			void Add(const Shader& shader);

			Shader* Load(const std::string& filepath);
			Shader* Load(const std::string& name, const std::string & filepath);

			std::shared_ptr<Shader> Get(const std::string& name);

			bool Exists(const std::string& name) const;

		private:
			std::unordered_map<std::string, Shader*> _shaders;
	};
}