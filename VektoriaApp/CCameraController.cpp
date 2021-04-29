#include "CCameraController.h"

CCameraController::CCameraController()
{

}

CCameraController::CCameraController(CPlacement* placement_camera, CDeviceKeyboard* device_keys, CDeviceMouse* device_mouse)
{
	m_zpcamera = placement_camera;
	m_zdmmouse = device_mouse;
	m_zdkkeys = device_keys;
}

CCameraController::~CCameraController()
{

}

void CCameraController::UpdateCameraMovement(float deltaTime)
{
	Camera_Pos = m_zpcamera->GetPos();
	Camera_Direction = m_zpcamera->GetDirection();

	if (m_zdkkeys->KeyPressed(DIK_W))
	{
		m_zpcamera->TranslateDelta(Camera_Direction.m_fx * deltaTime * TRANSLATEFACTOR, 0, Camera_Direction.m_fz * deltaTime * TRANSLATEFACTOR);
	}

	if (m_zdkkeys->KeyPressed(DIK_S))
	{
		m_zpcamera->TranslateDelta(-Camera_Direction.m_fx * deltaTime * TRANSLATEFACTOR, 0, -Camera_Direction.m_fz * TRANSLATEFACTOR * deltaTime);
	}

	if (m_zdkkeys->KeyPressed(DIK_D))
	{
		m_zpcamera->TranslateDelta(-Camera_Direction.m_fz * deltaTime * TRANSLATEFACTOR, 0, Camera_Direction.m_fx * deltaTime * TRANSLATEFACTOR);
	}

	if (m_zdkkeys->KeyPressed(DIK_A))
	{
		m_zpcamera->TranslateDelta(Camera_Direction.m_fz * deltaTime * TRANSLATEFACTOR, 0, -Camera_Direction.m_fx * deltaTime * TRANSLATEFACTOR);
	}

	if (m_zdmmouse->ButtonPressedRight())
	{
		//m_zpCamera.RotateDelta(-m_zpCamera.GetDirection().GetZ(), 0, m_zpCamera.GetDirection().GetX(), m_zdm.GetRelativeY());
		//m_zpCamera.CopyRotationXDelta(m_zdm.GetRelativeY());
		//m_zpCamera.CopyRotationYDelta(-m_zdm.GetRelativeX());
		//CHVector v = m_zpCamera.GetPos();
		m_zpcamera->TranslateDelta(-Camera_Pos);
		m_zpcamera->RotateDelta(-Camera_Direction.m_fz, 0, Camera_Direction.m_fx, m_zdmmouse->GetRelativeY() * ROTATEFACTOR);
		m_zpcamera->CopyRotationYDelta(-m_zdmmouse->GetRelativeX() * ROTATEFACTOR);
		m_zpcamera->TranslateDelta(Camera_Pos);
		//m_zpCamera.CopyRotationZDelta(0);	
	}

	float m = m_zdmmouse->GetRelativeZ(); //Maus-Rad
	if (m != 0)
	{
		if (m > 0)
			m_zpcamera->TranslateDelta(Camera_Direction * deltaTime * TRANSLATEFACTOR * 100.f);

		else m_zpcamera->TranslateDelta(-Camera_Direction * deltaTime * TRANSLATEFACTOR * 100.f);
	}


	if (Camera_Pos.m_fx > BOUNDARY_X)
	{
		m_zpcamera->CopyTranslationX(BOUNDARY_X);
	}

	if (Camera_Pos.m_fx < -BOUNDARY_X)
	{
		m_zpcamera->CopyTranslationX(-BOUNDARY_X);
	}

	if (Camera_Pos.m_fz > BOUNDARY_Z)
	{
		m_zpcamera->CopyTranslationZ(BOUNDARY_Z);
	}

	if (Camera_Pos.m_fz < -BOUNDARY_Z)
	{
		m_zpcamera->CopyTranslationZ(-BOUNDARY_Z);
	}

	if (Camera_Pos.m_fy < BOUNDARY_Y)
	{
		m_zpcamera->CopyTranslationY(BOUNDARY_Y);
	}

}

void CCameraController::AssignDeviceKeyboard(CDeviceKeyboard* device_keys)
{ 
	m_zdkkeys = device_keys;
}

void CCameraController::AssignDeviceMouse(CDeviceMouse* device_mouse)
{
	m_zdmmouse = device_mouse;
}

void CCameraController::AssignCameraPlacement(CPlacement* camera_placement) 
{
	m_zpcamera = camera_placement;
}

