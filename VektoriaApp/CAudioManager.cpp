#include "CAudioManager.h"

CAudioManager::CAudioManager()
{

};

CAudioManager::~CAudioManager()
{


};

void CAudioManager::Init(CScene* m_zs)
{

	Ambient_Building_Sound.Init("sounds\\Building_Sound.wav");
	
	Ambient_Background_Music.Init("sounds\\Project_Mars_Background_Mono_Edit.wav");
	Ambient_Click_Sound.Init("sounds\\Click_Sound_2_Geschnitten.wav");

	Local_ControlCenter.Init3D("sounds\\ControlCenter_Loop.wav", 1);
	Local_Foundry.Init3D("sounds\\Foundry_Loop.wav", 1);
	Local_Laboratory.Init3D("sounds\\Laboratory_Loop.wav", 1);
	Local_Mine.Init3D("sounds\\Mine_Loop.wav", 1);
	Local_Well.Init3D("sounds\\Well_Loop.wav", 1);
	Local_RobotFactory.Init3D("sounds\\RobotFactory_Loop.wav", 1);
	Local_RobotFactory.SetName("soundGame");
	Local_GravelPlant.Init3D("sounds\\GravelPlant_Loop.wav", 1);
	Local_NuclearPowerPlant.Init3D("sounds\\NuclearPowerPlant_Loop.wav", 1);
	

	m_zs->AddAudio(&Ambient_Building_Sound);
	m_zs->AddAudio(&Ambient_Background_Music);
	m_zs->AddAudio(&Ambient_Click_Sound);

	Ambient_Background_Music.Loop();
};