#include "hzpch.h"

#include "Platform/DirectX/DirectXBuffer.h"

#include <d3d11.h>

namespace Hazel {

	/////////////////////////////////////////////////////////////////////////////
	// VertexBuffer /////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////

	DirectXVertexBuffer::DirectXVertexBuffer(uint32_t size)
	{
		HZ_PROFILE_FUNCTION();

		// Fill in a buffer description.
		D3D11_BUFFER_DESC bufferDesc;
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = size;
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		// Fill in the subresource data.
		D3D11_SUBRESOURCE_DATA initData;
		initData.pSysMem = nullptr;
		initData.SysMemPitch = 0;
		initData.SysMemSlicePitch = 0;

		// Create the vertex buffer.
		//D3D11_BUFFER_DESC pDesc{};
		//D3D11_SUBRESOURCE_DATA pInitialData = nullptr;
		//ID3D11Buffer* pBuffer;
		//HRESULT hr = m_D3DDevice->CreateBuffer(&pDesc, pInitialData, &pBuffer);
		//HRESULT hr = m_D3DDevice->CreateBuffer(uint32_t size);
		throw std::runtime_error("DirectXVertexBuffer(float* vertices, uint32_t size)");
	}

	DirectXVertexBuffer::DirectXVertexBuffer(float* vertices, uint32_t size)
	{
		HZ_PROFILE_FUNCTION();

		//glCreateBuffers(1, &m_RendererID);
		//glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		//glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		throw std::runtime_error("DirectXVertexBuffer(float* vertices, uint32_t size)");
	}

	DirectXVertexBuffer::~DirectXVertexBuffer()
	{
		HZ_PROFILE_FUNCTION();

		if (m_pVertexBuffer != nullptr) {
			m_pVertexBuffer->Release();
			m_pVertexBuffer = nullptr;
		}
	}

	void DirectXVertexBuffer::Bind() const
	{
		HZ_PROFILE_FUNCTION();

		//glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		throw std::runtime_error("DirectXVertexBuffer::Bind()");

	}

	void DirectXVertexBuffer::Unbind() const
	{
		HZ_PROFILE_FUNCTION();

		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		throw std::runtime_error("DirectXVertexBuffer::Unbind()");
	}

	void DirectXVertexBuffer::SetData(const void* data, uint32_t size)
	{
		//glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		//glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
		throw std::runtime_error("DirectXVertexBuffer::SetData(const void* data, uint32_t size)");
	}

	/////////////////////////////////////////////////////////////////////////////
	// IndexBuffer //////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////

	DirectXIndexBuffer::DirectXIndexBuffer(uint32_t* indices, uint32_t count)
		: m_Count(count)
	{
		HZ_PROFILE_FUNCTION();

		//glCreateBuffers(1, &m_RendererID);
		//
		//// GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
		//// Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state. 
		//glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		//glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
		throw std::runtime_error("DirectXIndexBuffer::DirectXIndexBuffer(uint32_t* indices, uint32_t count)");
	}

	DirectXIndexBuffer::~DirectXIndexBuffer()
	{
		HZ_PROFILE_FUNCTION();

		if (m_pVertexBuffer != nullptr) {
			m_pVertexBuffer->Release();
			m_pVertexBuffer = nullptr;
		}
	}

	void DirectXIndexBuffer::Bind() const
	{
		HZ_PROFILE_FUNCTION();

		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		throw std::runtime_error("irectXIndexBuffer::Bind() const");

	}

	void DirectXIndexBuffer::Unbind() const
	{
		HZ_PROFILE_FUNCTION();

		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		throw std::runtime_error("DirectXIndexBuffer::Unbind() const");

	}

}
