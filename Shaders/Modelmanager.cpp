#include "Modelmanager.h"



Modelmanager::Modelmanager()
{
}

void Modelmanager::NextModel()
{
	currentModel = (currentModel + 1) % previewModels.size();
}

void Modelmanager::PreviousModel()
{
	currentModel = (currentModel + previewModels.size() - 1) % previewModels.size();
}

Model * Modelmanager::getCurrentModel()
{
	return previewModels[currentModel];
}

Modelmanager::~Modelmanager()
{
}