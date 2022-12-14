////////////////////////////////////////////////////////////////////////////////
// Filename: texture.vs
////////////////////////////////////////////////////////////////////////////////
//#include "bufferStruct.h"
cbuffer CameraBuffer : register (b0)
{
	float4x4 matView;
	float4x4 matProj;
};

cbuffer TransBuffer : register (b1)
{
	float4x4 matWorld;
};

cbuffer ColorBuffer : register (b2)
{
	float4 fColor;
};

cbuffer BoneBuffer : register (b3)
{
	float4x4 matBones[128];
};

float4x4 IdentityMatrix =
{
	{ 1, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 0, 1 }
};

struct VertexInputType
{
	float4 position : POSITION;
	float2 tex : TEXCOORD;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 tex : TEXCOORD;
};

////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType vsMain(VertexInputType input)
{
    PixelInputType output;
    
	// Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;

	// Calculate the position of the vertex against the world, view, and projection matrices.
	output.position = mul(input.position, matWorld);
    output.position = mul(output.position, matView);
    output.position = mul(output.position, matProj);
    
	// Store the texture coordinates for the pixel shader.
	output.tex = input.tex;

    return output;
}