#pragma once

#include "hzpch.h"
#ifdef HZ_PLATFORM_WINDOWS

#include "Hazel/Renderer/RendererAPI.h"

#include <d3d11.h>

namespace Hazel {

	class DirectXRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) override;

	private:
		ID3D11DeviceContext* m_D3DContext{};
 		ID3D11Device* m_D3DDevice{};
		IDXGISwapChain* m_SwapChain{};
		ID3D11RenderTargetView* m_RenderTargetView{};
	};
}

#endif