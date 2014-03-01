/* LineShader.h
Copyright (c) 2014 by Michael Zahniser

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef LINE_SHADER_H_
#define LINE_SHADER_H_

#include "Point.h"



// Class to be used for drawing lines.
class LineShader {
public:
	static void Init();
	
	static void Draw(Point from, Point to, float width, const float *color = nullptr);
};



#endif
