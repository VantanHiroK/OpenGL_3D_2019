/**
* @file Scene.cpp
*/
#include "Scene.h"
#include <iostream>

/**
* �R���X�g���N�^
* 
* @param name �V�[����
*/
Scene::Scene(const char* name) :name(name)
{

}

/**
* �f�X�g���N�^
*/
Scene::~Scene() 
{
	Finialize();
}

/**
* �V�[����������Ԃɂ���
*/
void Scene::Play() 
{
	isActive = true;
}

/**
* �V�[�����~��Ԃɂ���
*/
void Scene::Stop()
{
	isActive = false;
}

/**
* �V�[����\������
*/
void Scene::Show()
{
	isVisible = true;
}

/**
* �V�[�����\������
*/
void Scene::Hide()
{
	isVisible = false;
}

/**
* �V�[�������擾����
* 
* @return �V�[����
*/
const std::string& Scene::Name() const
{
	return name;
}

/**
* �V�[���̊�����Ԃ𒲂ׂ�
* 
* @retval true	�������Ă���
* @retval flase	��~���Ă���
*/
bool Scene::IsActive() const
{
	return isActive;
}

/**
* �V�[���̕\����Ԃ𒲂ׂ�
*
* @retval true	�\�����Ă���
* @retval flase	��\�����Ă���
*/
bool Scene::IsVisible() const
{
	return isVisible;
}