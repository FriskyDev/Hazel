#include "hzpch.h"
#include "Hazel/Renderer/GraphicsContext.h"

#include "Hazel/Renderer/Renderer.h"
#ifdef DIRECTX_AVAILABLE
#include "Platform/DirectX/DirectXContext.h"
#endif
#include "Platform/OpenGL/OpenGLContext.h"

namespace Hazel {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
#ifdef DIRECTX_AVAILABLE
			case RendererAPI::API::DirectX: return CreateScope<DirectXContext>(static_cast<GLFWwindow*>(window));
#endif
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}