#pragma once

#include "hzpch.h"
#include "Hazel/Renderer/Buffer.h"

#include <cstdint>

#include <d3d11.h>

namespace Hazel {

	class DirectXVertexBuffer : public VertexBuffer
	{
	public:
		DirectXVertexBuffer(uint32_t size);
		DirectXVertexBuffer(float* vertices, uint32_t size);
		virtual ~DirectXVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		
		virtual void SetData(const void* data, uint32_t size) override;

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
	private:
		ID3D11Buffer* m_pVertexBuffer = nullptr;
		BufferLayout m_Layout;
	};

	class DirectXIndexBuffer : public IndexBuffer
	{
	public:
		DirectXIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~DirectXIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual uint32_t GetCount() const { return m_Count; }
	private:
		ID3D11Buffer* m_pVertexBuffer = nullptr;
		uint32_t m_Count;
	};

}