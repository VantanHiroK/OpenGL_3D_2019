/**
* @file Main.cpp
*/
#include <iostream>
#include "TitleScene.h"
#include "GLFWEW.h"

//�X�^�b�N�̎���
int stack[10];		//�X�^�b�N�p�z��
int data_size = 0;	//�X�^�b�N�ɐς܂�Ă���f�[�^��(�ꎞ�I�Ƀf�[�^���i�[)

//�X�^�b�N�Ƀv�b�V��
void push(int data)
{
	//�X�^�b�N�̈�ԏ�Ƀf�[�^�̏�ɁA�󂯎�����f�[�^������
	stack[data_size] = data;

	//�f�[�^���������邽�тɁu1�v���₷
	++data_size;
}

//�X�^�b�N�Ƀ|�b�v
int pop()
{
	if (data_size <= 0) {
		return -1;	//�f�[�^���Ȃ�(�G���[)
	}
	else if (data_size > 10) {
		return -1;	//�X�^�b�N�����t(�G���[)
	}

	//�X�^�b�N�̈�ԏォ��f�[�^�����o��
	int data = stack[data_size - 1];	//�z��̓Y������0����Ȃ̂�-1����

	//�f�[�^����1���炷
	--data_size;

	//���o�����f�[�^��߂�l�ɂ���
	return data;
}

int main()
{
	GLFWEW::Window& window = GLFWEW::Window::Instance();
	window.Init(1280, 720, u8"�A�N�V�����Q�[��");

	SceneStack& sceneStack = SceneStack::Instance();
	sceneStack.Push(std::make_shared<TitleScene>());

	while(!window.ShouldClose()){
		const float deltaTime = window.DeltaTime();
		window.UpdateTimer();
		sceneStack.Update(deltaTime);
		sceneStack.Render();
		window.SwapBuffers();
	}

	push(10);
	push(30);
	std::cout << pop() << "\n";
	push(20);
	push(100);
	pop();
	std::cout << pop() << "\n";
	std::cout << pop() << "\n";
}