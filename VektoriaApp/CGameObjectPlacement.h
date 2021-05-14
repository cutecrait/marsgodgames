#pragma once
#include "Vektoria/root.h"
#include "GameObject.h "

using namespace Vektoria;

class CGameObjectPlacement : public CPlacement
{
public:

    CGameObjectPlacement();
    ~CGameObjectPlacement();

    void Init();

     // Update-Routine pro Tick
    void Update(float deltaTime);

     // Update-Funktion bei Click
    void UpdateOnClick();

    // Gibt Bau-Status aus (Objekt sichtbar auf dem Spielfeld)
    bool getBuildStatus();
    void setBuildStatus(bool);
   
    GameObject* getGameObject();
    void setGameObject(GameObject*);

private:

    GameObject* gameObject;

    // Bau-Status
    bool hasBeenBuild;

};

