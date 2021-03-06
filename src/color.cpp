/* 
 *  Copyright (c) 2017  Rafael Pagés
 *
 *  This file is part of SSMVtex
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *  of the Software, and to permit persons to whom the Software is furnished to do
 *  so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 *  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 *  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "color.h"

Color::Color (unsigned char *_p){

}

Color::Color (){
	r_ = g_ = b_ = 0.0;
	alpha_ = 1.0;
}

Color::Color (float _red, float _green, float _blue, float _alpha){
	// r_ = _red > 255 ? 255 : _red;
	// r_ = _red < 0 ? 0 : _red;

	// g_ = _green  > 255 ? 255 : _green;
	// g_ = _green < 0 ? 0 : _green;

	// b_ = _blue  > 255 ? 255 : _blue;
	// b_ = _blue < 0 ? 0 : _blue;

	// alpha_ = _alpha  > 1 ? 1 : _alpha;
	// alpha_ = _alpha < 0 ? 0 : _alpha;
	r_ = _red;
	g_ = _green;
	b_ = _blue;
	alpha_ = _alpha;

}

float Color::getRed() const {
	return r_;
}

float Color::getGreen() const {
	return g_;
}

float Color::getBlue() const {
	return b_;
}

float Color::getAlpha() const {
	return alpha_;
}

void Color::setRed(float _r){
	if (_r > 255.0){
		std::cerr << "Wrong red value: over 255" << std::endl;
		r_ = 255.0;
	} else if (_r < 0.0){
		std::cerr << "Wrong red value: under 0" << std::endl;
		r_ = 0.0;
	} else {
		r_ = _r;
	}
}

void Color::setGreen(float _g){
	if (_g > 255.0){
		std::cerr << "Wrong green value: over 255" << std::endl;
		g_ = 255.0;
	} else if (_g < 0.0){
		std::cerr << "Wrong green value: under 0" << std::endl;
		g_ = 0.0;
	} else {
		g_ = _g;
	}
}

void Color::setBlue(float _b){
	if (_b > 255.0){
		std::cerr << "Wrong blue value: over 255" << std::endl;
		b_ = 255.0;
	} else if (_b < 0.0){
		std::cerr << "Wrong blue value: under 0" << std::endl;
		b_ = 0.0;
	} else {
		b_ = _b;
	}
}

void Color::setAlpha(float _alpha){
	if (_alpha > 1.0){
		std::cerr << "Wrong alpha value: over 1" << std::endl;
		alpha_ = 255.0;
	} else if (_alpha < 0.0){
		std::cerr << "Wrong alpha value: under 0" << std::endl;
		alpha_ = 0.0;
	} else {
		alpha_ = _alpha;
	}
}

void Color::operator+= (const Color& _c) {
	r_ += _c.getRed();
	g_ += _c.getGreen();
	b_ += _c.getBlue();
}

Color Color::operator+ (const Color& _c) const {
	Color csum (r_ + _c.getRed(), g_ + _c.getGreen(), b_ + _c.getBlue(), alpha_);
	return csum;
}


Color Color::operator- (const Color& _c) const {
	Color cdiff (r_ - _c.getRed(), g_ - _c.getGreen(), b_ - _c.getBlue(), alpha_);
	return cdiff;
}


Color Color::operator* (float _f) const {
	Color cnew (r_ * _f, g_ * _f, b_ * _f, alpha_);
	return cnew;
}

Color Color::operator/ (float _f) const {
	Color cnew(r_ / _f, g_ / _f, b_ / _f, alpha_);
	return cnew;
}

bool Color::operator== (const Color& _c) const {

	return (r_ == _c.getRed()) && (g_ == _c.getGreen()) && (b_ == _c.getBlue()) && (alpha_ == _c.getAlpha());

}


bool Color::equals(const Color& _c) const {
	return *this == _c;
}

Color Color::hsv2rgb(float _h, float _s, float _v){

    float  hh, p, q, t, ff;
    int  i;
    Color out;

    if(_s <= 0.0) {       // < is bogus, just shuts up warnings
        // error - should never happen
        out.r_ = 0.0;
        out.g_ = 0.0;
        out.b_ = 0.0;
        return out;
    }

    hh = _h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = _v * (1.0 - _s);
    q = _v * (1.0 - (_s * ff));
    t = _v * (1.0 - (_s * (1.0 - ff)));

    switch(i) {
    case 0:
        out.r_ = _v;
        out.g_ = t;
        out.b_ = p;
        break;
    case 1:
        out.r_ = q;
        out.g_ = _v;
        out.b_ = p;
        break;
    case 2:
        out.r_ = p;
        out.g_ = _v;
        out.b_ = t;
        break;
    case 3:
        out.r_ = p;
        out.g_ = q;
        out.b_ = _v;
        break;
    case 4:
        out.r_ = t;
        out.g_ = p;
        out.b_ = _v;
        break;
    case 5:
    default:
        out.r_ = _v;
        out.g_ = p;
        out.b_ = q;
        break;
    }
    return out;
}
