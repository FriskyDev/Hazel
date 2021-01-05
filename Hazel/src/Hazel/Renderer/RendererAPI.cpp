#include "hzpch.h"
#include "Hazel/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"
#ifdef HZ_PLATFORM_WINDOWS
#include "Platform/DirectX/DirectXRendererAPI.h"
#endif

namespace Hazel {

#ifdef DIRECTX_AVAILABLE
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::DirectX;
#else
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
#endif

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
#ifdef DIRECTX_AVAILABLE
			case RendererAPI::API::DirectX: return CreateScope<DirectXRendererAPI>();
#endif
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}