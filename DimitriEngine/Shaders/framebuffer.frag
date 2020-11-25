#version 440 core
out vec4 FragColor;
  
in vec2 TexCoords;

uniform sampler2D screenTexture;

const float offset = 1.0 / 300.0;  

// Define kernels
#define BLUR 16
#define identity float[](0, 0, 0, 0, 1, 0, 0, 0, 0)
#define edge0 float[](1, 0, -1, 0, 0, 0, -1, 0, 1)
#define edge1 float[](0, 1, 0, 1, -4, 1, 0, 1, 0)
#define edge2 float[](-1, -1, -1, -1, 8, -1, -1, -1, -1)
#define sharpen float[](0, -1, 0, -1, 5, -1, 0, -1, 0)
#define box_blur float[](1 * 0.1111, 1 * 0.1111, 1 * 0.1111, 1 * 0.1111, 1 * 0.1111, 1 * 0.1111, 1 * 0.1111, 1 * 0.1111, 1 * 0.1111)
#define gaussian_blur float[](1.0 / BLUR, 2.0 / BLUR, 1. / BLUR, 2.0 / BLUR, 4.0 / BLUR, 2.0 / BLUR, 1.0 / BLUR, 2.0 / BLUR, 1.0 / BLUR)
#define emboss float[](-2, -1, 0, -1, 1, 1, 0, 1, 2)

vec3 PostProcess(float[9] effect, vec3 col){
    vec2 offsets[9] = vec2[](
        vec2(-offset,  offset), // top-left
        vec2( 0.0f,    offset), // top-center
        vec2( offset,  offset), // top-right
        vec2(-offset,  0.0f),   // center-left
        vec2( 0.0f,    0.0f),   // center-center
        vec2( offset,  0.0f),   // center-right
        vec2(-offset, -offset), // bottom-left
        vec2( 0.0f,   -offset), // bottom-center
        vec2( offset, -offset)  // bottom-right    
    );

    float kernel[9] = effect;

    
    vec3 sampleTex[9];
    for(int i = 0; i < 9; i++)
    {
        sampleTex[i] = vec3(texture(screenTexture, TexCoords.st + offsets[i]));
    }
    for(int i = 0; i < 9; i++)
        col += sampleTex[i] * kernel[i];

    return col;
}

void main()
{
    //vec3 col = vec3(texture(screenTexture, TexCoords));
    vec3 col = PostProcess(identity, vec3(0.0));
    //vec3 col = PostProcess(edge2, col);
    
    FragColor = vec4(col, 1.0);
}