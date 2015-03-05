/*
 * Sprite.h
 *
 *  Created on: 05 марта 2015 г.
 *      Author: snickers
 */

#ifndef SRC_RENDER_SPRITE_H_
#define SRC_RENDER_SPRITE_H_

#include <Render/Surface.h>

class Sprite {
public:
	Sprite();
	virtual ~Sprite();

	void Draw();
	void SetPos(const Vec2& new_pos);
	void SetSize(const Vec2& size);

	void SetTexture(SDL_Texture* texture);

private:
	SDL_Rect _rect;
	SDL_Texture* _texture;
};

#endif /* SRC_RENDER_SPRITE_H_ */
