#include "Credits.h"

unsigned int Credits::sRunTimeTypeId = (unsigned int)&Credits::sRunTimeTypeId;

void Credits::Draw(const GameTime& gameTime)
{
    mSpriteBatch->Begin();

    std::wostringstream CreditsDraw;

    if (GetActiveState() == true)
    { 
        CreditsDraw << L"Team Manager - Logun Tetley" << "\n";
        CreditsDraw << L"Assets manager - Carmen-Michelle Ienachi" << "\n";
        CreditsDraw << L"Programmer - Reece Kassiram-Brennan" << "\n";
        CreditsDraw << L"Designer - Jan Mark Callata Bradaschii Grecco" << "\n";
        CreditsDraw << L"Designer - Ayran Thane Olckers" << "\n";
        CreditsDraw << L"Qa - Jakob Asgaard" << "\n";

    mSpriteFont->DrawString(mSpriteBatch, CreditsDraw.str().c_str(), XMFLOAT2(0, 0));

    mSpriteBatch->End();
}

void Credits::Initialize()
{
    mSpriteBatch = new SpriteBatch(mGame->Direct3DDeviceContext());
    mSpriteFont = new SpriteFont(mGame->Direct3DDevice(), L"Content\\Fonts\\Arial_14_Regular.spritefont");
    SetupKeyboard();
}

bool Credits::GetActiveState() { return ActiveState; }

void Credits::SetActiveState(bool State) { ActiveState = State; }

void Credits::SetupKeyboard()
{
    mKeyboard = (Keyboard*)mGame->Services().GetService(Keyboard::TypeIdClass());
    assert(mKeyboard != nullptr);
}

void Credits::Update(const GameTime& gameTime)
{
    if (mKeyboard != nullptr)
        SetActiveState(mKeyboard->IsKeyDown(DIK_C));
}


