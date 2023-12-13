#include <d3d11.h>
#include <cassert>
#include "../FreeImage.h"
#pragma comment(lib, "d3d11.lib")

#ifndef _DEBUG
#define MUST(expression) (expression)
#else
#define MUST(expression) assert(SUCCEEDED(expression))
#endif

namespace Pipeline
{
	namespace
	{
		ID3D11Device*				Device;
		ID3D11DeviceContext*		DeviceContext;
		IDXGISwapChain*				SwapChain;

		namespace Buffer
		{
			ID3D11Buffer*			Vertex;
		}
		ID3D11InputLayout*			InputLayout;
		ID3D11VertexShader*			VertexShader;
		ID3D11PixelShader*			PixelShader;
		ID3D11RenderTargetView*		RenderTargetView;
	}

	LRESULT CALLBACK Procedure(HWND const hWnd,
							   UINT const uMessage,
							   WPARAM const wParam,
							   LPARAM const lParam)
	{
		switch (uMessage)
		{
		case WM_CREATE:
		{
			// Device, device context, swap chain ���� �ڵ��.
			{
				DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC();
				Descriptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
				Descriptor.BufferCount = 1;
				Descriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				Descriptor.OutputWindow = hWnd;
				Descriptor.Windowed = true;
				Descriptor.SampleDesc.Count = 1;

				MUST(D3D11CreateDeviceAndSwapChain(nullptr,
												   D3D_DRIVER_TYPE_HARDWARE,
												   nullptr,
												   0,
												   nullptr,
												   0,
												   D3D11_SDK_VERSION,
												   &Descriptor,
												   &SwapChain,
												   &Device,
												   nullptr,
												   &DeviceContext));
			}

			// Vertex buffer ����/���� �ڵ�� 1: ��ǥ ������ �Է�.
			{
				// Vertex ��ǥ ������.
				float const Coordinates[4][2]
				{
					{ -0.5f,  0.5f },
					{  0.5f,  0.5f },
					{ -0.5f, -0.5f },
					{  0.5f, -0.5f },
				};

				// Vertex buffer�� descriptor(���� 0).
				D3D11_BUFFER_DESC Descriptor
				{
					sizeof(Coordinates),
					D3D11_USAGE_IMMUTABLE,
					D3D11_BIND_VERTEX_BUFFER
				};

				D3D11_SUBRESOURCE_DATA SubResource{ Coordinates };
				ID3D11Buffer* Buffer = nullptr;
				MUST(Device->CreateBuffer(&Descriptor, &SubResource, &Buffer));

				const UINT Stride = sizeof(*Coordinates);
				const UINT Offset = 0;
				DeviceContext->IASetVertexBuffers(0, 1, &Buffer, &Stride, &Offset);
				Buffer->Release();
			}

			// Vertex buffer ����/���� �ڵ�� 2: ���� ������(�ؽ�ó) �Է�.
			{
				D3D11_BUFFER_DESC Descriptor
				{
					sizeof(float[4][2]),
					D3D11_USAGE_DYNAMIC,
					D3D11_BIND_VERTEX_BUFFER,
					D3D11_CPU_ACCESS_WRITE
				};

				MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Vertex));

				const UINT Stride = sizeof(float[2]);
				const UINT Offset = 0;
				DeviceContext->IASetVertexBuffers(1, 1, &Buffer::Vertex, &Stride, &Offset);
			}

			// �⺻ �������� ���� �ڵ��.
			{
				DeviceContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
			}

			// �Է� ���̾ƿ� �� vertex shader ����/���� �ڵ��.
			{
#include "../Shader/Bytecode/VertexShader.h"
				// �Է� ���̾ƿ�
				{
					D3D11_INPUT_ELEMENT_DESC Descriptor[2] =
					{
						{ "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0 },
						{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 1 }
					};

					MUST(Device->CreateInputLayout(Descriptor, 2, Bytecode, sizeof(Bytecode), &InputLayout));
					DeviceContext->IASetInputLayout(InputLayout);
				}

				// Vertex shader
				{
					MUST(Device->CreateVertexShader(Bytecode, sizeof(Bytecode), nullptr, &VertexShader));
					DeviceContext->VSSetShader(VertexShader, nullptr, 0);
				}
			}
			
			// Pixel shader ����/���� �ڵ��.
			{
#include "../Shader/Bytecode/PixelShader.h"
				MUST(Device->CreatePixelShader(Bytecode, sizeof(Bytecode), nullptr, &PixelShader));
				DeviceContext->PSSetShader(PixelShader, nullptr, 0);
			}

			// Shader resource view ����/���� �ڵ��.
			{
				FreeImage_Initialise();
				{
					FIBITMAP* Bitmap = FreeImage_Load(FREE_IMAGE_FORMAT::FIF_PNG, "Image/RockmanX/Sprite_Source.png");
					{
						FreeImage_FlipVertical(Bitmap);

						D3D11_TEXTURE2D_DESC Descriptor
						{
							FreeImage_GetWidth(Bitmap),
							FreeImage_GetHeight(Bitmap),
							1,
							1,
							DXGI_FORMAT_B8G8R8A8_UNORM,
							DXGI_SAMPLE_DESC{1},
							D3D11_USAGE_IMMUTABLE,
							D3D11_BIND_SHADER_RESOURCE
						};

						D3D11_SUBRESOURCE_DATA SubResource
						{
							FreeImage_GetBits(Bitmap),
							FreeImage_GetPitch(Bitmap)
						};

						ID3D11Texture2D* Texture2D = nullptr;
						MUST(Device->CreateTexture2D(&Descriptor, &SubResource, &Texture2D));
						{
							ID3D11ShaderResourceView* ShaderResourceView = nullptr;
							MUST(Device->CreateShaderResourceView(Texture2D, nullptr, &ShaderResourceView));
							DeviceContext->PSSetShaderResources(0, 1, &ShaderResourceView);
							ShaderResourceView->Release();
						}
						Texture2D->Release();
					}
					FreeImage_Unload(Bitmap);
				}
				FreeImage_DeInitialise();
			}

			return 0;
		}


		case WM_SIZE:
		{
			D3D11_VIEWPORT Viewport{ 0, 0, static_cast<float>LOWORD(lParam), static_cast<float>HIWORD(lParam) };
			DeviceContext->RSSetViewports(1, &Viewport);
			MUST(SwapChain->ResizeBuffers(1, LOWORD(lParam), HIWORD(lParam), DXGI_FORMAT_B8G8R8A8_UNORM, 0));

			// ���� Ÿ�� �� ���� �ڵ��.
			{
				ID3D11Texture2D* texture = nullptr;
				MUST(SwapChain->GetBuffer(0, IID_PPV_ARGS(&texture)));
				Device->CreateRenderTargetView(texture, nullptr, &RenderTargetView);
				DeviceContext->OMSetRenderTargets(1, &RenderTargetView, nullptr);
				texture->Release();
			}

			return 0;
		}


		case WM_APP:
		{
			{
				D3D11_MAPPED_SUBRESOURCE SubResource = D3D11_MAPPED_SUBRESOURCE();
				MUST(DeviceContext->Map(Buffer::Vertex, 0, D3D11_MAP_WRITE_DISCARD, 0, &SubResource));
				{
					static struct
					{
						float const Width = 34;
						float const Height = 50;
					}Frame;

					static unsigned Offset = 100;
					static unsigned Count = 0;
					static unsigned const CountPerMotion = 300;
					static unsigned Motion = Count / CountPerMotion;
					static unsigned NumMotions = 11;

					float const Coordinates[4][2] =
					{
						{ Frame.Width * (Count / CountPerMotion + 0), Offset + Frame.Height * 0 },	// �»��
						{ Frame.Width * (Count / CountPerMotion + 1), Offset + Frame.Height * 0 },	// ����
						{ Frame.Width * (Count / CountPerMotion + 0), Offset + Frame.Height * 1 },	// ���ϴ�
						{ Frame.Width * (Count / CountPerMotion + 1), Offset + Frame.Height * 1 }	// ���ϴ�
					};

					++Count;
					if (Count + 1 > CountPerMotion * NumMotions) Count = CountPerMotion;

					memcpy_s(SubResource.pData, SubResource.RowPitch, Coordinates, sizeof(Coordinates));
				}
				DeviceContext->Unmap(Buffer::Vertex, 0);
				MUST(SwapChain->Present(0, 0));

				float Color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
				DeviceContext->ClearRenderTargetView(RenderTargetView, Color);
				DeviceContext->Draw(4, 0);
			}
			return 0;
		}


		case WM_DESTROY:
		{
			RenderTargetView->Release();
			PixelShader->Release();
			VertexShader->Release();
			InputLayout->Release();
			Buffer::Vertex->Release();

			Device->Release();
			DeviceContext->Release();
			SwapChain->Release();

			PostQuitMessage(0);
			return 0;
		}


		default:
		{ return DefWindowProc(hWnd, uMessage, wParam, lParam); }
		}
	}
}