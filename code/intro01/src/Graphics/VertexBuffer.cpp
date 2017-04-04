#include "StdAfx.h"

#include "d3d11.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer() :
    mD3DDevice(nullptr),
    mVertexBuffer(nullptr)
{
}

VertexBuffer::~VertexBuffer()
{
}

bool VertexBuffer::Initialize(ID3D11Device* device, void* buffer, unsigned int bufferSize)
{
    mD3DDevice = device;

    D3D11_BUFFER_DESC bufferDesc;
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = bufferSize;
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = buffer;
    initData.SysMemPitch = 0;
    initData.SysMemSlicePitch = 0;

    return SUCCEEDED(mD3DDevice->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer));
}