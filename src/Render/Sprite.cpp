/*
 * Sprite.cpp
 *
 *  Created on: 05 марта 2015 г.
 *      Author: snickers
 */

#include <Render/Sprite.h>
#include <iostream>

Sprite::Sprite() {
    _texture = nullptr;
    _isAnimated = false;
    _angle = 0;
    _flip = SDL_FLIP_NONE;
    _frames_per_width = 1;
}

Sprite::~Sprite() {

}

void Sprite::Draw() {
    //TODO What about performance?
    //Same performance (~1000 objects) when not animated xD

    SDL_Rect src_rect = {
            (_anim_control.GetCurrentFrame() % _frames_per_width) * _anim_rect.w, //_anim_rect.x + _anim_rect.w * (_anim_control.GetCurrentFrame() % _frames_per_width),
            (_anim_control.GetCurrentFrame() / _frames_per_width) * _anim_rect.h,
            _anim_rect.w, _anim_rect.h
    };

    Surface::Draw(_texture, &src_rect, &_rect, _angle, _flip);
    _anim_control.OnAnimation();
}

void Sprite::SetPos(const Vec2& new_pos) {
    _rect.x = new_pos.x;
    _rect.y = new_pos.y;
}

void Sprite::SetSize(const Vec2& size) {
    _rect.w = size.x;
    _rect.h = size.y;
}

void Sprite::SetTexture(SDL_Texture* texture) {
    _texture = texture;

    //Get texture size
    if (_texture) {
        SDL_QueryTexture(_texture, nullptr, nullptr, &_src_rect.w, &_src_rect.h);
    }
}

void Sprite::SetAngle(int angle) {
    _angle = angle % 360;
}

void Sprite::SetFlip(SDL_RendererFlip flip) {
    _flip = flip;
}

Vec2 Sprite::GetPos() const {
    return Vec2(_rect.x, _rect.y);
}

Vec2 Sprite::GetSize() const {
    return Vec2(_rect.w, _rect.h);
}

SDL_Texture* Sprite::GetTexture() const {
    return _texture;
}

int Sprite::GetAngle() const {
    return _angle;
}

/*==Animation control==*/

void Sprite::SetFrameSize(const Vec2& frame_size) {
    _anim_rect.w = frame_size.x;
    _anim_rect.h = frame_size.y;
    SetFrame(_anim_control.GetCurrentFrame());
}

void Sprite::SetAnimation(int begin_frame, int end_frame) {
    _anim_control.SetBeginFrame(begin_frame);
    _anim_control.SetMaxFrame(end_frame);
    SetFrame(begin_frame);
}

void Sprite::SetFrame(int frame) {
    if (_src_rect.w == 0 || _anim_rect.w == 0)
        _frames_per_width = 1;
    else
        _frames_per_width = _src_rect.w / _anim_rect.w;

    _anim_rect.x = (frame % _frames_per_width) * _anim_rect.w;
    _anim_rect.y = (frame / _frames_per_width) * _anim_rect.h;

    _anim_control.SetCurrentFrame(frame);
}

void Sprite::SetAnimationRate(int frame_rate) {
    _anim_control.SetFrameRate(frame_rate);
}

