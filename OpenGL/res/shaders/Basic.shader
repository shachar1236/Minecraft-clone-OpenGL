#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

// out float out_red_color;
out vec4 out_color;
uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

void main() 
{
    // gl_Position = position;
    // gl_Position = u_ViewProjection * u_Transform * vec4(position, 1.0f);
    gl_Position = u_ViewProjection * u_Transform * position;
    out_color = vec4(position.x * 0.5 + 0.5, position.y * 0.5 + 0.5, position.z * 0.5 + 0.5, 1.0f);
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

// in float out_red_color;
in vec4 out_color;

void main() 
{
    color = out_color;
    // color = vec4(out_red_color, 0.5, 1.0, 1.0);
};