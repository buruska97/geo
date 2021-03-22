#version 430
#extension GL_EXT_geometry_shader4 : enable

layout(points) in;
layout(points, max_vertices=200) out;

out vec3 outPosition;

void main(void)
{
	vec4 pos = gl_PositionIn[0];
	//pos.x -= 0.0001f;
	//pos.y -= 0.0001f;
	gl_Position = pos;

	EmitVertex();
	EndPrimitive();

	outPosition = pos.xyz;
}