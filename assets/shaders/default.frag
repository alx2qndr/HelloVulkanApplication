#version 450

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragNormal;
layout(location = 3) in vec3 fragPos;

layout(location = 0) out vec4 outColor;

const vec3 lightDir = normalize(vec3(-4.0, -4.0, -4.0));
const vec3 lightColor = vec3(1.0);
const vec3 ambientColor = vec3(0.1, 0.2, 0.3);
const vec3 cameraPos = vec3(-8.0, 0.0, 0.0);

void main() {
    vec3 normal = normalize(fragNormal);
    vec3 viewDir = normalize(cameraPos - fragPos);
    
    float diffuseFactor = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diffuseFactor * lightColor;
    
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    vec3 specular = 2.0 * spec * lightColor;
    
    vec3 texColor = texture(texSampler, fragTexCoord).rgb;
    
    vec3 lighting = ambientColor + diffuse + specular;
    outColor = vec4(texColor * lighting, 1.0);
}