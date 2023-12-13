// shader->AsMatrix() 내의 매개변수 이름(string)과 같아야함
matrix		World;
matrix		View;
matrix		Projection;
float3		Direction;		// 빛이 들어오는 방향 (광원 -> 표면)

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
	float3 light  = -Direction;		// 표면 -> 광원 방향(광선 벡터를 반대 방향으로 뒤집은 것)

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