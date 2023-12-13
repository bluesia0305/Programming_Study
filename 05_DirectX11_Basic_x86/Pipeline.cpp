#include <d3d11.h>		// d3d11 ��� ���� Windows ����� ���ԵǾ�����(�ߺ� include ���ص� ��).
#include <cassert>		// ��ũ�� �Լ� assert()�� ����ϱ� ���� �߰��ϴ� ���.
#include "FreeImage.h"	// �پ��� �̹��� ���� ���Ŀ� ���� �����ϰ� ���α׷����� �� �ֵ��� ���� ���(���̺귯�� ���� �߰� �ʿ�).
#pragma comment(linker, "/entry:WinMainCRTStartup /subSystem:console")

// <���̺귯�� ���� ���>
// - d3d11.h ��� ������ �Լ��� ���ǰ� ���� ���� �Ǿ������Ƿ� �Լ��� ����ϱ� ���� ���̺귯���� ������ �ʿ�.
//   * ������Ʈ �Ӽ� -> ��Ŀ - ��� �ɼ� - �߰� ���Ӽ� �� '�� ��'�� d3d11.lib; �� �߰��ϰų� �Ʒ��� ���� �ڵ� �ۼ�.
#pragma comment(lib, "d3d11.lib")
//   (����� ���̺귯�� ������ �߰��ϴ� ���)
//	 * ������Ʈ �Ӽ� -> ��Ŀ - ��� �ɼ� - �߰� ���̺귯�� ���͸� ���� ���� ������.


// ��ȯ���� HRESULT ������ �Լ��� ���� ���� �߻� �� ���α׷� �ı��� ���� �Ʒ��� ���� ��ũ�� �Լ� �ۼ� �� ���.
#ifndef _DEBUG												// #ifndef == #if not defined.
#define MUST(expression) (expression)						// Release ����� �� ���๮.
#else
#define MUST(expression) assert(SUCCEEDED(expression))		// Debug ����� �� ���๮.
#endif

namespace Input
{
	void Procedure(HWND const, UINT const, WPARAM const, LPARAM const);

	namespace Get
	{ bool Down(WPARAM const); }
}

namespace Pipeline
{
	// ������ ����������(Rendering pipeline)
	// : ȭ�鿡 �׷����� �׷����� �ܰ躰 ����.
	//	  1) IA(Input assembler) Stage
	//	  2) VS(Vertex shader) Stage
	//	  3) HS(Hull shader) Stage  ������������������
	//	  4) TS(Tessellator) Stage			��	�������� �ڵ�����
	//	  5) DS(Domain shader) Stage		��	�̷������ �۾��� �ƴ�.
	//	  6) GS(Geometric shader) Stage		��
	//	  7) SO(Stream output) Stage  ��������������
	//	  8) RS(Rasterizer) Stage
	//	  9) PS(Pixel shader) Stage
	//	 10) OM(Output merge) Stage

	namespace
	{
		// <DirectX11�� ���ظ� ���� �⺻ ����>====================================================================================================
		//
		// (���߿�)
		// 1) COM �������̽� ����
		//	  - COM �������̽�(COM Interface)
		//		: ����ڰ� ���Ƿ� ���� �� �ִ� �ڷ����� �ƴ�(�������̽� = ������ ���� �ƹ� �͵� �������� �ʰ� ��ü�� ������ �� �ִ� �޼��� ����).
		//		  * �ش� �ڷ������� �����Ҵ��� �Ұ����ϴ�(�������̽��̱⵵ ������, �Ұ����ϵ��� �����Ҵ� ������ ��ü�� �����ε�).
		//		  * COM �������̽� ������ ��ü�� ����/����
		//			- ����: Descriptor ���� �� Create~ �Լ��� �̿��� ����(����̽�, ����̽� ���ؽ�Ʈ, ���� ü���� ��쿡�� D3D11Create~ �Լ�).
		//			- ����: {object}->Release() �޼��带 �̿��� ����.
		//
		//	  - ������(Descriptor, ������)
		//		: ���ҽ��� GPU���� Ư���Ǵ� ���Ŀ� �°� �������ִ� �淮�� �ڷᱸ��.
		//
		//--------------------------------------------------------------------------------------------------------------------------------------
		//
		// (���߿�)
		// 2) ������ ���������� ���� �ֿ� ��ü��
		//	  - ����̽�(Device) �� ID3D11Device* ����
		//		: ���ҽ��� ����� ���÷��� �����(�׷��� ī��)�� ����� �߻�ȭ �� ��ü.
		//		  * �׷��� ���ҽ��� ����, �׷��Ƚ� ���������� ����, ���̴� ����.
		// 
		//	  - ����̽� ���ؽ�Ʈ(Device context) �� ID3D11DeviceContext* ����
		//		: ����̽��� ���Ǵ� ��Ȳ �Ǵ� ������ �����ϴ� ��ü.
		//		  �� ��ü������, ����̽� ���ؽ�Ʈ�� ����̽��� ������ ���ҽ��� ����Ͽ�
		//		  ���������� ���¸� �����ϰ� ������ ����� �����Ѵ�.
		//		  * ����̽��� ���� ������ ��ü(�׷��� ���ҽ�, ���̴�)�� ���������� �� ����(Set~ �Լ�)�ϰ� �������� ����.
		//
		//	  - ���� ü��(Swap chain) �� IDXGISwapChain* ����
		//		: ����ڿ��� �������� ǥ���ϴ� �� ���Ǵ� ������ ����(frame buffer)�� �÷���.
		//		  * ���� ����(Front buffer): ���� ȭ�鿡 ��µǰ� �ִ� ������ ����.
		//		  * �ĸ� ����(Back buffer) : ���� ���۰� �ƴ� ����(���� ���α׷��� ���� ���ۿ� ���� ������� �ʰ� �ĸ� ���ۿ��� ���).
		//
		//	  - ���̴�(Shader)
		//		: �׷��� �ϵ������ ������ ȿ���� ����ϴ� �� ���Ǵ� ����Ʈ���� ����� ����.
		//		  * ������ ���̴�(Vertex shader) �� ID3D11VertexShader* ����
		//			: ������(=����) �����Ϳ� �������� ������ �����Ͽ� Ư���� ȿ���� �ִ� �� ���δ�.
		//		  * �ȼ� ���̴�(Pixel shader) �� ID3D11PixelShader* ����
		//			: �ȼ� ���̴� �ܰ�� ��� ����, �ؽ�ó ������, �Ǵ� �ȼ� ����� ���� ������ ���� �����Ͽ� �� �ȼ��� ������(�⺻������ ����)�� ����.
		// 
		//	  - ���ҽ�(Resource)
		//		: ���ҽ��� ����� �������ϴ� �� ���Ǵ� �ؽ�ó �� ����(��, ���̴��� ���޵Ǵ� ������)�� �ǹ��Ѵ�.
		//		  * ����(Buffer) �� ID3D11Buffer* ����
		//			: ���� ����, �ε��� ���� ���� ���� �� ���̴� ��� ���� ���Ǵ� ������(�̹����� �ƴ� ������).
		//			  (1) ������ ����(Vertex buffer)	: ���� ������ �����ϴ� �� ���Ǵ� ������ �����͸� ����.
		//			  (2) �ε��� ����(Index buffer)	: ������ ���ۿ� ���� ���� �������� ����(������ ȿ�������� �������ϴ� �� ���).
		//			  (3) ��� ����(Constant buffer)	: ���̴� ��� �����͸� ����.
		//		  * �ؽ�ó(Texture) �� ID3D11Texture1D*(�Ǵ� 2D, 3D) ����
		//			: �ؽ�ó ���ҽ��� �ؼ��� �����ϵ��� ����ȭ�� ������ ����(��, �̹��� ������)�̴�.
		// 
		//	  - ���ҽ� ��(Resource View) �� ���� ID3D11~* ����
		//		: ���ҽ��� ������ ���������ο� ���ε����� �� �ִ� ��ü��,
		//		  ���ҽ��� ��� ����� ��(= �ٶ� �� ������, View)������ ���Ͽ� ������ �� �ִ�.
		//		  * ���� Ÿ�� ��(Render target view, RTV)		: �ĸ� ���۸� ����ϱ� ���� ���������ο� ���ε��ϴ� �뵵(���� ������ ��´�).
		//		  * ���� ���ٽ� ��(Depth stencil view, DSV)		: ���� �� ���ٽ� ���ҽ��� �б� ���� ���(���̿� ���ٽ� ���� ��´�).
		//		  * ���̴� ���ҽ� ��(Shader resource view, SRV)  : �̹����� �б� ���� ���.
		//		  * ������ �׼��� ��(Unordered access view, UAV) : (������ �̹�����) �ؽ�ó�� �д� ���ÿ� ���� ���� ���.
		// 
		//	  - �Է� ���̾ƿ�(Input layout) �� ID3D11InputLayout* ����
		//		: ������ ���ۿ� ����� ���� ���ҽ�(Sub resource)�� �б� ���� ������ 1 stride ������,
		//		  �߰������� � �����Ͱ� ��ǥ �Ǵ� ������ ��Ÿ�������� �������ִ� �۾�.
		//	
		//	  - �� ��Ʈ(View port) �� D3D11_VIEWPORT ����
		//		: �������� ����� ȭ�� ������ ǥ���ϴ� ������(polygon).
		// 
		// 
		// 
		//--------------------------------------------------------------------------------------------------------------------------------------
		// 
		// 3) ��Ÿ
		//	  - ���� ���۸�(Double buffering, Swap chain ����)
		//		: �����̴� ����(����� �޴� �ð��� �ʹ� ª�� ȭ���� ����� �������� �������� �߻�)�� �ذ��ϱ� ����,
		//		  front/back buffer�� ����Ͽ� 1) �׸��� �۾���, 2) �ϼ��� �׸��� �������� ������ �и��ϴ� ��.
		// 
		//	  - DirectX �׷��� ������(DirectX Graphics Infrastructure, DXGI)
		//		: Ư�� �׷��� API�� �׷��� Ŀ�� ���� ����(ȣȯ��)�� �����ϴ� Microsoft Windows�� ����� ��� ���� ���.
		//		  DXGI�� �׷��� ����� �� ����� ����, ���÷��� ��� ����, ���� ���� ����, ���μ��� �� ���ҽ� ����,
		//		  �������� �������� ǥ���ϱ� ���� â �Ǵ� ����Ϳ� ǥ���ϴ� ���� �۾��� ó���� ��ü�� ����.
		// 
		//======================================================================================================================================


		ID3D11Device*				Device;
		ID3D11DeviceContext*		DeviceContext;
		IDXGISwapChain*				SwapChain;

		namespace Buffer
		{
			ID3D11Buffer*			Vertex;
			ID3D11Buffer*			Constant[3];

			template<typename Data>
			void Update(ID3D11Buffer* buffer, Data const& data)
			{
				D3D11_MAPPED_SUBRESOURCE SubResource = D3D11_MAPPED_SUBRESOURCE();
				// ������ ���ۿ� ����� ���� �����ϱ� ���� CPU�� ���������� Ǯ���ֱ� ���� �Լ�.
				MUST(DeviceContext->Map(buffer,						// ID3D11Resource*			  pResource			  : ������ ������ ������.
										0,							// UINT						  Subresource		  : ���� ���ҽ�
										D3D11_MAP_WRITE_DISCARD,	// D3D11_MAP				  MapType			  : CPU���� �а� ���� ���� �׼����� ���ҽ� �ĺ� ���.
																	//													* ~_READ			   : ���ҽ��� �б� ���� ����(D3D11_CPU_ACCESS_READ).
																	//													* ~_WRITE			   : ���ҽ��� ���⸦ ���� ����(D3D11_CPU_ACCESS_WRITE).
																	//													* ~_READ_WRITE		   : ���ҽ��� �а� ���� ���� ����(D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE).
																	//													* ~_WRITE_DISCARD	   : ���ҽ��� ���� ���� ����(���� ���ҽ� ����, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE).
																	//													* ~_WRITE_NO_OVERWRITE : ���ҽ��� ���� ���� ����(����� �Ұ���, D3D11_CPU_ACCESS_WRITE).
										0,							// UINT						  MapFlags			  : (����).
										&SubResource));				// D3D11_MAPPED_SUBRESOURCE*  pMappedResource = 0 : ���� ���ҽ��� ������ ������ ������

				memcpy_s(SubResource.pData,				// void* const		  _Destination	   : ������� ���� ���ҽ��� pData.
						 SubResource.RowPitch,			// rsize_t const	  _DestinationSize : ������� ���� ���ҽ��� RowPitch.
						 data,							// void const* const  _Source		   : ����� ������.
						 sizeof(data));					// rsize_t const	  _SourceSize	   : ����� �������� ũ��.

				DeviceContext->Unmap(buffer, 0);
			}
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
		case WM_MOUSEWHEEL: case WM_MOUSEHWHEEL: case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN: case WM_LBUTTONUP: case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDOWN: case WM_RBUTTONUP: case WM_RBUTTONDBLCLK:
		case WM_MBUTTONDOWN: case WM_MBUTTONUP: case WM_MBUTTONDBLCLK:
		case WM_XBUTTONDOWN: case WM_XBUTTONUP: case WM_XBUTTONDBLCLK:
		case WM_SYSKEYDOWN: case WM_SYSKEYUP:	// Ctrl, Alt ��ư�� �Բ� Ű���尡 ������(��������) ��쿡 �߻��ϴ� �޼���
		case WM_KEYDOWN: case WM_KEYUP:
		{
			Input::Procedure(hWnd, uMessage, wParam, lParam);
			return 0;
		}


		case WM_CREATE:
		{
			// Rendering pipeline �ʱ� ����.
			// - Device, DeviceContext, SwapChain ���� �ڵ��.
			{
				// Swap chain�� descriptor(device, device context, swap chain ��ü�� ��� ������).
				DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC();	// �⺻������ �����ϱ� ���� ����Ʈ ������ ȣ���Ͽ� ��ü ����.


				// <DXGI_SWAP_CHAIN_DESC ����ü�� ��� ����>
				// : DXGI_SWAP_CHAIN_DESC ���� ������� �⺻������ �ʱ�ȭ�� �Ǹ�, �Ʒ��� ���� �������� �ڵ����� ����ȴ�.
				// 
				// 1) DXGI_MODE_DESC BufferDesc
				//	  - UINT Width, Height		  : �⺻��(= 0)�� ���: ���� â�� ��ü '�۾�����' ���÷��� ũ��� �ڵ� ������.
				//	  - DXGI_RATIONAL RefreshRate : �⺻��(= 0, �̶� Numerator = 0, Denominator = 1)�� ���, �ڵ� ������(FPS)���� ������.
				//	  - DXGI_MODE_SCALING Scaling :
				//		* ~_UNSPECIFIED : (�⺻��) â ũ�� ��ȭ�� ���� ���� ��ȭ ������ �»�� ��ǥ�� ���� ���.
				//		* ~_CENTERED = â ũ�� ��ȭ�� ���� ���� ��ȭ�� ������, ȭ�� ���� ������ �������� Ȯ�� �� ���
				//		* ~_STRETCHED = â ũ�� ��ȭ�� ���� ������ ����.
				//	  - DXGI_MODE_SCANLINE_ORDER ScanlineOrdering :
				//		* ~_UNSPECIFIED : (�⺻��) ���÷��̿� ���� �Ʒ� ���� �߿��� �ڵ����� ����.
				// 		* ~_PROGRESSIVE : �����ֻ�.
				//		* ~_UPPER_FIELD_FIRST: ����ֻ�(interlaced) -> Ȧ�� �ʵ�(upper field)�� ���� ����� �� ������ ���.
				//		* ~_LOWER_FIELD_FIRST: ����ֻ�(interlaced) -> ¦�� �ʵ�(lower field)�� ���� ����� �� ������ ���.
				//
				// 2) UINT Flags: �߰����� ����� ����� �������� ����(������� ���� �� �⺻�� = 0���� ���).
				//
				// 3) DXGI_SWAP_EFFECT SwapEffect: ȭ���� �Ѱ��ְ� ���� �����͸� ������ ���� �������� ����.
				//	  - DXGI_SWAP_EFFECT_DISCARD = �⺻��. ȭ���� �Ѱ��ְ� ���� �����͸� ����.
				//	  - DXGI_SWAP_EFFECT_SEQUENTIAL = ȭ���� �Ѱ��� �ڿ��� �����͸� ������ ����.
				//
				// 4) DXGI_SAMPLE_DESC SampleDesc: SampleDesc�� �󸶳� �����ϰ� �ٷ� �������� ����(��� ����� ����).
				//	  (Super-sampling: ȭ���� Ȯ���Ű�� ���� �ʱ� �ȼ� ũ���� Ȯ��� �ȼ��� �ɰ� �� ȭ���� ���(����� �ſ� ����, DX������ ���� ���ϴµ�?),
				//	   Multi-sampling: �׵θ��� ���ؼ��� �ȼ��� �ɰ��� ��� ������ �ذ� -> ��� DX11 ����̽����� ����)
				//	  - Count = �ȼ��� �� ���� �ɰ� �������� ����(1 = ��Ƽ ���ø��� ������� ����).
				//	  - Quality = ��Ƽ ���ø��� �󸶳� ��������� ����(0 ~ 1 ������ ��, �������� �� ���� ���).


				// BufferDesc.Format: �ȼ��� �Ҵ�� ���� � �������� ���� �������� ���� ������ ������ �� �ִ�(��, ����ǥ�� ��� ������ ������) ��� ����.
				Descriptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;		// RGBA(R, G, B, Alpha = ����) ���� 0 ~ 255�� 256 �ܰ�(unsigned char = 8 bit)�� ����.
																				// UNORM: Unsigned, normalized(�ִ밪�� 1�� ǥ��ȭ�� ��) �� �ǹ�.

				Descriptor.BufferCount		= 1;								// ���۸� '�߰�'�� ������ ����(�⺻�� = 0 -> 1 ���� ���۸� ���).
				Descriptor.BufferUsage		= DXGI_USAGE_RENDER_TARGET_OUTPUT;	// ���۸� ��� ����� �������� ����(���� Ÿ�� ����ϴ� �뵵�� ����).
				Descriptor.OutputWindow		= hWnd;								// ����� �������� �ڵ�.
				Descriptor.Windowed			= true;								// â ��带 ����� ������ ����.
				Descriptor.SampleDesc.Count = 1;								// �����ڸ� ���� ��ü ������, �⺻���� 0���� �ʱ�ȭ �ǹǷ� 1�� ������ ��.

				// <DirectX�� ��� ����(feature level) ���� ����>
				// : �Ϲ������� ������ ���� ������ ��� ���� �迭�� ��Ҹ� �ʱ�ȭ�Ѵ�.
				//	 ��� ���� �迭(featureLevels)�� �Ʒ� ������ ���� ���� �����ص� ������,
				//	 D3D11CreateDeviceAndSwapChain �Լ��� ���� pFeatureLevels = nullptr�� �����ϴ� ���,
				//	 �⺻������ ���Ǵ� ��� ���� �迭�� �Ʒ��� �迭�� �����ϴ�.
				D3D_FEATURE_LEVEL featurelevels[] = { D3D_FEATURE_LEVEL_11_0,
													  D3D_FEATURE_LEVEL_10_1,
													  D3D_FEATURE_LEVEL_10_0,
													  D3D_FEATURE_LEVEL_9_3,
													  D3D_FEATURE_LEVEL_9_2,
													  D3D_FEATURE_LEVEL_9_1 };

				// HRESULT: S_OK, S_FALSE�� ������ ��ȯ�ϴ� �ڷ���(long�� typedef ����).
				// assert(expression): (cassert ��� ���� ��ũ�� �Լ�)
				//					   - Debug ���: expression�� ���̸� �Ѿ�� �����̸� ����.
				//					   - Release ���: �ƹ� ���۵� �������� ����((void)0 ���� ġȯ��).
				//					     * ��, Debug ���(����� ���)�� Release ���(���� ����)�� �� �۵� ����� �ٸ��Ƿ�
				//						   ��ó���� ����� ���� ���е� �Լ� ����� �ʿ��ϴ�(��ó���� MUST ��ũ�� �Լ� ����).
				// 
				// SUCCEEDED(): (cassert ��� ���� ��ũ�� �Լ�)
				//				HRESULT�� ������ long�̹Ƿ�, �̸� bool �������� �ٲ��ֱ� ���� �Լ�(S_OK�� �� true ��ȯ, S_FALSE�� �� false ��ȯ).
				MUST(D3D11CreateDeviceAndSwapChain(nullptr,						// IDXGIAdapter*				pAdapter		   : �׷��� ī�带 ������ �� ���(���� �׷��� ī�� ���� nullptr).
												   D3D_DRIVER_TYPE_HARDWARE,	// D3D_DRIVER_TYPE				DriverType		   : ����̹� Ÿ��.
												   								//												     * ~_HARDWARE  : �ϵ����� �̾Ƴ�(���� �ӵ�, ��Ȯ�� ����).
												   								//												     * ~_REFERENCE : �ϵ����� ���۷����� ��ģ��(���� �ӵ�, ��Ȯ�� ����).
												   								//												     * ~_NULL	   : ����̹� Ÿ���� ����(����� ����).
												   								//												     * ~_SOFTWARE  : DirectX�� �ƴ� �ٸ� ����Ʈ����κ��� �ҷ���(�ſ� ���� �ӵ�).
												   								//												     * ~_WARP	   : Rasterizing ���� �ְ������� ���� �� ���(���������� ���).
												   nullptr,						// HMODULE						Software		   : ������ ������ software�� hInstance(������� ������ nullptr).
												   0,							// UINT							Flags			   : �߰����� ����(�����Ƿ� 0 ���).
												   featurelevels,				// const D3D_FEATURE_LEVEL*		pFeatureLevels	   : DirectX ������ ȣȯ��(��� ����)�� ����(��� ���� �迭(featurelevels) ����).
												   6,							// UINT							FeatureLevels	   : pFeatureLevels�� ����� ����(nullptr�� ���� 0 ����).
												   D3D11_SDK_VERSION,			// UINT							SDKVersion		   : (�׻�) D3D11_SDK_VERSION ���� ����.
												   &Descriptor,					// const DXGI_SWAP_CHAIN_DESC*	pSwapChainDesc	   : Swap chain�� descriptor�� ������.
												   &SwapChain,					// IDXGISwapChain**				ppSwapChain		   : (���� ������) Swap chain�� ������.
												   &Device,						// ID3D11Device**				ppDevice		   : (���� ������) Device�� ������.
												   nullptr,						// D3D_FEATURE_LEVEL*			pFeatureLevel	   : �����ϴ� ��� ���� �迭�� ù ��° ��Ҹ� ��Ÿ���� D3D_FEATURE_LEVEL��
												   								//													 �����͸� ��ȯ�� ����(��� ������ ������ �ʿ� ������ nullptr).
												   &DeviceContext));			// ID3D11DeviceContext**		ppImmediateContext : (���� ������) Device context�� ������.
												   
												   // <Device, DeviceContext, SwapChain�� ���õ� ���ڸ� ���� ������ �������� �����ϴ� ����?>
												   // : D3D11CreateDeviceAndSwapChain �Լ� ������ �Ű������� ���޵Ǿ� ���� ���� �ٸ� ������ �����ؾ��ϴµ�
												   //   �̶�, �ش� �Լ��� ����Ǹ� �Ű������� �޸� ������ �����ǹǷ� ���� ������� �ʴ´�.
												   //   ���� ������ ������ ������ ����� ���� �Լ� ������ ������ �� �ֵ��� �ϱ� ���� ���ڷ� ���� ������ �������� �����Ѵ�.
			}

			// Vertex buffer(������ ��ǥ) ���� �ڵ��.
			{
				// ������ ��ǥ���� ������ ���� ����(�̹��� ���� �ε� -> ������ �ؽ�ó��).
				float const Coordinates[4][2]
				{
					{ -0.5f,  0.5f },
					{  0.5f,  0.5f },
					{ -0.5f, -0.5f },
					{  0.5f, -0.5f },
				};

				// Vertex buffer�� descriptor(���� 0�� ���� �����͸��� �Է�).
				D3D11_BUFFER_DESC Descriptor
				{
					sizeof(Coordinates),			// UINT			ByteWidth			: ������ ���� �����͸� ���� ũ��.
					D3D11_USAGE_IMMUTABLE,			// D3D11_USAGE	Usage				: ������ �� ����Ǵ� ���ҽ��� ��� ������ �ĺ�.
					 								//									  * ~_DEFAULT   : GPU�� �б� �� ���� �׼����� �ʿ��� ���ҽ�.
					 								//									  * ~_IMMUTABLE : GPU������ ���� �� �ִ� ���ҽ��Դϴ�.
					 								//									  * ~_DYNAMIC   : GPU�� CPU ���ÿ� �а� ���� ����.
					 								//									  * ~_STAGING   : GPU���� CPU���� �� ���� �������� ����.
					D3D11_BIND_VERTEX_BUFFER		// UINT			BindFlags			: ���ҽ��� ���������ο� ���ε��ϴ� ����� �ĺ�.
													// UINT			CPUAccessFlags		: ���ҽ��� ���Ǵ� CPU �׼��� ������ ����.
													//									  * ~_WRITE : CPU���� �а� ���� ������ ���ҽ�.
													//									  * ~_READ  : CPU���� �б� ������ ���ҽ�.
					 								// UINT			MiscFlags			: (����� ��� �� ��).
					 								// UINT			StructureByteStride	: (����� ��� �� ��) ����ȭ�� ������ ��� �� ����Ʈ�� ���� ������ ����.
				};

				D3D11_SUBRESOURCE_DATA SubResource
				{
					Coordinates						// const void*  pSysMem			 : �ش� �����Ϳ� ����Ǿ��ִ� �ּҸ� �����Ͽ� �޸𸮸� ����.
													// UINT			SysMemPitch		 : .
													// UINT			SysMemSlicePitch : .
				};

				ID3D11Buffer* Buffer = nullptr;		// �̹����� ��� ���簢���� ��ǥ�� �����ϴ� �� ����� vertex buffer.
				MUST(Device->CreateBuffer(&Descriptor,		// const D3D11_BUFFER_DESC*		  pDesc		   : ������ descriptor�� ������.
										  &SubResource,		// const D3D11_SUBRESOURCE_DATA*  pInitialData : ���� �ʱ�ȭ�ϱ� ���� �ʿ��� ���� ���ҽ�(�� ����).
										  &Buffer));		// ID3D11Buffer**				  ppBuffer	   : (���� ������) Vertex buffer�� ������.

				const UINT Stride = sizeof(*Coordinates);
				const UINT Offset = 0;
				DeviceContext->IASetVertexBuffers(0,				// UINT					 StartSlot		 : ���ε��� ���� ù ��° �Է� ����(0���� ����).
												  1,				// UINT					 NumBuffers		 : �迭 ���� ���� ������ ��.
												  &Buffer,			// ID3D11Buffer* const*	 ppVertexBuffers : Vertex buffer�� �迭�� ���� ������.
												  &Stride,			// const UINT*			 pStrides		 : ���� ���� �迭�� ���� ������(���� �ϳ��� �����͸� ���� �� �� ����Ʈ�� ����������).
												  &Offset);			// const UINT*			 pOffsets		 : ������ ���� �迭�� ���� ������(�������̶� ù ��Ҷ� �ٸ� ���� ���).
				Buffer->Release();
			}

			// Vertex buffer(�ؽ�ó ���ҽ�) ���� �ڵ��.
			{
				//// ���� �̹��� - ���� ���ҽ� �ʿ�.
				//float const Texcoord[4][2]
				//{
				//	{ 0.0f, 0.0f },
				//	{ 500.0f, 0.0f },
				//	{ 0.0f, 500.0f },
				//	{ 500.0f, 500.0f }
				//};
				//D3D11_BUFFER_DESC Descriptor{ sizeof(Texcoord), D3D11_USAGE_IMMUTABLE, D3D11_BIND_VERTEX_BUFFER };
				//D3D11_SUBRESOURCE_DATA SubResource{ Texcoord };
				//MUST(Device->CreateBuffer(&Descriptor, &SubResource, &Buffer::Vertex));
				
				// ���� �̹��� - ���� ���ҽ��� �ʿ� ����.
				D3D11_BUFFER_DESC Descriptor{ sizeof(float[4][2]), D3D11_USAGE_DYNAMIC, D3D11_BIND_VERTEX_BUFFER, D3D11_CPU_ACCESS_WRITE };
				MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Vertex));

				const UINT Stride = sizeof(float[2]);
				const UINT Offset = 0;
				DeviceContext->IASetVertexBuffers(1, 1, &Buffer::Vertex, &Stride, &Offset);
			}

			// �⺻ �������� ���� �ڵ��.
			{
				// �⺻ ��������(Primitive topology)
				// : ������ � �������� �ؼ��� �������� ���� ����.
				//	 * ~_TRIANGLELIST  : ������ ������ ������ �ﰢ������ �ν�
				//	 * ~_TRIANGLESTRIP : ������ ������ ��� ����� �ﰢ������ �ν�.
				DeviceContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
			}

			// Vertex shader ���� �ڵ��.
			{
#include "Shader/Bytecode/VertexShader.h"
				// ���̾ƿ� ����.
				{
					// InputLayout�� descriptor �迭(������ �����Ͱ� ��ǥ�� ���� �� ���� �����ͷ� �����ǹǷ�, 2�� ��Ҹ� ���� �迭�� ����)
					D3D11_INPUT_ELEMENT_DESC Descriptor[2]
					{
						{
							"POSITION",					// LPCSTR					   SemanticName			: �ش� ������(��ǥ �Ǵ� ����)�� HLSL������ �ø�ƽ ����.
							0,							// UINT						   SemanticIndex		: �ش� �������� �ø�ƽ �ε���(���� �������Ƿ� 0).
							DXGI_FORMAT_R32G32_FLOAT,	// DXGI_FORMAT				   Format				: ��ǥ(�Ǵ� ����)�� � �������� ���� ������ ����.
							0							// UINT						   InputSlot			: 
														// UINT						   AlignedByteOffset	: �����͸� �д� ���������� �ʱ� �ּҷκ����� ����Ʈ �ּ� ����(������).
														// D3D11_INPUT_CLASSIFICATION  InputSlotClass		: 
														// UINT						   InstanceDataStepRate : (����).
						},

						// ���� ������ ����ü���� ���
						{
							"TEXCOORD",
							0,
							DXGI_FORMAT_R32G32_FLOAT,
							1
						}
					};

					MUST(Device->CreateInputLayout(Descriptor,			// const D3D11_INPUT_ELEMENT_DESC*  pInputElementDescs				  : Input layout�� descriptor�� ������(���� �迭�̹Ƿ� �̸� ����).
												   2,					// UINT								NumElements						  : Input layout�� descriptor �迭�� ����� ����.
												   Bytecode,			// const void*						pShaderBytecodeWithInputSignature : ���̴� �����ڵ��� ������.
												   sizeof(Bytecode),	// SIZE_T							BytecodeLength					  : �����ڵ��� ����
												   &InputLayout));		// ID3D11InputLayout**				ppInputLayout					  : Input layout�� ������.

					// ���̾ƿ� ���� �Լ� ��ü�� IA �ܰ迡 ��������, �����ڵ� ���� ������ �ʿ��ϹǷ� VS �ܰ迡�� ����.
					DeviceContext->IASetInputLayout(InputLayout);		// ��� �������� �ν��Ͻ�ȭ �� input layout.
				}

				// Vertex shader ����.
				{
					MUST(Device->CreateVertexShader(Bytecode,			// const void*			 pShaderBytecode : ���̴� �����ڵ��� ������.
													sizeof(Bytecode),	// SIZE_T				 BytecodeLength  : �����ڵ��� ����.
													nullptr,			// ID3D11ClassLinkage*	 pClassLinkage   : (����).
													&VertexShader));	// ID3D11VertexShader**  ppVertexShader  : Vertex shader�� ������.
					DeviceContext->VSSetShader(VertexShader, nullptr, 0);
				}
			}

			// Constant buffer ���� �ڵ��(D3D11_USAGE_DYNAMIC).
			{
				D3D11_BUFFER_DESC Descriptor{ sizeof(float[4][4]), D3D11_USAGE_DYNAMIC, D3D11_BIND_CONSTANT_BUFFER, D3D11_CPU_ACCESS_WRITE };
				for (UINT8 i = 0; i < 3; ++i)
				{
					MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Constant[i]));
					DeviceContext->VSSetConstantBuffers(i, 1, &Buffer::Constant[i]);
				}
			}

			// Pixel shader ���� �ڵ��.
			{
#include "Shader/Bytecode/PixelShader.h"
				MUST(Device->CreatePixelShader(Bytecode,			// const void*			pShaderBytecode : ���̴� �����ڵ��� ������.
											   sizeof(Bytecode),	// SIZE_T				BytecodeLength  : �����ڵ��� ����.
											   nullptr,				// ID3D11ClassLinkage*  pClassLinkage   : (����).
											   &PixelShader));		// ID3D11PixelShader**  ppPixelShader   : Pixel shader�� ������.

				DeviceContext->PSSetShader(PixelShader,		// ID3D11PixelShader*			pPixelShader	  : ��� �������� �ν��Ͻ�ȭ �� pixel shader.
										   nullptr,			// ID3D11ClassInstance* const*  ppClassInstances  : (����).
										   0);				// UINT							NumClassInstances : (����).
			}

			// �̹��� ���� �ڵ��.
			{
				FreeImage_Initialise();
				{
					// (����) PNG, WAV ������ ��� ���� �����͸� �������� �ʴ� ��������, ���� ���߿��� ���� ���� �̿��Ѵ�.

					FIBITMAP* Bitmap = FreeImage_Load(FREE_IMAGE_FORMAT::FIF_PNG,	// FREE_IMAGE_FORMAT  fif	   : �̹��� ������ ����(Ȯ���ڿ� ���� ����).
													  "Image/Player.png");			// const char*		  filename : �̹��� ���� (���)���.

					// �ε��� �̹����� �ؽ�ó�� ����� �ڵ��.
					{
						// �̹����� ó�� �ε��ϸ� �������� �������������Ƿ�, �ٽ� ��������.
						FreeImage_FlipVertical(Bitmap);

						D3D11_TEXTURE2D_DESC Descriptor = D3D11_TEXTURE2D_DESC();
						Descriptor.Width			= FreeImage_GetWidth(Bitmap);
						Descriptor.Height			= FreeImage_GetHeight(Bitmap);
						Descriptor.MipLevels		= 1;								// (����) �Ӹ�(MipMap) -> �̸� ��ҽ��Ѽ� �����ִ� ��� ����(������� �����Ƿ� 1).
						Descriptor.ArraySize		= 1;								// (����) ��ī�� �ڽ�(Sky box)
						Descriptor.Format			= DXGI_FORMAT_B8G8R8A8_UNORM;
						Descriptor.SampleDesc.Count = 1;
						Descriptor.Usage			= D3D11_USAGE_IMMUTABLE;
						Descriptor.BindFlags		= D3D11_BIND_SHADER_RESOURCE;

						D3D11_SUBRESOURCE_DATA SubResource
						{
							FreeImage_GetBits(Bitmap),		// const void *pSysMem	 : .
							FreeImage_GetPitch(Bitmap)		// UINT SysMemPitch		 : BITMAP�� ������ �������� ����(stride�� ����� ����).
															// UINT SysMemSlicePitch : .
						};

						ID3D11Texture2D* Texture2D = nullptr;
						MUST(Device->CreateTexture2D(&Descriptor,	// const D3D11_TEXTURE2D_DESC*	  pDesc		   : Texture2D�� descriptor�� ������.
													 &SubResource,	// const D3D11_SUBRESOURCE_DATA*  pInitialData : Texture2D�� ���� ���ҽ� ������(�̹��� ������)�� ������.
													 &Texture2D));	// ID3D11Texture2D**			  ppTexture2D  : (���� ������) Texture2D�� ������.
						{
							ID3D11ShaderResourceView* ShaderResourceView = nullptr;
							MUST(Device->CreateShaderResourceView(Texture2D,				// ID3D11Resource*						   pResource			: .
																  nullptr,					// const D3D11_SHADER_RESOURCE_VIEW_DESC*  pDesc				: .
																  &ShaderResourceView));	// ID3D11ShaderResourceView**			   ppShaderResourceView : (���� ������) ShaderResourceView�� ������. 
							{
								DeviceContext->PSSetShaderResources(0,						// UINT								StartSlot			 : .
																	1,						// UINT								NumViews			 : .
																	&ShaderResourceView);	// ID3D11ShaderResourceView* const  ppShaderResourceView : .
							}
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


		case WM_APP:
		{
			MUST(SwapChain->Present(0,		// UINT	 SyncInterval : ���� ����� ������ ǥ�ø� ����ȭ�ϴ� ����� ����(���۷� ������ ����, �� Ŀ�� ���� ���ð��� ������� ȿ��).
									0));	// UINT	 Flags		  : �߰����� ����(�����Ƿ� 0).

			// �÷� �迭(RGBA ��) ���� �ڵ��.
			float Color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
				
			// ���� Ÿ���� ��� ��Ҹ� �ϳ��� ������ �����ϴ� �Լ�.
			DeviceContext->ClearRenderTargetView(RenderTargetView,		// ID3D11RenderTargetView*	pRenderTargetView : Render target view.
												 Color);				// const float*				ColorRGBA		  : ������ ��Ÿ���� �迭(RGBA).

			// ��������Ʈ �̹��� �������� TEXCOORD ���� �ڵ��.
			{
				// ����ü �ڷ����� ����� ���� �ƴ�, ���Ϸ� �����ϰ� �Ǵ� ����ü�� ������ ����.
				static struct
				{
					float const Width  = 84;
					float const Height = 120;
				}Frame;

				static unsigned Count		   = 0;		// ���� ������ ī��Ʈ
				static unsigned CountPerMotion = 500;	// Frame per motion
				static unsigned Motion		   = 12;	// �ִϸ��̼��� 12 ���� �����Ǿ��ֱ� ����.

				float const Coordinates[4][2] =
				{
					{ Frame.Width * (Count / CountPerMotion + 0), Frame.Height * 0 },	// �»��
					{ Frame.Width * (Count / CountPerMotion + 1), Frame.Height * 0 },	// ����
					{ Frame.Width * (Count / CountPerMotion + 0), Frame.Height * 1 },	// ���ϴ�
					{ Frame.Width * (Count / CountPerMotion + 1), Frame.Height * 1 }	// ���ϴ�
				};

				Count += 1;
				if (Count > CountPerMotion * Motion - 1) Count = 0;

				Buffer::Update(Buffer::Vertex, Coordinates);
			}

			// Constant buffer(���� ��ǥ ��ȯ) ���� �ڵ��.
			{
				static float sx = 84;
				static float sy = 120;
				
				static float dx = 0.0f;
				static float dy = 0.0f;

				if (Input::Get::Down(VK_UP)) dy += 0.03f;
				if (Input::Get::Down(VK_DOWN)) dy -= 0.03f;
				if (Input::Get::Down(VK_LEFT)) dx -= 0.03f;
				if (Input::Get::Down(VK_RIGHT)) dx += 0.03f;

				// (Linear) Transform: Scale(����), rotation(����), translation(�����̵�).
				// (���߿�) ���켱������ ������ �Է��ϱ� ���� ���� ��ȯ����� ��ġ��ķ� ����.
				float const Transform[4][4] =
				{
					sx,		0,		0,		dx,
					0,		sy,		0,		dy,
					0,		0,		1,		0,
					0,		0,		0,		1
				};

				Buffer::Update(Buffer::Constant[0], Transform);
			}

			// Constant buffer(ī�޶� ��ǥ ��ȯ) ���� �ڵ��.
			{
				static float dx = 0.0f;
				static float dy = 0.0f;

				//dx -= 0.005f;

				// ī�޶� ��ǥ�� ĳ������ �̵� ����� �ݴ�� �̵���Ű�� ĳ���Ͱ� �����̴� �� ���� ȿ��.
				float const Transform[4][4] =
				{
					1,	0,	0,	dx,
					0,	1,	0,	dy,
					0,	0,	1,	0,
					0,	0,	0,	1
				};

				Buffer::Update(Buffer::Constant[1], Transform);
			}

			// Constant buffer(��������) ���� �ڵ��.
			{
				static float X = 2.0f / 500.0f;
				static float Y = 2.0f / 500.0f;

				float const Transform[4][4] =
				{
					X,	0,	0,	0,
					0,	Y,	0,	0,
					0,	0,	1,	0,
					0,	0,	0,	1
				};

				Buffer::Update(Buffer::Constant[2], Transform);
			}
			
			DeviceContext->Draw(4,		// UINT  VertexCount	: �׸� ������ ����.
								0);		// UINT  VertexLocation : ������ ��ġ.

			// �ӽ� �ڵ��.
			{
				static float sx = 84 / 3;
				static float sy = 120 / 3;

				static float dx = 100;
				static float dy = 100;

				// (Linear) Transform: Scale(����), rotation(����), translation(�����̵�).
				float const Transform[4][4] =
				{
					sx,		0,		0,		dx,
					0,		sy,		0,		dy,
					0,		0,		1,		0,
					0,		0,		0,		1
				};
				Buffer::Update(Buffer::Constant[0], Transform);
			}
			DeviceContext->Draw(4, 0);

			return 0;
		}


		case WM_SIZE:
		{
			// �� ��Ʈ ���� �ڵ��.
			{
				// �� ��Ʈ�� ũ�⸦ ���ۿ� �����ϰ� ����
				D3D11_VIEWPORT Viewport
				{
					0.0f,									// FLOAT TopLeftX;
					0.0f,									// FLOAT TopLeftY;
					static_cast<FLOAT>LOWORD(lParam),		// FLOAT Width;
					static_cast<FLOAT>HIWORD(lParam)		// FLOAT Height;
															// FLOAT MinDepth;
															// FLOAT MaxDepth;
				};
				
				DeviceContext->RSSetViewports(1,			// UINT					  NumViewports : View port�� ����.
											  &Viewport);	// const D3D11_VIEWPORT*  pViewports   : View port�� ������.
			}

			// Buffer Resizing.
			{
				MUST(SwapChain->ResizeBuffers(1,							// UINT			BufferCount	   : Descriptor.BufferCount ���� ������ ��(buffer�� 1���� 0, 2���� 1, ... / index�� �����ϸ� ����).
											  LOWORD(lParam),				// UINT			Width		   : ���콺�� ���� x ��ǥ.
											  HIWORD(lParam),				// UINT			Height		   : ���콺�� ���� y ��ǥ.
											  								//								 * â�� ����� �� ���콺�� �׻� right, bottom�� ��ġ�ϰ� �ǹǷ�
																			//								   ���콺�� ����� ��ǥ�� â�� ����Ǵ� width, height�� �׻� ����.
											  DXGI_FORMAT_B8G8R8A8_UNORM,	// DXGI_FORMAT	NewFormat	   : �����͸� �д� format(DXGI_SWAP_CHAIN_DESC ����).
											  0));							// UINT			SwapChainFlags : �߰����� ����(�����Ƿ� 0 ���).
			}


			// ���� Ÿ�� �� ���� �ڵ��.
			{
				ID3D11Texture2D* texture = nullptr;
				MUST(SwapChain->GetBuffer(0,							// UINT		  Buffer	  : DISCARD �ɼ��� ����ϴ� ��� 0�� ����.
										  IID_PPV_ARGS(&texture)));		// const IID  &riid		  : Texture2D ����ü�� ID�� ����.
																		// void		  **ppSurface : (����).
				{
					Device->CreateRenderTargetView(texture,				// ID3D11Resource*						pResource : Render target�� ��Ÿ���� ID3D11Resource�� ������.
												   nullptr,				// const D3D11_RENDER_TARGET_VIEW_DESC	pDesc	  : Render target view�� ��Ÿ���� D3D11_RENDER_TARGET_VIEW_DESC�� ������.
												   &RenderTargetView);	// ID3D11RenderTargetView**				ppRTView  : (���� ������) Render target view�� ������.
				}
				texture->Release();

				DeviceContext->OMSetRenderTargets(1,					// UINT							   NumViews			   : ���ε��� render target�� ��(ppRenderTargetViews �迭�� ����� ������ ����).
												  &RenderTargetView,	// ID3D11RenderTargetView* const*  ppRenderTargetViews : (���� ������) Render target view�� ������(���� ��� nullptr).
												  nullptr);				// ID3D11DepthStencilView*		   pDepthStencilView   : Depth stencil view(���� ��� nullptr).
			}

			return 0;
		}


		case WM_DESTROY:
		{
			// �Ϲ������� COM interface�� ��ü�� ���� ������ �������� �����Ѵ�(�Ļ� Ŭ������ �Ҹ��� ȣ��� ����� ����).
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