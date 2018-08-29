#include "stdafx.h"
#include "MaterialWindow.h"

#include <Commdlg.h> // openfile
#include <WinBase.h>

using namespace std;
using namespace wiGraphicsTypes;
using namespace wiECS;
using namespace wiSceneSystem;

MaterialWindow::MaterialWindow(wiGUI* gui) : GUI(gui)
{
	assert(GUI && "Invalid GUI!");

	float screenW = (float)wiRenderer::GetDevice()->GetScreenWidth();
	float screenH = (float)wiRenderer::GetDevice()->GetScreenHeight();

	materialWindow = new wiWindow(GUI, "Material Window");
	materialWindow->SetSize(XMFLOAT2(760, 700));
	materialWindow->SetEnabled(false);
	GUI->AddWidget(materialWindow);

	//materialNameField = new wiTextInputField("MaterialName");
	//materialNameField->SetPos(XMFLOAT2(10, 30));
	//materialNameField->SetSize(XMFLOAT2(300, 20));
	//materialNameField->OnInputAccepted([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->name = args.sValue;
	//});
	//materialWindow->AddWidget(materialNameField);

	//float x = 540, y = 0;
	//float step = 35;

	//waterCheckBox = new wiCheckBox("Water: ");
	//waterCheckBox->SetTooltip("Set material as special water material.");
	//waterCheckBox->SetPos(XMFLOAT2(570, y += step));
	//waterCheckBox->OnClick([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->water = args.bValue;
	//});
	//materialWindow->AddWidget(waterCheckBox);

	//planarReflCheckBox = new wiCheckBox("Planar Reflections: ");
	//planarReflCheckBox->SetTooltip("Enable planar reflections. The mesh should be a single plane for best results.");
	//planarReflCheckBox->SetPos(XMFLOAT2(570, y += step));
	//planarReflCheckBox->OnClick([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->planar_reflections = args.bValue;
	//});
	//materialWindow->AddWidget(planarReflCheckBox);

	//shadowCasterCheckBox = new wiCheckBox("Cast Shadow: ");
	//shadowCasterCheckBox->SetTooltip("The subset will contribute to the scene shadows if enabled.");
	//shadowCasterCheckBox->SetPos(XMFLOAT2(570, y += step));
	//shadowCasterCheckBox->OnClick([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->cast_shadow = args.bValue;
	//});
	//materialWindow->AddWidget(shadowCasterCheckBox);

	//normalMapSlider = new wiSlider(0, 4, 1, 4000, "Normalmap: ");
	//normalMapSlider->SetTooltip("How much the normal map should distort the face normals (bumpiness).");
	//normalMapSlider->SetSize(XMFLOAT2(100, 30));
	//normalMapSlider->SetPos(XMFLOAT2(x, y += step));
	//normalMapSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->normalMapStrength = args.fValue;
	//});
	//materialWindow->AddWidget(normalMapSlider);

	//roughnessSlider = new wiSlider(0, 1, 0.5f, 1000, "Roughness: ");
	//roughnessSlider->SetTooltip("Adjust the surface roughness. Rough surfaces are less shiny, more matte.");
	//roughnessSlider->SetSize(XMFLOAT2(100, 30));
	//roughnessSlider->SetPos(XMFLOAT2(x, y += step));
	//roughnessSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->roughness = args.fValue;
	//});
	//materialWindow->AddWidget(roughnessSlider);

	//reflectanceSlider = new wiSlider(0, 1, 0.5f, 1000, "Reflectance: ");
	//reflectanceSlider->SetTooltip("Adjust the overall surface reflectivity.");
	//reflectanceSlider->SetSize(XMFLOAT2(100, 30));
	//reflectanceSlider->SetPos(XMFLOAT2(x, y += step));
	//reflectanceSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->reflectance = args.fValue;
	//});
	//materialWindow->AddWidget(reflectanceSlider);

	//metalnessSlider = new wiSlider(0, 1, 0.0f, 1000, "Metalness: ");
	//metalnessSlider->SetTooltip("The more metal-like the surface is, the more the its color will contribute to the reflection color.");
	//metalnessSlider->SetSize(XMFLOAT2(100, 30));
	//metalnessSlider->SetPos(XMFLOAT2(x, y += step));
	//metalnessSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->metalness = args.fValue;
	//});
	//materialWindow->AddWidget(metalnessSlider);

	//alphaSlider = new wiSlider(0, 1, 1.0f, 1000, "Alpha: ");
	//alphaSlider->SetTooltip("Adjusts the overall transparency of the surface.");
	//alphaSlider->SetSize(XMFLOAT2(100, 30));
	//alphaSlider->SetPos(XMFLOAT2(x, y += step));
	//alphaSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->alpha = args.fValue;
	//});
	//materialWindow->AddWidget(alphaSlider);

	//alphaRefSlider = new wiSlider(0, 1, 1.0f, 1000, "AlphaRef: ");
	//alphaRefSlider->SetTooltip("Adjust the alpha cutoff threshold. This disables some optimizations so performance can be affected.");
	//alphaRefSlider->SetSize(XMFLOAT2(100, 30));
	//alphaRefSlider->SetPos(XMFLOAT2(x, y += step));
	//alphaRefSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->alphaRef = args.fValue;
	//});
	//materialWindow->AddWidget(alphaRefSlider);

	//refractionIndexSlider = new wiSlider(0, 1.0f, 0.02f, 1000, "Refraction Index: ");
	//refractionIndexSlider->SetTooltip("Adjust the IOR (index of refraction). It controls the amount of distortion of the scene visible through the transparent object.");
	//refractionIndexSlider->SetSize(XMFLOAT2(100, 30));
	//refractionIndexSlider->SetPos(XMFLOAT2(x, y += step));
	//refractionIndexSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->refractionIndex = args.fValue;
	//});
	//materialWindow->AddWidget(refractionIndexSlider);

	//emissiveSlider = new wiSlider(0, 1, 0.0f, 1000, "Emissive: ");
	//emissiveSlider->SetTooltip("Adjust the light emission of the surface. The color of the light emitted is that of the color of the material.");
	//emissiveSlider->SetSize(XMFLOAT2(100, 30));
	//emissiveSlider->SetPos(XMFLOAT2(x, y += step));
	//emissiveSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->emissive = args.fValue;
	//});
	//materialWindow->AddWidget(emissiveSlider);

	//sssSlider = new wiSlider(0, 1, 0.0f, 1000, "Subsurface Scattering: ");
	//sssSlider->SetTooltip("Adjust how much the light is scattered when entered inside the surface of the object. (SSS postprocess must be enabled)");
	//sssSlider->SetSize(XMFLOAT2(100, 30));
	//sssSlider->SetPos(XMFLOAT2(x, y += step));
	//sssSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->subsurfaceScattering = args.fValue;
	//});
	//materialWindow->AddWidget(sssSlider);

	//pomSlider = new wiSlider(0, 0.1f, 0.0f, 1000, "Parallax Occlusion Mapping: ");
	//pomSlider->SetTooltip("Adjust how much the bump map should affect the object (slow).");
	//pomSlider->SetSize(XMFLOAT2(100, 30));
	//pomSlider->SetPos(XMFLOAT2(x, y += step));
	//pomSlider->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->parallaxOcclusionMapping = args.fValue;
	//});
	//materialWindow->AddWidget(pomSlider);

	//movingTexSliderU = new wiSlider(-0.05f, 0.05f, 0, 1000, "Texcoord anim U: ");
	//movingTexSliderU->SetTooltip("Adjust the texture animation speed along the U direction in texture space.");
	//movingTexSliderU->SetSize(XMFLOAT2(100, 30));
	//movingTexSliderU->SetPos(XMFLOAT2(x, y += step));
	//movingTexSliderU->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->movingTex.x = args.fValue;
	//});
	//materialWindow->AddWidget(movingTexSliderU);

	//movingTexSliderV = new wiSlider(-0.05f, 0.05f, 0, 1000, "Texcoord anim V: ");
	//movingTexSliderV->SetTooltip("Adjust the texture animation speed along the V direction in texture space.");
	//movingTexSliderV->SetSize(XMFLOAT2(100, 30));
	//movingTexSliderV->SetPos(XMFLOAT2(x, y += step));
	//movingTexSliderV->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->movingTex.y = args.fValue;
	//});
	//materialWindow->AddWidget(movingTexSliderV);

	//texMulSliderX = new wiSlider(0.01f, 10.0f, 0, 1000, "Texture TileSize X: ");
	//texMulSliderX->SetTooltip("Adjust the texture mapping size.");
	//texMulSliderX->SetSize(XMFLOAT2(100, 30));
	//texMulSliderX->SetPos(XMFLOAT2(x, y += step));
	//texMulSliderX->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->texMulAdd.x = args.fValue;
	//});
	//materialWindow->AddWidget(texMulSliderX);

	//texMulSliderY = new wiSlider(0.01f, 10.0f, 0, 1000, "Texture TileSize Y: ");
	//texMulSliderY->SetTooltip("Adjust the texture mapping size.");
	//texMulSliderY->SetSize(XMFLOAT2(100, 30));
	//texMulSliderY->SetPos(XMFLOAT2(x, y += step));
	//texMulSliderY->OnSlide([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->texMulAdd.y = args.fValue;
	//});
	//materialWindow->AddWidget(texMulSliderY);


	//colorPicker = new wiColorPicker(GUI, "Material Color");
	//colorPicker->SetPos(XMFLOAT2(10, 400));
	//colorPicker->RemoveWidgets();
	//colorPicker->SetVisible(true);
	//colorPicker->SetEnabled(true);
	//colorPicker->OnColorChanged([&](wiEventArgs args) {
	//	if (material != nullptr)
	//		material->baseColor = XMFLOAT3(powf(args.color.x, 1.f / 2.2f), powf(args.color.y, 1.f / 2.2f), powf(args.color.z, 1.f / 2.2f));
	//});
	//materialWindow->AddWidget(colorPicker);


	//blendModeComboBox = new wiComboBox("Blend mode: ");
	//blendModeComboBox->SetPos(XMFLOAT2(x, y += step));
	//blendModeComboBox->SetSize(XMFLOAT2(100, 25));
	//blendModeComboBox->OnSelect([&](wiEventArgs args) {
	//	if (material != nullptr && args.iValue >= 0)
	//	{
	//		material->blendFlag = static_cast<BLENDMODE>(args.iValue);
	//	}
	//});
	//blendModeComboBox->AddItem("Opaque");
	//blendModeComboBox->AddItem("Alpha");
	//blendModeComboBox->AddItem("Premultiplied");
	//blendModeComboBox->AddItem("Additive");
	//blendModeComboBox->SetEnabled(false);
	//blendModeComboBox->SetTooltip("Set the blend mode of the material.");
	//materialWindow->AddWidget(blendModeComboBox);


	//shaderTypeComboBox = new wiComboBox("Custom Shader: ");
	//shaderTypeComboBox->SetPos(XMFLOAT2(x, y += step));
	//shaderTypeComboBox->SetSize(XMFLOAT2(100, 25));
	//shaderTypeComboBox->OnSelect([&](wiEventArgs args) {
	//	if (material != nullptr)
	//	{
	//		if (args.iValue == 0)
	//		{
	//			material->customShader = nullptr;
	//		}
	//		else if (args.iValue > 0)
	//		{
	//			material->customShader = Material::customShaderPresets[args.iValue - 1];
	//		}
	//	}
	//});
	//shaderTypeComboBox->AddItem("None");
	//for (auto& x : Material::customShaderPresets)
	//{
	//	shaderTypeComboBox->AddItem(x->name);
	//}
	//shaderTypeComboBox->SetEnabled(false);
	//shaderTypeComboBox->SetTooltip("Set the custom shader of the material.");
	//materialWindow->AddWidget(shaderTypeComboBox);


	//// Textures:

	//x = 10;
	//y = 60;

	//texture_baseColor_Label = new wiLabel("BaseColorMap: ");
	//texture_baseColor_Label->SetPos(XMFLOAT2(x, y += step));
	//texture_baseColor_Label->SetSize(XMFLOAT2(120, 20));
	//materialWindow->AddWidget(texture_baseColor_Label);

	//texture_baseColor_Button = new wiButton("BaseColor");
	//texture_baseColor_Button->SetText("");
	//texture_baseColor_Button->SetTooltip("Load the basecolor texture. RGB: Albedo Base Color, A: Opacity");
	//texture_baseColor_Button->SetPos(XMFLOAT2(x + 122, y));
	//texture_baseColor_Button->SetSize(XMFLOAT2(260, 20));
	//texture_baseColor_Button->OnClick([&](wiEventArgs args) {
	//	if (material == nullptr)
	//		return;

	//	if (material->texture != nullptr)
	//	{
	//		material->texture = nullptr;
	//		material->textureName = "";
	//		texture_baseColor_Button->SetText("");
	//	}
	//	else
	//	{
	//		char szFile[260];

	//		OPENFILENAMEA ofn;
	//		ZeroMemory(&ofn, sizeof(ofn));
	//		ofn.lStructSize = sizeof(ofn);
	//		ofn.hwndOwner = nullptr;
	//		ofn.lpstrFile = szFile;
	//		// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	//		// use the contents of szFile to initialize itself.
	//		ofn.lpstrFile[0] = '\0';
	//		ofn.nMaxFile = sizeof(szFile);
	//		ofn.lpstrFilter = "Texture\0*.dds;*.png;*.jpg;*.tga;\0";
	//		ofn.nFilterIndex = 1;
	//		ofn.lpstrFileTitle = NULL;
	//		ofn.nMaxFileTitle = 0;
	//		ofn.lpstrInitialDir = NULL;
	//		ofn.Flags = 0;
	//		if (GetSaveFileNameA(&ofn) == TRUE) {
	//			string fileName = ofn.lpstrFile;
	//			material->texture = (Texture2D*)wiResourceManager::GetGlobal()->add(fileName);
	//			material->textureName = fileName;
	//			texture_baseColor_Button->SetText(wiHelper::GetFileNameFromPath(material->textureName));
	//		}
	//	}
	//});
	//materialWindow->AddWidget(texture_baseColor_Button);



	//texture_normal_Label = new wiLabel("NormalMap: ");
	//texture_normal_Label->SetPos(XMFLOAT2(x, y += step));
	//texture_normal_Label->SetSize(XMFLOAT2(120, 20));
	//materialWindow->AddWidget(texture_normal_Label);

	//texture_normal_Button = new wiButton("NormalMap");
	//texture_normal_Button->SetText("");
	//texture_normal_Button->SetTooltip("Load the normalmap texture. RGB: Normal, A: Roughness");
	//texture_normal_Button->SetPos(XMFLOAT2(x + 122, y));
	//texture_normal_Button->SetSize(XMFLOAT2(260, 20));
	//texture_normal_Button->OnClick([&](wiEventArgs args) {
	//	if (material == nullptr)
	//		return;

	//	if (material->normalMap != nullptr)
	//	{
	//		material->normalMap = nullptr;
	//		material->normalMapName = "";
	//		texture_normal_Button->SetText("");
	//	}
	//	else
	//	{
	//		char szFile[260];

	//		OPENFILENAMEA ofn;
	//		ZeroMemory(&ofn, sizeof(ofn));
	//		ofn.lStructSize = sizeof(ofn);
	//		ofn.hwndOwner = nullptr;
	//		ofn.lpstrFile = szFile;
	//		// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	//		// use the contents of szFile to initialize itself.
	//		ofn.lpstrFile[0] = '\0';
	//		ofn.nMaxFile = sizeof(szFile);
	//		ofn.lpstrFilter = "Texture\0*.dds;*.png;*.jpg;*.tga;\0";
	//		ofn.nFilterIndex = 1;
	//		ofn.lpstrFileTitle = NULL;
	//		ofn.nMaxFileTitle = 0;
	//		ofn.lpstrInitialDir = NULL;
	//		ofn.Flags = 0;
	//		if (GetSaveFileNameA(&ofn) == TRUE) {
	//			string fileName = ofn.lpstrFile;
	//			material->normalMap = (Texture2D*)wiResourceManager::GetGlobal()->add(fileName);
	//			material->normalMapName = fileName;
	//			texture_normal_Button->SetText(wiHelper::GetFileNameFromPath(material->normalMapName));
	//		}
	//	}
	//});
	//materialWindow->AddWidget(texture_normal_Button);



	//texture_surface_Label = new wiLabel("SurfaceMap: ");
	//texture_surface_Label->SetPos(XMFLOAT2(x, y += step));
	//texture_surface_Label->SetSize(XMFLOAT2(120, 20));
	//materialWindow->AddWidget(texture_surface_Label);

	//texture_surface_Button = new wiButton("SurfaceMap");
	//texture_surface_Button->SetText("");
	//texture_surface_Button->SetTooltip("Load the surface property texture: R: Reflectance, G: Metalness, B: Emissive, A: SSS");
	//texture_surface_Button->SetPos(XMFLOAT2(x + 122, y));
	//texture_surface_Button->SetSize(XMFLOAT2(260, 20));
	//texture_surface_Button->OnClick([&](wiEventArgs args) {
	//	if (material == nullptr)
	//		return;

	//	if (material->surfaceMap != nullptr)
	//	{
	//		material->surfaceMap = nullptr;
	//		material->surfaceMapName = "";
	//		texture_surface_Button->SetText("");
	//	}
	//	else
	//	{
	//		char szFile[260];

	//		OPENFILENAMEA ofn;
	//		ZeroMemory(&ofn, sizeof(ofn));
	//		ofn.lStructSize = sizeof(ofn);
	//		ofn.hwndOwner = nullptr;
	//		ofn.lpstrFile = szFile;
	//		// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	//		// use the contents of szFile to initialize itself.
	//		ofn.lpstrFile[0] = '\0';
	//		ofn.nMaxFile = sizeof(szFile);
	//		ofn.lpstrFilter = "Texture\0*.dds;*.png;*.jpg;*.tga;\0";
	//		ofn.nFilterIndex = 1;
	//		ofn.lpstrFileTitle = NULL;
	//		ofn.nMaxFileTitle = 0;
	//		ofn.lpstrInitialDir = NULL;
	//		ofn.Flags = 0;
	//		if (GetSaveFileNameA(&ofn) == TRUE) {
	//			string fileName = ofn.lpstrFile;
	//			material->surfaceMap = (Texture2D*)wiResourceManager::GetGlobal()->add(fileName);
	//			material->surfaceMapName = fileName;
	//			texture_surface_Button->SetText(wiHelper::GetFileNameFromPath(material->surfaceMapName));
	//		}
	//	}
	//});
	//materialWindow->AddWidget(texture_surface_Button);



	//texture_displacement_Label = new wiLabel("DisplacementMap: ");
	//texture_displacement_Label->SetPos(XMFLOAT2(x, y += step));
	//texture_displacement_Label->SetSize(XMFLOAT2(120, 20));
	//materialWindow->AddWidget(texture_displacement_Label);

	//texture_displacement_Button = new wiButton("DisplacementMap");
	//texture_displacement_Button->SetText("");
	//texture_displacement_Button->SetTooltip("Load the displacement map texture.");
	//texture_displacement_Button->SetPos(XMFLOAT2(x + 122, y));
	//texture_displacement_Button->SetSize(XMFLOAT2(260, 20));
	//texture_displacement_Button->OnClick([&](wiEventArgs args) {
	//	if (material == nullptr)
	//		return;

	//	if (material->displacementMap != nullptr)
	//	{
	//		material->displacementMap = nullptr;
	//		material->displacementMapName = "";
	//		texture_displacement_Button->SetText("");
	//	}
	//	else
	//	{
	//		char szFile[260];

	//		OPENFILENAMEA ofn;
	//		ZeroMemory(&ofn, sizeof(ofn));
	//		ofn.lStructSize = sizeof(ofn);
	//		ofn.hwndOwner = nullptr;
	//		ofn.lpstrFile = szFile;
	//		// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	//		// use the contents of szFile to initialize itself.
	//		ofn.lpstrFile[0] = '\0';
	//		ofn.nMaxFile = sizeof(szFile);
	//		ofn.lpstrFilter = "Texture\0*.dds;*.png;*.jpg;*.tga;\0";
	//		ofn.nFilterIndex = 1;
	//		ofn.lpstrFileTitle = NULL;
	//		ofn.nMaxFileTitle = 0;
	//		ofn.lpstrInitialDir = NULL;
	//		ofn.Flags = 0;
	//		if (GetSaveFileNameA(&ofn) == TRUE) {
	//			string fileName = ofn.lpstrFile;
	//			material->displacementMap = (Texture2D*)wiResourceManager::GetGlobal()->add(fileName);
	//			material->displacementMapName = fileName;
	//			texture_displacement_Button->SetText(wiHelper::GetFileNameFromPath(material->displacementMapName));
	//		}
	//	}
	//});
	//materialWindow->AddWidget(texture_displacement_Button);


	materialWindow->Translate(XMFLOAT3(screenW - 760, 50, 0));
	materialWindow->SetVisible(false);

	SetEntity(INVALID_ENTITY);
}

MaterialWindow::~MaterialWindow()
{
	materialWindow->RemoveWidgets(true);
	GUI->RemoveWidget(materialWindow);
	SAFE_DELETE(materialWindow);
}



void MaterialWindow::SetEntity(Entity entity)
{
	this->entity = entity;

	//if (this->material == mat)
	//	return;

	//if (material != nullptr)
	//{
	//	material->SetUserStencilRef(0);
	//}

	//material = mat;
	//if (material != nullptr)
	//{
	//	materialNameField->SetValue(material->name);
	//	waterCheckBox->SetCheck(material->water);
	//	planarReflCheckBox->SetCheck(material->planar_reflections);
	//	shadowCasterCheckBox->SetCheck(material->cast_shadow);
	//	normalMapSlider->SetValue(material->normalMapStrength);
	//	roughnessSlider->SetValue(material->roughness);
	//	reflectanceSlider->SetValue(material->reflectance);
	//	metalnessSlider->SetValue(material->metalness);
	//	alphaSlider->SetValue(material->alpha);
	//	refractionIndexSlider->SetValue(material->refractionIndex);
	//	emissiveSlider->SetValue(material->emissive);
	//	sssSlider->SetValue(material->subsurfaceScattering);
	//	pomSlider->SetValue(material->parallaxOcclusionMapping);
	//	movingTexSliderU->SetValue(material->movingTex.x);
	//	movingTexSliderU->SetValue(material->movingTex.x);
	//	texMulSliderX->SetValue(material->texMulAdd.x);
	//	texMulSliderY->SetValue(material->texMulAdd.y);
	//	alphaRefSlider->SetValue(material->alphaRef);
	//	materialWindow->SetEnabled(true);
	//	colorPicker->SetEnabled(true);
	//	blendModeComboBox->SetSelected((int)material->blendFlag);

	//	texture_baseColor_Button->SetText(wiHelper::GetFileNameFromPath(material->textureName));
	//	texture_normal_Button->SetText(wiHelper::GetFileNameFromPath(material->normalMapName));
	//	texture_surface_Button->SetText(wiHelper::GetFileNameFromPath(material->surfaceMapName));
	//	texture_displacement_Button->SetText(wiHelper::GetFileNameFromPath(material->displacementMapName));
	//}
	//else
	//{
	//	materialNameField->SetValue("No material selected");
	//	materialWindow->SetEnabled(false);
	//	colorPicker->SetEnabled(false);

	//	texture_baseColor_Button->SetText("");
	//	texture_normal_Button->SetText("");
	//	texture_surface_Button->SetText("");
	//	texture_displacement_Button->SetText("");
	//}
}
