#include "StdAfx.h"
#include "Mesh.h"

#include <d3d11.h>

Mesh::Mesh()
{
    mRawVertexData = nullptr;
    mIndexBufferData = nullptr;
}

Mesh::~Mesh()
{
    delete[] mRawVertexData;
    mRawVertexData = nullptr;
    delete[] mIndexBufferData;
    mIndexBuffer = nullptr;
}

bool Mesh::Load(PositionNormalUVLayout* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount)
{
    mRawVertexData = vertices;
    mIndexBufferData = indices;

    D3D11_BUFFER_DESC vertexBufferDesc;
    D3D11_SUBRESOURCE_DATA resourceData;

    ZeroMemory(&vertexBufferDesc, sizeof(D3D11_BUFFER_DESC));
    ZeroMemory(&resourceData, sizeof(D3D11_SUBRESOURCE_DATA));

    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.ByteWidth = sizeof(PositionNormalUVLayout) * vertexCount;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

    resourceData.pSysMem = vertices;
    return false;
}