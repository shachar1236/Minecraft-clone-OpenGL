#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in float red_color;

out float out_red_color;

void main() 
{
    gl_Position = position;
    out_red_color = red_color;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in float out_red_color;
// uniform vec4 u_Color;

void main() 
{
    // color = u_Color;
    color = vec4(out_red_color, 0.5, 1.0, 1.0);
};