#include "Camera.h"
#include <glad/glad.h>

namespace NicoBGameEngine
{
	const float Camera::YAW = -90.0f;
	const float Camera::PITCH = 0.0f;
	const float Camera::SPEED = 2.5f;
	const float Camera::SENSITIVITY = 0.1f;
	const float Camera::ZOOM = 45.0f;

	Camera::Camera(glm::vec3 position, 
		glm::vec3 up, 
		float yaw, 
		float pitch)
		: _front(glm::vec3(0.0f, 0.0f, -1.0f)), _movementSpeed(SPEED),_mouseSensitivity(SENSITIVITY),_zoom(ZOOM)
	{
		_position = position;
		_worldUp = up;
		_yaw = yaw;
		_pitch = pitch;
		UpdateCameraVectors();
	}

	Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
		: _front(glm::vec3(0.0f, 0.0f, -1.0f)), _movementSpeed(SPEED), _mouseSensitivity(SENSITIVITY),_zoom(ZOOM)
	{
		_position = glm::vec3(posX, posY, posZ);
		_worldUp = glm::vec3(upX, upY, upZ);
		_yaw = yaw;
		_pitch = pitch;
		UpdateCameraVectors();
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(_position, _position + _front, _up);
		//return glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f) + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	void Camera::ProcessKeyboard(CameraMovement direction, float deltaTime)
	{
		float velocity = _movementSpeed * deltaTime;

		switch (direction)
		{
			case FORWARD:
				_position += _front * velocity;
				break;
			case BACKWARD:
				_position -= _front * velocity;
				break;
			case LEFT:
				_position -= _right * velocity;
				break;
			case RIGHT:
				_position += _right * velocity;
				break;
		}
	}

	void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
	{
		xoffset *= _mouseSensitivity;
		yoffset *= _mouseSensitivity;

		_yaw += xoffset;
		_pitch += yoffset;

		if(constrainPitch)
		{
			if (_pitch > 89.0f)
				_pitch = 89.0f;
			if (_pitch < -89.0f)
				_pitch = -89.0f;
		}

		UpdateCameraVectors();
	}

	void Camera::ProcessMouseScroll(float yoffset)
	{
		if (_zoom >= 1.0f && _zoom <= 45.0f)
			_zoom -= yoffset;
		if (_zoom <= 1.0f)
			_zoom = 1.0f;
		if (_zoom >= 45.0f)
			_zoom = 45.0f;
	}

	void Camera::UpdateCameraVectors()
	{
		glm::vec3 frontCompute;
		frontCompute.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		frontCompute.y = sin(glm::radians(_pitch));
		frontCompute.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		_front = glm::normalize(frontCompute);
		_right = glm::normalize(glm::cross(_front, _worldUp));
		_up = glm::normalize(glm::cross(_right, _front));
	}
}