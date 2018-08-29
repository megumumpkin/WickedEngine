#pragma once

class wiGUI;
class wiWindow;
class wiLabel;
class wiCheckBox;
class wiSlider;
class wiComboBox;
class wiColorPicker;

class ObjectWindow
{
public:
	ObjectWindow(wiGUI* gui);
	~ObjectWindow();

	wiECS::Entity entity;
	void SetEntity(wiECS::Entity entity);

	wiGUI* GUI;

	wiWindow*	objectWindow;

	wiCheckBox* renderableCheckBox;
	wiSlider*	ditherSlider;
	wiSlider*	cascadeMaskSlider;
	wiColorPicker* colorPicker;

	wiLabel*	physicsLabel;
	wiComboBox*	simulationTypeComboBox;
	wiCheckBox* kinematicCheckBox;
	wiComboBox*	physicsTypeComboBox;
	wiComboBox*	collisionShapeComboBox;
};

