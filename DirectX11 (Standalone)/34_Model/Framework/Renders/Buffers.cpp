#include "Framework.h"
#include "Buffers.h"

VertexBuffer::VertexBuffer(void* data, UINT count, UINT stride, UINT slot, bool bCpuWrite, bool bGpuWrite)
	: data(data), count(count), stride(stride), slot(slot),
	  bCpuWrite(bCpuWrite), bGpuWrite(bGpuWrite)
{
	// Create Vertex Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = stride * count;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		if (bCpuWrite == false && bGpuWrite == false)
		{
			desc.Usage = D3D11_USAGE_IMMUTABLE;
		}
		else if (bCpuWrite == true && bGpuWrite == false)
		{
			desc.Usage = D3D11_USAGE_DYNAMIC;	// CPU 쓰기만 가능, GPU 읽기만 가능
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		}
		else if (bCpuWrite == false && bGpuWrite == true)
		{
			desc.Usage = D3D11_USAGE_DEFAULT;	// UpdateSubresource 에서만 CPU 쓰기 예외적으로 가능, GPU 쓰기 가능
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		}
		else
		{
			desc.Usage = D3D11_USAGE_STAGING;	// CPU, GPU 모두 읽기 쓰기 가능 = 가장 느림
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
		}
		
		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = data;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &buffer));
	}
}

VertexBuffer::~VertexBuffer()
{
	SafeRelease(buffer);
}

void VertexBuffer::Render()
{
	UINT offset = 0;
	D3D::GetDC()->IASetVertexBuffers(slot, 1, &buffer, &stride, &offset);
}

///////////////////////////////////////////////////////////////////////////////////////////////

IndexBuffer::IndexBuffer(void * data, UINT count)
	: data(data), count(count)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

	desc.ByteWidth = sizeof(UINT) * count;
	desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	desc.Usage = D3D11_USAGE_IMMUTABLE;

	D3D11_SUBRESOURCE_DATA subResource = { 0 };
	subResource.pSysMem = data;

	Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &buffer));
}

IndexBuffer::~IndexBuffer()
{
	SafeRelease(buffer);
}

void IndexBuffer::Render()
{
	D3D::GetDC()->IASetIndexBuffer(buffer, DXGI_FORMAT_R32_UINT, 0);
}

///////////////////////////////////////////////////////////////////////////////////////////////

ConstantBuffer::ConstantBuffer(void* data, UINT dataSize)
	: data(data), dataSize(dataSize)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

	desc.ByteWidth = dataSize;
	desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	desc.Usage = D3D11_USAGE_DYNAMIC;
	desc.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;

	Check(D3D::GetDevice()->CreateBuffer(&desc, nullptr, &buffer));
}

ConstantBuffer::~ConstantBuffer()
{
	SafeRelease(buffer);
}

void ConstantBuffer::Render()
{
	D3D11_MAPPED_SUBRESOURCE subResource;
	// 매핑된 서브 리소스 데이터의 포인터를 가져오고, 해당 하위 리소스에 대한 GPU 액세스를 막는 함수.
	D3D::GetDC()->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subResource);
	{
		memcpy(subResource.pData, data, dataSize);
	}

	// 리소스에 대한 포인터를 다시 무효화하고, 해당 리소스에 대한 GPU의 액세스를 활성화하는 함수.
	D3D::GetDC()->Unmap(buffer, 0);
}