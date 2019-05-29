/**
* @file Main.cpp
*/
#include <iostream>
#include "TitleScene.h"
#include "GLFWEW.h"

//スタックの実装
int stack[10];		//スタック用配列
int data_size = 0;	//スタックに積まれているデータ数(一時的にデータを格納)

//スタックにプッシュ
void push(int data)
{
	//スタックの一番上にデータの上に、受け取ったデータを入れる
	stack[data_size] = data;

	//データ数が増えるたびに「1」増やす
	++data_size;
}

//スタックにポップ
int pop()
{
	if (data_size <= 0) {
		return -1;	//データがない(エラー)
	}
	else if (data_size > 10) {
		return -1;	//スタックが満杯(エラー)
	}

	//スタックの一番上からデータを取り出す
	int data = stack[data_size - 1];	//配列の添え字は0からなので-1する

	//データ数を1減らす
	--data_size;

	//取り出したデータを戻り値にする
	return data;
}

int main()
{
	GLFWEW::Window& window = GLFWEW::Window::Instance();
	window.Init(1280, 720, u8"アクションゲーム");

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