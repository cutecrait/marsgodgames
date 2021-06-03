#pragma once
#include "Vektoria\root.h"

using namespace Vektoria;

class GameObject
{
public:
	
	struct Ressources_Data {
		
		// Noch zu erweitern mit den anderen Ressourcen

		// Baukosten
		int Sauerstoff_per_Build;
		int Stein_per_Build;
		int Strom_per_Build;

		// Verbrauch von Ressourcen pro Zeiteinheit
		float Sauerstoff_Use_per_Unit;
		float Stein_Use_per_Unit;
		float Strom_Use_per_Unit;

		// Gewinn von Ressourcen pro Zeiteinheit
		float Sauerstoff_Gain_per_Unit;
		float Stein_Gain_per_Unit;
		float Strom_Gain_per_Unit;

	};

	struct Resources {
		int Steel = 0;
		int Concrete = 0;
		int Wood = 0;
	};

	//Aufbau der GameObjects

	GameObject();
	~GameObject();

	CGeo* getModel() { return m_model; }
	CMaterial* getMaterial() {return &m_material;}
	CFileWavefront getPfad() { return m_modelPfad; }

	int getRes1() { return m_res1; }
	int getRes2() { return m_res2; }
	int getRes3() { return m_res3; }

	// Gibt struct aus, der die Ressourcen Informationen enthält
	// Momentan bitte nicht verwenden. Die Ressourcen kommen in die jeweiligen Buildings rein. 
	// Andere GameObjects kosten erstmal nichts.
	virtual Resources getRessources() { return ressis; }

	// Initialiserungmethode der GameObjects
	virtual void Init(char* model, char* material, int, int, int);

	// Update-Methode pro Tick
	virtual void Update(float);

	// Berechnet die Höhe, um auf dem Spielfeld komplett sichtbar zu sein
	float CalculateHeight();

	void TransformGeo();

	// Setzt die Geometrie
	void setModel(char*);

	// Setzt die Textur
	void setMaterial(char* );

private:
	
	CGeo* m_model;
	CFileWavefront m_modelPfad;
	CMaterial m_material;

	

protected:

	
	Resources ressis;

	int m_res1;
	int m_res2;
	int m_res3;
	
};

