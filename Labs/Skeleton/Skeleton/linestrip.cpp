#include "linestrip.hpp"




LineStrip::LineStrip()
{
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);
	vertices.push_back(1.0f);

	vertices.push_back(0.0f);
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);
	vertices.push_back(1.0f);
}

LineStrip::~LineStrip()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArray);

}

void LineStrip::init()
{
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer((GLuint)0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

void LineStrip::render() {

	glBindVertexArray(vertexArray);
	glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, vertices.size() / 4);
	glBindVertexArray(0);
}

void LineStrip::render(int width, int height)
{
	int vp[4];
	glGetIntegerv(GL_VIEWPORT, vp);
	glViewport(0, 0, width, height);
	this->render();
	glViewport(vp[0], vp[1], vp[2], vp[3]);
}

void LineStrip::addNewPoint(float x, float y)
{
	int n = vertices.size();
	vertices[n - 4] = x;
	vertices[n - 3] = y;
	vertices[n - 2] = 0.0f;
	vertices[n - 1] = 1.0f;

	vertices.push_back(0.0f);
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);
	vertices.push_back(1.0f);

	setAdjancyPoints();

	glDeleteVertexArrays(1, &vertexArray);
	glDeleteBuffers(1, &vertexBuffer);

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer((GLuint)0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

void LineStrip::setAdjancyPoints()
{
	int n = vertices.size();

	if (n >= 16)
	{
		vertices[0] = 2 * vertices[4] - vertices[8];
		vertices[1] = 2 * vertices[5] - vertices[9];

		vertices[n - 4] = 2 * vertices[n - 8] - vertices[n - 12];
		vertices[n - 3] = 2 * vertices[n - 7] - vertices[n - 11];
	}
}
