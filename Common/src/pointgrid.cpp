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

#include <iostream>

#include "pointgrid.hpp"

PointGrid::PointGrid(int width, int height){
  this->width = width;
  this->height = height;

  GLfloat* vertices = new GLfloat[3 * width * height];
  for(int y = 0; y < height; ++y){
    for(int x = 0; x < width; ++x){
      vertices[3 * (x + y * width)] = x / (float)width ; // X
      vertices[3 * (x + y * width) + 1] = y / (float)height; // Y
      vertices[3 * (x + y * width) + 2] = 0.0f; // Z
    }
  }

  glGenVertexArrays(1, &vertexArray);
  glBindVertexArray(vertexArray);

  //glGenTransformFeedbacks(1, &feedbackBuffer);

  glGenBuffers(1, &vertexBuffer);
  //glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, feedbackBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * width * height, vertices, GL_STATIC_DRAW);

  

  glEnableVertexAttribArray(0);
  glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);

  glGenBuffers(1, &vertexBuffer2);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * width * height, nullptr, GL_STATIC_READ);

  glFlush();

  glBindVertexArray(0);
}

PointGrid::~PointGrid(){
  glDeleteBuffers(1, &vertexBuffer);
  glDeleteVertexArrays(1, &vertexArray);
}

void PointGrid::render(Shader* shader){

    glBindVertexArray(vertexArray);
    glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, vertexBuffer2);
    //glBindTransformFeedback(fbo2, )
    glBeginTransformFeedback(GL_POINTS);
    bool static isFirst = true;

    
    glDrawArrays(GL_POINTS, 0, width * height);

    GLfloat feedback[100];
    glGetBufferSubData(GL_TRANSFORM_FEEDBACK_BUFFER, 0, sizeof(feedback), feedback);

    for (int i = 0; i < 10; i++)
    {
        std::cout << feedback[i] << "\n";
    }

    glEndTransformFeedback();
    glGetBufferSubData(GL_TRANSFORM_FEEDBACK_BUFFER, 0, sizeof(feedback), feedback);

    for (int i = 0; i < 10; i++)
    {
        std::cout << feedback[i] << "\n";
    }

    glBindVertexArray(0);
    

}
