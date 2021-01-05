#include "hzpch.h"
#ifdef HZ_PLATFORM_WINDOWS
#include "Platform/DirectX/DirectXContext.h"


#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#pragma comment(lib, "d3d11.lib")


namespace Hazel {

	DirectXContext::DirectXContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void DirectXContext::Init()
	{
		HZ_PROFILE_FUNCTION();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		HZ_CORE_INFO("DirectX Info:");
		HWND m_hwnd = glfwGetWin32Window(m_WindowHandle);
	}

	void DirectXContext::SwapBuffers()
	{
		HZ_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}

#endif
