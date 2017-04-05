#include "StdAfx.h"
#include "d3d11.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
}

IndexBuffer::~IndexBuffer()
{
}

bool IndexBuffer::Initialize(ID3D11Device* device, void* buffer, unsigned int bufferSize)
{
    mD3DDevice = device;

    D3D11_BUFFER_DESC bufferDesc;
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = bufferSize;
    bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = buffer;
    initData.SysMemPitch = 0;
    initData.SysMemSlicePitch = 0;

    return false;
}