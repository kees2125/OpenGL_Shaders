#pragma once

#include "Movement.h"
#include "Model.h"

class Modelmanager
{
public:
	Modelmanager();
	Movement movement = Movement();
	Model *building;
	std::vector<Model*> previewModels;
	void NextModel();
	void PreviousModel();
	Model* getCurrentModel();
	~Modelmanager();
private:
	int currentModel = 0;
};

