////////////////////////////////////////////////////////////////////////////////
// Filename: skin.vs
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
	float3 position : POSITION;
	float2 tex		: TEXCOORD;
	uint4 boneIdx	: BONEID;
	float4 weight	: WEIGHT;
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
	
	float finalWeight = 1 - (input.weight[0]+input.weight[1]+input.weight[2]);
	
	
	float4x4 boneTransform	=	matBones[input.boneIdx[0]] * input.weight[0];
	boneTransform			+=	matBones[input.boneIdx[1]] * input.weight[1];
	boneTransform			+=	matBones[input.boneIdx[2]] * input.weight[2];
	boneTransform			+=	matBones[input.boneIdx[3]] * finalWeight;
	
	output.position			= mul(float4(input.position, 1.f), boneTransform);
	output.position			= mul(output.position, matWorld);
    output.position			= mul(output.position, matView);
    output.position			= mul(output.position, matProj);
    
	output.tex = input.tex;

    return output;
}