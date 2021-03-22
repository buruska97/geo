#pragma once

#include <GL/glew.h>
#include <vector>

class LineStrip {
private:
	GLuint vertexArray;

	std::vector<GLfloat> vertices;
	GLuint vertexBuffer;

public:
	LineStrip();
	~LineStrip();

	void init();
	void render();
	void render(int width, int height);

	void addNewPoint(float x, float y);
	void setAdjancyPoints();
};