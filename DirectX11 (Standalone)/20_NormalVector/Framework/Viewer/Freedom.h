#pragma once
#include "Camera.h"

#define CAMERA_TRANSLATION_SPEED	2.5f
#define CAMERA_ROTATION_SPEED		1.5f

class Freedom : public Camera
{
public:
	Freedom();
	~Freedom();

	void Update() override;
	void Speed(float move, float rotation = 2.0f);

private:
	float move = 20.0f;
	float rotation = 2.0f;
};