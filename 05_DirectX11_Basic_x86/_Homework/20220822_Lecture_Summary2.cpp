#include <d3d11.h>		// d3d11 ��� ���� Windows ����� ���ԵǾ�����(�ߺ� include X).

namespace Pipeline
{
	namespace
	{
		// COM interface: ����ڰ� ���Ƿ� ���� �� �ִ� �ڷ����� �ƴ�(�������̽� = ������ ���� �ƹ� �͵� �������� �ʰ� ��ü�� ������ �� �ִ� �޼��� ����).
		//				  * �ش� �ڷ������� �����Ҵ� ���� �� ����(abstract�̹Ƿ� �ν��Ͻ�ȭ�� �� ����).
		//				  * Create()�� ����� Release()�� �����Ѵ�.
		//				  * ������(Descriptor, ������): �ڿ��� GPU���� Ư���Ǵ� ���Ŀ� �°� �������ִ� �淮�� �ڷᱸ��.

		ID3D11Device* Device;					// ������ ������������ �����ϱ� ���� ���.
		ID3D11DeviceContext* DeviceContext;		// ������ ������������ ���� ������ ���ս�Ű�� ���� ���.
		IDXGISwapChain* SwapChain;				// DXGI(DirectX Graphics Infrastructure): Ŀ�� ���� ȣȯ���� ��� �����ϴ� ����(�׷��� ī�忡 ���� �ڵ� �νĹ���� �ٸ��Ƿ�).
												// SwapChain: ����ڿ��� �������� ǥ���ϴ� �� ���Ǵ� ������ �÷���.
	}


	// CALLBACK == __stdcall(��ũ�� ���).
	// Procedure(): ������ ���ν��� �Լ�(������ WndProc��� �̸� ����).
	LRESULT CALLBACK Procedure(HWND const hWnd,			// �޼����� ó���� ������ �ڵ�.
		UINT const uMessage,							// ���޵� �޼���.
		WPARAM const wParam,							// �޼����� ���� �߰� ����(wParam).
		LPARAM const lParam)							// �޼����� ���� �߰� ����(lParam).
	{
		switch (uMessage)
		{
		// ó�� â�� ������ �� �� ���� ȣ��Ǵ� �޼���.
		case WM_CREATE:
		{
			// �Ʒ��� ��ɾ� �ϳ���, Device, Device context, Swap chain�� �ѹ��� ��� ���� ������.
			DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC();	// �⺻������ �����ϱ� ���� ����Ʈ ������ ȣ���Ͽ� ��ü ����.
			//D3D11CreateDeviceAndSwapChain();

			return 0;
		}

		// â�� ����� ����� �� ȣ��Ǵ� �޼���.
		case WM_SIZE:
			return 0;

		// ����� ���� �޼���.
		case WM_APP:
			return 0;

		// ���� ����� ���� ��ư�� �����ų� Alt + F4 �Է� �� �����쿡�� �߻��ϴ� �޼���.
		case WM_DESTROY:
		{
			Device->Release();			// Release�� ���� ����.
			DeviceContext->Release();	// Release�� ���� ����.
			SwapChain->Release();		// Release�� ���� ����.
			PostQuitMessage(0);			// PostQuitMessage(): �޽��� ť�� WM_QUIT �޼����� ����Ʈ�ϴ� �Լ�.
			return 0;
		}

		// ��� �з����� ���� �޼������� ����Ʈ�� ó��.
		default:
		{ return DefWindowProc(hWnd, uMessage, wParam, lParam); }	// DefWindowProc(): �޼����� ����Ʈ�� ó���ϴ� �Լ�.
		}

	}
}