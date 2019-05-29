/**
* @file Font.h
*/
#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED
#include <GL/glew.h>
#include"Sprite.h"
#include<glm/glm.hpp>
#include <vector>
#include <string>

/**
* ビットマップフォント描画クラス
*/
class FontRenderer
{
public:
	FontRenderer() = default;
	~FontRenderer() = default;
	FontRenderer(const FontRenderer&) = delete;
	FontRenderer& operator=(const FontRenderer&) = delete;

	bool Init(size_t maxChar);
	bool LoadFromFile(const char* path);
	void BeginUpdate();
	bool AddString(const glm::vec2&, const wchar_t*);
	void EndUpdate();
	void Draw(const glm::vec2&) const;
	float LineHeight() const;

private:
	SpriteRenderer spriteRenderer;	///<描画に使用するスプライトレンダラー.
	std::vector<Texture::Image2DPtr>textures;	///<フォントテクスチャリスト.
	float lineHeight = 0;	///<行の高さ.
	float base = 0;	///<行の上部からベースラインまでの距離.
};



#endif // !FONT_H_INCLUDED

