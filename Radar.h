/* Radar.h
Copyright (c) 2014 by Michael Zahniser

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef RADAR_H_
#define RADAR_H_

#include "Point.h"

#include <vector>



// Class representing all objects which should show up on radar. Each object is
// either a ring (planets) or a dot (ships) and has a color representing its status
// (owned by player, friendly, unfriendly, hostile, inactive, or special).
class Radar {
public:
	static const int PLAYER;
	static const int FRIENDLY;
	static const int UNFRIENDLY;
	static const int HOSTILE;
	static const int INACTIVE;
	static const int SPECIAL;
	
public:
	void Clear();
	// Add an object. If "inner" is 0 it is a dot; otherwise, it is a ring. The
	// given position should be in world units (not shrunk to radar units).
	void Add(int type, Point position, double outer, double inner = 0.);
	// Add a pointer, pointing in the direction of the given vector.
	void AddPointer(int type, const Point &position);
	
	// Draw the radar display at the given coordinates.
	void Draw(const Point &center, double scale, double radius, double pointerRadius) const;
	
	// Get the color for the given status.
	static const float *GetColor(int type);
	
	
private:
	class Object {
	public:
		Object(const float *color, const Point &pos, double out, double in);
		
		const float *color;
		Point position;
		double outer;
		double inner;
	};
	
	class Pointer {
	public:
		Pointer(const float *color, const Point &unit);
		
		const float *color;
		Point unit;
	};
	
	
private:
	std::vector<Object> objects;
	std::vector<Pointer> pointers;
};



#endif
