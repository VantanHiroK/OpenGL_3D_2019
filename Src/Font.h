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
* �r�b�g�}�b�v�t�H���g�`��N���X
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
	SpriteRenderer spriteRenderer;	///<�`��Ɏg�p����X�v���C�g�����_���[.
	std::vector<Texture::Image2DPtr>textures;	///<�t�H���g�e�N�X�`�����X�g.
	float lineHeight = 0;	///<�s�̍���.
	float base = 0;	///<�s�̏㕔����x�[�X���C���܂ł̋���.
};



#endif // !FONT_H_INCLUDED

