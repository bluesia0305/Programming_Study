// shader->AsMatrix() ���� �Ű����� �̸�(string)�� ���ƾ���
matrix		World;
matrix		View;
matrix		Projection;
float3		Direction;		// ���� ������ ���� (���� -> ǥ��)

struct VertexInput
{
	float4 Position : Position;
	float3 Normal : Normal;
};

struct VertexOutput
{
    float4 Position : SV_Position;
    float3 Normal : Normal;
};

VertexOutput VS(VertexInput input)
{
    VertexOutput output;
    output.Position = mul(input.Position, World);
    output.Position = mul(output.Position, View);
    output.Position = mul(output.Position, Projection);

    output.Normal	= mul(input.Normal, (float3x3)World);

    return output;
}

SamplerState Samp;
float4 PS(VertexOutput input) : SV_Target
{
    float3 normal = normalize(input.Normal);
	float3 light  = -Direction;		// ǥ�� -> ���� ����(���� ���͸� �ݴ� �������� ������ ��)

    return float4(1, 1, 1, 1) * dot(normal, light);
}

RasterizerState FillMode_WireFrame
{
    FillMode = WireFrame;
};

technique11 T0
{
    pass P0
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }

    pass P1
    {
        SetRasterizerState(FillMode_WireFrame);

        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }
}