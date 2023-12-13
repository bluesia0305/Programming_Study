#include "00_Global.fx"

// shader->AsMatrix(), ... �� �Ű����� �̸�(string)�� ���ƾ���
Texture2D DiffuseMap;
float3 Direction;

struct VertexOutput
{
    float4 Position : SV_Position;
    float2 Uv : Uv;
    float3 Normal : Normal;
};

VertexOutput VS(VertexTextureNormal input)
{
    VertexOutput output;
    output.Position = WorldPosition(input.Position);
    output.Position = ViewProjection(output.Position);
    output.Uv = input.Uv;
    output.Normal = WorldNormal(input.Normal);

    return output;
}

float4 PS(VertexOutput input) : SV_Target
{
    float3 normal = normalize(input.Normal);
    float3 light = -Direction; // ǥ�� -> ���� ����(���� ���͸� �ݴ� �������� ������ ��)

    return DiffuseMap.Sample(LinearSampler, input.Uv) * dot(normal, light);
}

technique11 T0
{
	P_VP(P0, VS, PS)
	P_RS_VP(P1, FillMode_WireFrame, VS, PS)
}