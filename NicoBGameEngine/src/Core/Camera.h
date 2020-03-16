#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace NicoBGameEngine
{
	class Camera
	{
		public:

			static const float YAW;
			static const float PITCH;
			static const float SPEED;
			static const float SENSITIVITY;
			static const float ZOOM;

			enum CameraMovement
			{
				FORWARD,
				BACKWARD,
				LEFT,
				RIGHT
			};

			glm::vec3 _position;
			glm::vec3 _front;
			glm::vec3 _up;
			glm::vec3 _right;
			glm::vec3 _worldUp;

			float _yaw;
			float _pitch;
			float _movementSpeed;
			float _mouseSensitivity;
			float _zoom;

			Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
					glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
					float yaw = YAW, float pitch = PITCH);
			Camera(float posX, float posY, float posZ, float upX, float upY,float upZ, float yaw, float pitch);
			glm::mat4 GetViewMatrix() const;
			void ProcessKeyboard(CameraMovement direction, float deltaTime);
			void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
			void ProcessMouseScroll(float yoffset);
			void UpdateCameraVectors();


	};

}