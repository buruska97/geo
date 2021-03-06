/*
 *
 * Copyright © 2010-2016 Balázs Tóth <tbalazs@iit.bme.hu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef _POINTGRID_
#define _POINTGRID_

#include <GL/glew.h>

#include "shader.hpp"

class PointGrid{
private:
  int width;
  int height;

  GLuint vertexArray;
  GLuint vertexBuffer;
  GLuint vertexBuffer2;



public:
  PointGrid(int width, int height);
  ~PointGrid();

  void render(Shader* shader);
};

#endif
