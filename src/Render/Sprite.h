/*
 * Sprite.h
 *
 *  Created on: 05 марта 2015 г.
 *      Author: snickers
 */

#ifndef SRC_RENDER_SPRITE_H_
#define SRC_RENDER_SPRITE_H_

#include <Render/Surface.h>
#include <Render/Animation.h>

class Sprite {
public:
    Sprite();
    virtual ~Sprite();

    void Draw();
    void SetPos(const Vec2& new_pos);
    void SetSize(const Vec2& size);
    void SetTexture(SDL_Texture* texture);
    void SetAnimation(int begin_frame, int end_frame);

private:
    bool _isAnimated;
    SDL_Rect _rect;
    SDL_Rect _src_rect;//real size of texture
    SDL_Texture* _texture;
    Animation _anim_control;
};

#endif /* SRC_RENDER_SPRITE_H_ */
