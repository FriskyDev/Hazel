#include "hzpch.h"

#ifdef HZ_PLATFORM_WINDOWS
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include "Hazel/Core/Application.h"

#include "Platform/DirectX/DirectXRendererAPI.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Hazel {
	
	void DirectXMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		//switch (severity)
		//{
		//	case GL_DEBUG_SEVERITY_HIGH:         HZ_CORE_CRITICAL(message); return;
		//	case GL_DEBUG_SEVERITY_MEDIUM:       HZ_CORE_ERROR(message); return;
		//	case GL_DEBUG_SEVERITY_LOW:          HZ_CORE_WARN(message); return;
		//	case GL_DEBUG_SEVERITY_NOTIFICATION: HZ_CORE_TRACE(message); return;
		//}
		
		HZ_CORE_ASSERT(false, "Unknown severity level!");
	}

	void DirectXRendererAPI::Init()
	{
		HZ_PROFILE_FUNCTION();

		UINT flags{};
	#ifdef HZ_DEBUG
		//glEnable(GL_DEBUG_OUTPUT);
		//glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		//glDebugMessageCallback(DirectXMessageCallback, nullptr);
		//
		//glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
		flags = D3D11_CREATE_DEVICE_DEBUG;
	#endif

		auto window = dynamic_cast<WindowsWindow*>(Application::Get().GetWindow());
		HZ_ASSERT(window, "Invalid WindowsWindow");

		// describe our swapchain buffer
		DXGI_MODE_DESC bufferDesc{};
		bufferDesc.Width = window->GetWidth();
		bufferDesc.Height = window->GetHeight();
		bufferDesc.RefreshRate.Numerator = 60;
		bufferDesc.RefreshRate.Denominator = 1;
		bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		auto glfwWindow = static_cast<GLFWwindow*>(window->GetNativeWindow());

		// describe our swapchain
		DXGI_SWAP_CHAIN_DESC swapChainDesc{};
		swapChainDesc.BufferDesc = bufferDesc;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 1;
		swapChainDesc.OutputWindow = glfwGetWin32Window(glfwWindow);
		swapChainDesc.Windowed = TRUE;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		// create our swapchain
		HRESULT hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, nullptr, 0, D3D11_SDK_VERSION, &swapChainDesc, &m_SwapChain, &m_D3DDevice, nullptr, &m_D3DContext);

		// create our backBuffer
		ID3D11Texture2D* backBuffer;
		hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);

		// create our Render Target
		hr = m_D3DDevice->CreateRenderTargetView(backBuffer, nullptr, &m_RenderTargetView);
		backBuffer->Release();

		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//glEnable(GL_DEPTH_TEST);
	}

	void DirectXRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		//glViewport(x, y, width, height);
	}

	void DirectXRendererAPI::SetClearColor(const glm::vec4& color)
	{
		//glClearColor(color.r, color.g, color.b, color.a);
	}

	void DirectXRendererAPI::Clear()
	{
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void DirectXRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount)
	{
		//uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
		//glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		//glBindTexture(GL_TEXTURE_2D, 0);
	}

}

#endif
