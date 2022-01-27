#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textCoord;

// out float out_red_color;
uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec4 out_color;
out vec2 textureCoord;

void main() 
{
    // gl_Position = position;
    // gl_Position = u_ViewProjection * u_Transform * vec4(position, 1.0f);
    gl_Position = u_ViewProjection * u_Transform * position;
    out_color = vec4(position.x * 0.5 + 0.5, position.y * 0.5 + 0.5, position.z * 0.5 + 0.5, 1.0f);
    textureCoord = textCoord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

// in float out_red_color;
in vec4 out_color;
in vec2 textureCoord;

uniform sampler2D ourTexture;

void main() 
{
    color = texture(ourTexture, textureCoord);
    // color = vec4(out_red_color, 0.5, 1.0, 1.0);
};