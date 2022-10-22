#include "GameCamera.h"
#include "../core.h"
#include "../plugin/FableMenu.h"

CCamera* TheCamera = nullptr;

Matrix CCamera::GetMatrix()
{
	return Matrix(up, forward);
}

float CCamera::GetXY()
{
	float v1, v3, result;

	v1 = atan2(this->forward.X, this->forward.Y) * 0.15915494f;
	v3 = v1;
	if (v1 >= 0.0 && v3 < 1.0)
		return v3;
	result = fmod(v3, 1.0);
	if (result < 0.0)
		result = result + 1.0;
	return result;
}

float CCamera::GetYZ()
{
	float v1, v3, result;

	v1 = atan2(this->forward.Z, sqrt(this->forward.X * this->forward.X + this->forward.Y * this->forward.Y)) * 0.15915494f;
	v3 = v1;
	if (v1 >= 0.0 && v3 < 1.0)
		return v3;
	result = fmod(v3, 1.0);
	if (result < 0.0)
		result = result + 1.0;
	return result;
}

void CCamera::PointAt(CVector* pos)
{
	((void(__thiscall*)(CCamera*, CVector*))_addr(0x16B66A0))(this, pos);
}

void CGameCameraManager::Update()
{
	CCamera* cam = (CCamera*)(*(int*)(this + 80) + 4);
	TheCamera = cam;
	if (FableMenu::m_bCustomCameraPos && !FableMenu::ms_bFreeCam)
		cam->pos = TheMenu->camPos;
	else
		TheMenu->camPos = cam->pos;

	if (FableMenu::m_bCustomCameraPos || FableMenu::ms_bFreeCam)
		return;
	
	((void(__thiscall*)(CGameCameraManager*))_addr(0x1B8C140))(this);
}
