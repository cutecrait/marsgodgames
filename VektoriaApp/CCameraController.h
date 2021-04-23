#pragma once

#include "Vektoria\Root.h"
using namespace Vektoria;
using namespace std;

#define TRANSLATEFACTOR 3.0f
#define ROTATEFACTOR 1.0f
#define BOUNDARY_X 15.0f
#define BOUNDARY_Y 0
#define BOUNDARY_Z 15.0f

class CCameraController
{
	public:

	CCameraController();
	CCameraController(CPlacement* placement_camera, CDeviceKeyboard* device_keys, CDeviceMouse* device_mouse);
	~CCameraController();

	void UpdateCameraMovement(float deltaTime);

	void AssignDeviceKeyboard(CDeviceKeyboard* device_keys);
	void AssignDeviceMouse(CDeviceMouse* device_mouse);
	void AssignCameraPlacement(CPlacement* placement_camera);


private:

	CDeviceKeyboard* m_zdkkeys;
	CDeviceMouse* m_zdmmouse;
	CPlacement* m_zpcamera;
	CHVector Camera_Pos;
	CHVector Camera_Direction;

};

