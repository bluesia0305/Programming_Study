#include "Framework.h"
#include "Freedom.h"

Freedom::Freedom() : Camera()
{

}

Freedom::~Freedom()
{

}

void Freedom::Update()
{
	if (Mouse::Get()->Press(1) == false) return;

	// Move by relative direction
	Vector3 r = Right();
	Vector3 u = Up();
	Vector3 f = Forward();

	// Move by absolute direction
	//Vector3 r = Vector3(1, 0, 0);
	//Vector3 u = Vector3(0, 1, 0);
	//Vector3 f = Vector3(0, 0, 1);

	// Move
	{
		Vector3 P;
		Position(&P);	// Get position vector

		if (Keyboard::Get()->Press('W'))
			P += CAMERA_TRANSLATION_SPEED * f * move * Time::Delta();
		else if (Keyboard::Get()->Press('S'))
			P -= CAMERA_TRANSLATION_SPEED * f * move * Time::Delta();

		if (Keyboard::Get()->Press('D'))
			P += CAMERA_TRANSLATION_SPEED * r * move * Time::Delta();
		else if (Keyboard::Get()->Press('A'))
			P -= CAMERA_TRANSLATION_SPEED * r * move * Time::Delta();

		if (Keyboard::Get()->Press('E'))
			P += CAMERA_TRANSLATION_SPEED * u * move * Time::Delta();
		else if (Keyboard::Get()->Press('Q'))
			P -= CAMERA_TRANSLATION_SPEED * u * move * Time::Delta();

		Position(P);	// Set position vector
	}

	// Rotation
	{
		Vector3 R;
		Rotation(&R);	// Get rotation vector

		Vector3 val = Mouse::Get()->GetMoveValue();
		R.x += CAMERA_ROTATION_SPEED * val.y * rotation * Time::Delta();	// x-axis rotation
		R.y += CAMERA_ROTATION_SPEED * val.x * rotation * Time::Delta();	// y-axis rotation
		R.z = 0.0f;	// x-axis rotation

		Rotation(R);	// Set rotation vector
	}
}

void Freedom::Speed(float move, float rotation)
{
	this->move = move;
	this->rotation = rotation;
}
