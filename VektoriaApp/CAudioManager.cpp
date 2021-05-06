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
	

	m_zs->AddAudio(&Ambient_Building_Sound);
	m_zs->AddAudio(&Ambient_Background_Music);
	m_zs->AddAudio(&Ambient_Click_Sound);

	Ambient_Background_Music.Loop();
};