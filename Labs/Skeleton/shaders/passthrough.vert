#version 430

in vec3 vPosition;

void main(void) {
   gl_Position = vec4(vPosition, 1.0f);
}

