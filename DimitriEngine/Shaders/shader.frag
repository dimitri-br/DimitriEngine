#version 330 core
struct Material
{
    sampler2D texture_diffuse;
    sampler2D texture_specular;

    vec3 color;
    float smoothness;
    float metallic;
};
uniform Material material;

struct DirLight{
    vec3 direction;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    vec3 color;
};
uniform DirLight dirLight;

struct PointLight {    
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;  

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    vec3 color;
};  
#define NR_POINT_LIGHTS 4
uniform PointLight pointLights[NR_POINT_LIGHTS];

in vec2 TexCoords;
in vec3 Normal;

in vec3 FragPos;

layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;


uniform bool useColor;
uniform vec3 viewPos;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.smoothness);
    // combine results
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.texture_diffuse, TexCoords));
    if  (useColor){
        ambient = light.ambient * material.color;
        diffuse = light.diffuse * material.color;
    }
    vec3 specular = light.specular * spec * ((!useColor) ? vec3(texture(material.texture_specular, TexCoords)) : vec3(1));
    
    return (ambient + diffuse + specular);// + specular);
} 


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.smoothness);
    // attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
  			     light.quadratic * (distance * distance));   

    // combine results
    vec3 ambient  = light.ambient * vec3(texture(material.texture_diffuse, TexCoords));
    vec3 diffuse  = light.diffuse * diff * vec3(texture(material.texture_diffuse, TexCoords));
    if  (useColor){
        ambient = light.ambient * material.color;
        diffuse = light.diffuse * material.color;
    }
    vec3 specular = light.specular * spec * ((!useColor) ? vec3(texture(material.texture_specular, TexCoords)) : vec3(1));
    
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
} 

void main()
{   
    // properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    // phase 1: Directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir);
    //vec3 result = vec3(0);
    // phase 2: Point lights
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
       result += CalcPointLight(pointLights[i], norm, FragPos, viewDir); 
    // check whether result is higher than some threshold, if so, output as bloom threshold color
    float brightness = dot(result, vec3(0.2126f, 0.7152f, 0.0722f));
    if(brightness > 1.0f)
        BrightColor = vec4(result, 1.0f);
    else
        BrightColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    FragColor = vec4(result, 1.0f);
    //FragColor = vec4((result), 1.0f);// * texture(material.texture_diffuse, TexCoords);
   // FragColor = texture(material.texture_diffuse, TexCoords);
}