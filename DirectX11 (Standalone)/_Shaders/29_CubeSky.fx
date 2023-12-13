#include "00_Global.fx"

TextureCube SkyCubeMap;

struct VertexOutput
{
    float4 Position : SV_Position;
    float3 oPosition : Position1;
};

VertexOutput VS(Vertex input)
{
    VertexOutput output;

    output.Position		= mul(input.Position, World);
    output.Position		= mul(output.Position, View);
    output.Position		= mul(output.Position, Projection);

    output.oPosition.x  = -input.Position.x;		// ������ ��� ���ΰ� �������� �ٲ���
    output.oPosition.yz = input.Position.yz;		// 

    return output;
}

float4 PS(VertexOutput input) : SV_Target
{
    return SkyCubeMap.Sample(LinearSampler, input.oPosition);
}

technique11 T0
{
    P_RS_DSS_VP(P0, FrontCounterClockwise_True, DepthEnable_False, VS, PS)
}