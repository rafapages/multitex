/* 
 *  Copyright (c) 2015  Rafael Pagés (rps (at) gti.ssr.upm.es)
 *    and Universidad Politécnica de Madrid
 *
 *  This file is part of Multitex
 *
 *  Multitex is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Multitex is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

#include "chart.h"
#include <fstream>

Chart::Chart(){

}

Chart::~Chart(){

}

void Chart::setNEdgePos(int _value){
	nEdgePos_ = _value;
}

void Chart::increaseNEdgePos(){
	nEdgePos_++;
}

void Chart::decreaseNEdgePos(){
	nEdgePos_--;
}

void Chart::setOrder(int _value){
	order_ = _value;
}

void Chart::increaseOrder(){
	order_++;
}

int Chart::getNEdgePos() const {
	return nEdgePos_;
}

int Chart::getOrder() const {
	return order_;
}

float Chart::getWidth() const {
	const Vector2f bboxmin = m_.getBBoxMin();
	const Vector2f bboxmax = m_.getBBoxMax();
	return fabs(bboxmax(0) - bboxmin(0));
}

float Chart::getHeight() const {
	const Vector2f bboxmin = m_.getBBoxMin();
	const Vector2f bboxmax = m_.getBBoxMax();
	return fabs(bboxmax(1) - bboxmin(1));
}

float Chart::getArea() const {
	return getHeight() * getWidth();
}

void Chart::displace(const Vector2f& _v){
	m_.displaceMesh(_v);
}

void Chart::rotate(){
	m_.rotateMesh();
}

void Chart::addOffset2BoundingBox(float _offset){
	m_.addOffset2BoundingBox(_offset);
}

