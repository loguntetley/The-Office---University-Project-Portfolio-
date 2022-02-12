#include "ShadowMappingDemo.h"
#include "Game.h"
#include "GameException.h"
#include "VectorHelper.h"
#include "MatrixHelper.h"
#include "ColorHelper.h"
#include "Camera.h"
#include "Model.h"
#include "Mesh.h"
#include "Utility.h"
#include "PointLight.h"
#include "Keyboard.h"
#include <WICTextureLoader.h>
#include "Projector.h"
#include "RenderableFrustum.h"
#include "ShadowMappingMaterial.h"
#include "DepthMapMaterial.h"
#include "DepthMap.h"
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <sstream>
#include <iomanip>
#include <DirectXCollision.h>
#include <DirectXMath.h>

namespace DirectX
{
	class SpriteBatch;
	class SpriteFont;
}

#pragma once
class Credits: public DrawableGameComponent
{
	RTTI_DECLARATIONS(Credits, DrawableGameComponent)

public:
	virtual void Draw(const GameTime& gameTime) override;
	virtual void Initialize() override;

	Credits::Credits(Game* pInstance) : DrawableGameComponent(*pInstance)
	{
		ActiveState = false;
	}

private:

	Credits* Instance;
	bool ActiveState;
	Keyboard* mKeyboard;
	SpriteBatch* mSpriteBatch;
	SpriteFont* mSpriteFont;

	bool Credits::GetActiveState();

	void Credits::SetActiveState(bool State);

	void Credits::SetupKeyboard();

	virtual void Update(const GameTime& gameTime) override;

	const Keyboard& Credits::GetKeyboard() const
	{
		return *mKeyboard;
	}

	void Credits::SetKeyboard(Keyboard& keyboard)
	{
		mKeyboard = &keyboard;
	}
};


