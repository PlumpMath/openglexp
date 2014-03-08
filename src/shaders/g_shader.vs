#version 330 core

in vec3 vpos;
in vec3 vcol;
in vec3 vnorm;

out vec3 fpos;
out vec3 fcol;
out vec3 fnorm;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
  gl_Position = projMat * viewMat * modelMat * vec4(vpos,1.0);
  fpos = gl_Position.xyz;
  fcol = vcol;
  fnorm = vnorm;
}

