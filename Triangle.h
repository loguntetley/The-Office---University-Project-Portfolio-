#pragma once

#include "DrawableGameComponent.h"

using namespace Library;

namespace Rendering
{
    class Triangle : public DrawableGameComponent
    {
        RTTI_DECLARATIONS(Triangle, DrawableGameComponent)

    public:
        TriangleDemo(Game& game, Camera& camera);
        ~Triangle();

        virtual void Initialize() override;
        virtual void Update(const GameTime& gameTime) override;
		virtual void Draw(const GameTime& gameTime) override;

    private:
        typedef struct _BasicEffectVertex
        {
            XMFLOAT4 Position;
            XMFLOAT4 Color;

            _BasicEffectVertex() { }

            _BasicEffectVertex(XMFLOAT4 position, XMFLOAT4 color)
                : Position(position), Color(color) { }
        } BasicEffectVertex;

        Triangle();
        Triangle(const Triangle& rhs);
        Triangle& operator=(const Triangle& rhs);

        ID3DX11Effect* mEffect;
        ID3DX11EffectTechnique* mTechnique;
        ID3DX11EffectPass* mPass;
        ID3DX11EffectMatrixVariable* mWvpVariable;

        ID3D11InputLayout* mInputLayout;		
        ID3D11Buffer* mVertexBuffer;

        XMFLOAT4X4 mWorldMatrix;
		float mAngle;
    };
}
