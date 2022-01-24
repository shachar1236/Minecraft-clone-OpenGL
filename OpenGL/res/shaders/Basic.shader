#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
// layout(location = 1) in float red_color;

// out float out_red_color;
uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

void main() 
{
    // gl_Position = position;
    gl_Position = u_ViewProjection * u_Transform * position;
    // out_red_color = 0.4;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

// in float out_red_color;
uniform vec4 u_Color;

void main() 
{
    color = u_Color;
    // color = vec4(out_red_color, 0.5, 1.0, 1.0);
};