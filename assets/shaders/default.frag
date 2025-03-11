#version 450

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragNormal;
layout(location = 3) in vec3 fragPos;

layout(location = 0) out vec4 outColor;

const vec3 lightDir = normalize(vec3(-1.0, -1.0, -1.0));
const vec3 lightColor = vec3(1.0, 1.0, 1.0);
const vec3 ambientColor = vec3(0.1, 0.1, 0.1);

void main() {
    vec3 normal = normalize(fragNormal);

    float diffuse = max(dot(normal, lightDir), 0.0);
    vec3 lighting = ambientColor + diffuse * lightColor;

    vec3 texColor = texture(texSampler, fragTexCoord).rgb;

    outColor = vec4(texColor * lighting, 1.0);
}
